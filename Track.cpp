#include "Track.h"

// Constructor
Track::Track(const std::string& name, const std::string& location, int turns, int straights)
    : name(name), location(location), turns(turns), straights(straights) {}

std::string Track::getName() const {
    return name;
}

std::string Track::getLocation() const{
    return location;
}

int Track::getTurns() const{
    return turns;
}

int Track::getStraights() const{
    return straights;
}

// Initialize specific tracks, constructs object inside container
std::vector<Track> intitializeTracks() {
    std::vector<Track> tracks;
    tracks.emplace_back("Silverstone", "UK", 18, 6);
    tracks.emplace_back("Monza", "Italy", 11, 4);
    tracks.emplace_back("Spa-Francorchamps", "Belgium", 19, 10);
    tracks.emplace_back("Suzuka", "Japan", 18, 5);
    tracks.emplace_back("Monaco", "Monaco", 19, 3);
    return tracks;
}