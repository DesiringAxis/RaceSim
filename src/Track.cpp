#include "Track.h"

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
    tracks.emplace_back("Silverstone", "UK", 52, 18, 6, 90.275f);
    tracks.emplace_back("Monza", "Italy", 53, 11, 4, 84.030f);
    tracks.emplace_back("Spa-Francorchamps", "Belgium", 44, 19, 10, 107.305f);
    tracks.emplace_back("Suzuka", "Japan", 53, 18, 5, 93.706f);
    tracks.emplace_back("Monaco", "Monaco", 78, 19, 3, 74.693f);
    return tracks;
}