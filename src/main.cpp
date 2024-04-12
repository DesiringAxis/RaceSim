#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>
#include "Track.h"
#include "Driver.h"

extern std::vector<Track> initializeTracks();
extern std::vector<Driver> initializeDrivers();

int main() {
    auto tracks = initializeTracks();
    auto drivers = initializeDrivers();

    std::cout << "Select a track:\n";
    for (int i = 0; i < tracks.size(); ++i) {
        std::cout << i + 1 << ". " << tracks[i].getName() << "\n";
    }

    int trackChoice;
    std::cin >> trackChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Important to clear the buffer

    if (trackChoice < 1 || trackChoice > static_cast<int>(tracks.size())) {
        std::cout << "Invalid track selection. Please try again.\n";
        return -1;
    }

    Track selectedTrack = tracks[trackChoice - 1];

   // Assuming startingGrid is meant to order drivers based on user input
    std::vector<Driver> startingGrid;
    std::cout << "Enter the number for drivers in the starting grid order: \n";
    for (int i = 0; i < drivers.size(); ++i) {
        int driverNumber;
        std::cout << "Driver " << i + 1 << ": ";
        std::cin >> driverNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer after input

        // Validate input
        if (driverNumber < 1 || driverNumber > static_cast<int>(drivers.size())) {
            std::cout << "Invalid driver number. Please try again.\n";
            --i; // Decrement to repeat the loop for correct input
            continue;
        }

        // Add the selected driver to the starting grid
        startingGrid.push_back(drivers[driverNumber - 1]);
    }

    std::vector<std::pair<std::string, float>> driverTimes; // Pair of driver name and total race time, including starting advantage
    float sumLapTimes = 0;
    float averageLapTime;
    float minLapTime = std::numeric_limits<float>::max();
    float trackFastestLap = selectedTrack.getFastestLap();
    unsigned int totalLaps = selectedTrack.getLaps();

    for (auto& driver : drivers) {
        float baseLapTime = trackFastestLap;
        // Adding time based on driver and car attributes for the first lap
        baseLapTime += baseLapTime * selectedTrack.getTurns() * (1 - (driver.getHandling() * driver.getCar()->getHandling() / 100.0));
        baseLapTime += baseLapTime * selectedTrack.getStraights() * (1 - (driver.getSpeed() * driver.getCar()->getSpeed() / 100.0));
        float totalRaceTime = baseLapTime; // First lap time
        
        // Calculating lap times for remaining laps, affected by stamina
        for (unsigned int lap = 2; lap <= totalLaps; ++lap) {
            // Each subsequent lap increases at a rate that decreases with stamina
            float lapTimeDecreaseFactor = exp(-0.1 * (driver.getStamina() / 10.0) * (lap - 1));
            float lapTime = baseLapTime * (1 + (0.05 * (lap - 1)) * lapTimeDecreaseFactor);
            totalRaceTime += lapTime;
        
        // Tracking the fastest lap and sum of all lap times for later calculations
            if (lapTime < minLapTime) {
                minLapTime = lapTime;
            }
            sumLapTimes += lapTime;
        }

        driverTimes.emplace_back(driver.getName(), totalRaceTime);
    }

    // Sort and display the race results
    std::sort(driverTimes.begin(), driverTimes.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::cout << "\nFinishing Order:\n";
    for (auto& [name, time] : driverTimes) {
        std::cout << name << " - Total Race Time: " << time << " seconds\n";
    }

    // Calculate and print average lap time
    averageLapTime = sumLapTimes / (drivers.size() * totalLaps);
    std::cout << "\nAverage lap time: " << averageLapTime << " seconds\n";
    std::cout << "Fastest lap time: " << minLapTime << " seconds\n";

    return 0;
}