#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <vector>

class Track {
private:
    //Track information
    std::string name; 
    std::string location; 
    unsigned int laps; 
    int turns; 
    int straights; 
    float fastestLap; 

public:
  //Track rating
  virtual double getTrackRating() const {
        return static_cast<double>(turns + straights) / laps;
    }
    // Initialize track with name, location, # of turns, # of straights
    Track(const std::string& name, const std::string& location, unsigned int laps, int turns, int straights, float fastestLap);
    std::string getName() const;
    std::string getLocation() const;
    unsigned int getLaps() const;
    int getTurns() const;
    int getStraights() const;
    float getFastestLap() const;
    // Compare tracks based on fastest lap time
    bool operator<(const Track& other) const {
      return this->fastestLap < other.fastestLap;
    }

};

std::vector<Track> intitializeTracks();

#endif // TRACK_H
