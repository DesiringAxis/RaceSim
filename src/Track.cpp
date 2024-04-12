#include "Track.h"
#include <vector>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

// Constructor
Track::Track(const std::string& name, const std::string& location, unsigned int laps, int turns, int straights, float fastestLap)
    : name(name), location(location), laps(laps), turns(turns), straights(straights), fastestLap(fastestLap) {}

//Returns Track info
std::string Track::getName() const {
    return name;
}

std::string Track::getLocation() const{
    return location;
}

unsigned int Track::getLaps() const {
    return laps;
}

int Track::getTurns() const{
    return turns;
}

int Track::getStraights() const{
    return straights;
}

float Track::getFastestLap() const{
    return fastestLap;
}

// Initialize specific tracks, constructs object inside container
std::vector<Track> initializeTracks() {
    std::vector<Track> tracks;
    std::regex namePattern("^[A-Za-z\\s-]+$");
    std::vector<std::string> trackNames = {"Silverstone", "Monza", "Spa-Francorchamps", "Suzuka", "Monaco"};

    for (const auto& name : trackNames) {
        if (std::regex_match(name, namePattern)) {
            // Only add the track if the name matches the pattern
            if (name == "Silverstone") {
                tracks.emplace_back(name, "UK", 52, 18, 6, 90.275f);
            } else if (name == "Monza") {
                tracks.emplace_back(name, "Italy", 53, 11, 4, 84.030f);
            } else if (name == "Spa-Francorchamps") {
                tracks.emplace_back(name, "Belgium", 44, 19, 10, 107.305f);
            } else if (name == "Suzuka") {
                tracks.emplace_back(name, "Japan", 53, 18, 5, 93.706f);
            } else if (name == "Monaco") {
                tracks.emplace_back(name, "Monaco", 78, 19, 3, 74.693f);
            }
         }else {
            cout << "Invalid track name detected: " << name << endl;
        }
    }
    return tracks; // Added return statement
}