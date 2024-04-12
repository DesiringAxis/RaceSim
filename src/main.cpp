#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>
#include <numeric>
#include "Track.h"
#include "Driver.h"

extern std::vector<Track> initializeTracks();
extern std::vector<Driver> initializeDrivers();

void convertTime(float totalTimeInSeconds, int& minutes, int& seconds, int& milliseconds) {
    minutes = static_cast<int>(totalTimeInSeconds) / 60;
    seconds = static_cast<int>(totalTimeInSeconds) % 60;
    milliseconds = static_cast<int>((totalTimeInSeconds - static_cast<int>(totalTimeInSeconds)) * 1000);
}

int main() {
    auto tracks = initializeTracks();
    auto drivers = initializeDrivers();

    std::cout << "Select a track:\n";
    for (int i = 0; i < tracks.size(); ++i) {
        std::cout << i + 1 << ". " << tracks[i].getName() << "\n";
    }

    int trackChoice;
    std::cin >> trackChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (trackChoice < 1 || trackChoice > static_cast<int>(tracks.size())) {
        std::cout << "Invalid track selection. Please try again.\n";
        return -1;
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
            --i;
        }
    }

    std::vector<std::pair<std::string, std::pair<float, std::vector<float>>>> driverTimes;

    for (auto& driver : startingGrid) {
        float totalRaceTime = 0;
        std::vector<float> lapTimes;

        for (unsigned int lap = 1; lap <= selectedTrack.getLaps(); ++lap) {
            float baseLapTime = selectedTrack.getFastestLap();
            baseLapTime *= 1 + (0.01 * selectedTrack.getTurns() * (1 - (driver.getHandling() + driver.getCar()->getHandling()) / 200.0));
            baseLapTime *= 1 + (0.01 * selectedTrack.getStraights() * (1 - (driver.getSpeed() + driver.getCar()->getSpeed()) / 200.0));

            float lapTimeDecreaseFactor = exp(-0.1 * (driver.getStamina() / 10.0) * (lap - 1));
            float lapTime = baseLapTime * (1 + (0.05 * (lap - 1)) * lapTimeDecreaseFactor);

            totalRaceTime += lapTime;
            lapTimes.push_back(lapTime);
        }

        driverTimes.emplace_back(driver.getName(), std::make_pair(totalRaceTime, lapTimes));
    }

    std::sort(driverTimes.begin(), driverTimes.end(), [](const auto& a, const auto& b) {
        return a.second.first < b.second.first;
    });

    std::cout << "\nFinishing Order:\n";
    for (auto& [name, times] : driverTimes) {
        int minutes, seconds, milliseconds;
        convertTime(times.first, minutes, seconds, milliseconds);
        printf("%s - Total Race Time: %d:%02d:%03d\n", name.c_str(), minutes, seconds, milliseconds);

        auto& lapTimes = times.second;
        float fastestLap = *std::min_element(lapTimes.begin(), lapTimes.end());
        float averageLapTime = std::accumulate(lapTimes.begin(), lapTimes.end(), 0.0f) / lapTimes.size();

        convertTime(fastestLap, minutes, seconds, milliseconds);
        printf("    Fastest Lap: %d:%02d:%03d\n", minutes, seconds, milliseconds);

        convertTime(averageLapTime, minutes, seconds, milliseconds);
        printf("    Average Lap: %d:%02d:%03d\n", minutes, seconds, milliseconds);
    }

    return 0;
}