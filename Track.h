//Hold all track information
#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <vector>

class Track {
private:
    std::string name;       // Track name
    std::string location;   // Track location
    int turns;              // Number of turns
    int straights;          // Number of straights

public:
    // Initialize track with name, location, # of turns, # of straights
    Track(const std::string& name, const std::string& location, int turns, int straights);

    std::string getName() const; // Gets track name
    std::string getLocation() const; // Gets track location
    int getTurns() const; // Gets number of turns
    int getStraights() const; // Gets number of straights

};

// Initialization to retrieve tracks
std::vector<Track> intitializeTracks();

#endif // TRACK_H
