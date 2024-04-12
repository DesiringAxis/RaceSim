//Hold all track information
#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <vector>

class Track {
private:
    std::string name; // Track name
    std::string location; // Track location
    unsigned int laps; //Number of laps
    int turns; // Number of turns
    int straights; // Number of straights
    float fastestLap; //Fastest Lap time done with this generation of F1 car

public:
  virtual double getTrackRating() const {
        return static_cast<double>(turns + straights) / laps;
    }
    // Initialize track with name, location, # of turns, # of straights
    Track(const std::string& name, const std::string& location, unsigned int laps, int turns, int straights, float fastestLap);
    //Getters
    std::string getName() const;
    std::string getLocation() const;
    unsigned int getLaps() const;
    int getTurns() const;
    int getStraights() const;
    float getFastestLap() const;

    bool operator<(const Track& other) const {
      return this->fastestLap < other.fastestLap;
    }


};

  // Initialization to retrieve tracks
std::vector<Track> intitializeTracks();

#endif // TRACK_H
