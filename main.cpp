#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>
#include "Track.h"
#include "Driver.h"

// Initialize Track, Driver, and associated car info
extern std::vector<Track> initializeTracks();
extern std::vector<Driver> initializeDrivers();

int main() {
    auto tracks = initializeTracks();
    auto drivers = initializeDrivers();

    // Display tracks and let the user select one
    std::cout << "Select a track:\n";
    for (int i = 0; i < tracks.size(); ++i) {
        std::cout << i + 1 << ". " << tracks[i].getName() << "\n";
    }
    int trackChoice;
    std::cin >> trackChoice;
    Track selectedTrack = tracks[trackChoice - 1];

    // Ask user to specify the starting grid order
    std::cout << "Enter the starting grid order by driver name, one per line:\n";
    std::vector<std::string> startingGridOrder;
    std::string driverName;
    for (int i = 0; i < 6; ++i) { // Assuming 6 drivers
        std::cin >> driverName;
        startingGridOrder.push_back(driverName);
    }

    // Map to hold driver names and their starting position advantages
    std::map<std::string, float> startingAdvantages;
    for (int i = 0; i < startingGridOrder.size(); ++i) {
        // Each subsequent driver gets a 1-second disadvantage
        startingAdvantages[startingGridOrder[i]] = -static_cast<float>(i);
    }

    std::vector<std::pair<std::string, float>> driverTimes; // Pair of driver name and total race time, including starting advantage
    float sumLapTimes = 0;
    float averageLapTime;
    float minLapTime = std::numeric_limits<float>::max();

    for (auto& driver : drivers) {
        Car* car = driver.getCar();
        float speed = driver.getSpeed();
        float handling = driver.getHandling();
        float stamina = driver.getStamina(); // Assuming the third skill is stamina
        float fastestLap = selectedTrack.getFastestLap(); // Reset fastestLap for each driver
        
        // Calculate time added for both turns and straights, adjusted by starting advantage
        fastestLap += selectedTrack.getTurns() * fastestLap * 
                      (1 - (driver.getSpeed() * car->getAcceleration() * (car->getHandling() * car->getHandling()) / 10000));
        fastestLap += selectedTrack.getStraights() * fastestLap * 
                      (1 - (driver.getHandling() * car->getSpeed() * (car->getSpeed() * car->getSpeed()) / 10000));
        
        // Calculate total race time with exponential decay based on stamina, including starting advantage
        float driverTotalTime = startingAdvantages[driver.getName()]; // Include starting advantage
        for(unsigned int lap = 1; lap <= selectedTrack.getLaps(); ++lap) {
            float lapTime = fastestLap * exp(-stamina * lap);
            driverTotalTime += lapTime;
            sumLapTimes += lapTime;
            if (lapTime < minLapTime) {
                minLapTime = lapTime; // Update fastest lap across all drivers
            }
        }

        driverTimes.emplace_back(driver.getName(), driverTotalTime); // Store each driver's total race time
    }

    // Sort drivers by their total race time
    std::sort(driverTimes.begin(), driverTimes.end(), [](const std::pair<std::string, float>& a, const std::pair<std::string, float>& b) {
        return a.second < b.second;
    });

    // Print finishing grid order
    std::cout << "\nFinishing Order:\n";
    for (const auto& driver : driverTimes) {
        std::cout << driver.first << " - Total Race Time: " << driver.second << " seconds\n";
    }

    // Calculate and print average lap time
    averageLapTime = sumLapTimes / (drivers.size() * selectedTrack.getLaps());
    std::cout << "\nAverage lap time: " << averageLapTime << " seconds\n";
    std::cout << "Fastest lap time: " << minLapTime << " seconds\n";

    return 0;
}