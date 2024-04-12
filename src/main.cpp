#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>
#include <numeric>
#include <sstream>
#include <iomanip>
#include "Track.h"
#include "Driver.h"

extern std::vector<Track> initializeTracks();
extern std::vector<Driver> initializeDrivers();

void convertTime(double totalTimeInSeconds, int& minutes, int& seconds, int& milliseconds) {
    minutes = static_cast<int>(totalTimeInSeconds) / 60;
    seconds = static_cast<int>(totalTimeInSeconds) % 60;
    milliseconds = static_cast<int>((totalTimeInSeconds - static_cast<int>(totalTimeInSeconds)) * 1000);
}

// Overloaded function
std::string convertTime(double totalTimeInSeconds) {
    int minutes, seconds, milliseconds;
    convertTime(totalTimeInSeconds, minutes, seconds, milliseconds);
    
    std::ostringstream oss;
    oss << std::setfill('0') << minutes << ":" << std::setw(2) << seconds << ":" << std::setw(3) << milliseconds;
    return oss.str();
}

int main() {
    double Var = 0.0;
    static int Static = 0;
    auto tracks = initializeTracks();
    auto drivers = initializeDrivers();

    int trackChoice = 0;
    bool validTrack = false;

    while (!validTrack) {
        std::cout << "Select a track:\n";
        for (int i = 0; i < tracks.size(); ++i) {
            std::cout << i + 1 << ". " << tracks[i].getName() << "\n";
        }

        std::cin >> trackChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (trackChoice < 1 || trackChoice > static_cast<int>(tracks.size())) {
            std::cout << "Invalid number. Please enter a valid pre-assigned number.\n";
        } else {
            validTrack = true;
        }
    }

    Track selectedTrack = tracks[trackChoice - 1];

    std::cout << "Enter the number for drivers in the starting grid order:\n";
    for (const auto& driver : drivers) {
        std::cout << driver.getNumber() << ". " << driver.getName() << "\n";
    }

    std::vector<Driver> startingGrid;
    for (size_t i = 0; i < drivers.size(); ++i) {
        std::cout << "Enter the pre-assigned number for position " << (i + 1) << " in the grid: ";
        int driverNumber;
        std::cin >> driverNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        auto it = std::find_if(drivers.begin(), drivers.end(), [driverNumber](const Driver& d) {
            return d.getNumber() == driverNumber;
        });

        if (it != drivers.end()) {
            startingGrid.push_back(*it);
        } else {
            std::cout << "Invalid number. Please enter a valid pre-assigned number.\n";
            --i; // Decrease counter to retry the same position
        }
    }

    std::vector<std::pair<std::string, std::pair<double, std::vector<double>>>> driverTimes;

    for (auto& driver : startingGrid) {
        double totalRaceTime = 0;
        std::vector<double> lapTimes;

        for (unsigned int lap = 1; lap <= selectedTrack.getLaps(); ++lap) {
            double baseLapTime = static_cast<double>(selectedTrack.getFastestLap());
            baseLapTime *= 1 + (0.01 * selectedTrack.getTurns() * (1 - (driver.getHandling() + driver.getCar()->getHandling()) / 200.0));
            baseLapTime *= 1 + (0.01 * selectedTrack.getStraights() * (1 - (driver.getSpeed() + driver.getCar()->getSpeed()) / 200.0));

            double lapTimeDecreaseFactor = exp(-0.1 * (driver.getStamina() / 10.0) * (lap - 1));
            double lapTime = baseLapTime * (1 + (0.05 * (lap - 1)) * lapTimeDecreaseFactor);

            totalRaceTime += lapTime;
            lapTimes.push_back(lapTime);
        }

        driverTimes.emplace_back(driver.getName(), std::make_pair(totalRaceTime, lapTimes));
    }

    std::sort(driverTimes.begin(), driverTimes.end(), [](const auto& a, const auto& b) {
        return a.second.first < b.second.first;
    });
    
    char showDetails;
    std::cout << "Do you want to see detailed lap times for each driver? (Y/N): ";
    std::cin >> showDetails;

    std::cout << "\nFinishing Order:\n";
    for (auto& [name, nestedPair] : driverTimes) {
        // Display total race time
        std::cout << name << " - Total Race Time: " << convertTime(nestedPair.first) << "\n";

        // Check if detailed lap times are requested
        if (showDetails == 'Y' || showDetails == 'y') {
            std::cout << "Detailed Lap Times for " << name << ":\n";
            for (size_t i = 0; i < nestedPair.second.size(); ++i) {
                std::string formattedLapTime = convertTime(nestedPair.second[i]);
                std::cout << "Lap " << (i + 1) << ": " << formattedLapTime << "\n";
            }
        }

        // Calculating and displaying fastest and average lap times
        double fastestLap = *std::min_element(nestedPair.second.begin(), nestedPair.second.end());
        std::cout << "Fastest Lap: " << convertTime(fastestLap) << "\n";

        double totalLapTime = std::accumulate(nestedPair.second.begin(), nestedPair.second.end(), 0.0);
        double averageLapTime = totalLapTime / nestedPair.second.size();
        std::cout << "Average Lap: " << convertTime(averageLapTime) << "\n";
    }
    return 0;
}