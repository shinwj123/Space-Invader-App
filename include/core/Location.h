#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_LOCATION_H
#define FINAL_PROJECT_SHINWJ123_LOCATION_H

namespace space_invader_game {

class Location {
public:
    Location(int row, int col);

    int row() const;
    int col() const;

    //+= operator for location
    Location& operator+=(const Location& rightLocation) const;

    //operator for location
    bool operator()(const Location& leftLocation, const Location& rightLocation) const;

    //+ operator for location
    Location operator+(const Location& rightLocation) const;

    //% operator for location
    Location operator%(const Location& rightLocation) const;

    // helper function for %operator
    int modular(int a, int b);

private:
    int row_;
    int col_;
}; //class location
} //namespace space_invader_game

#endif //FINAL_PROJECT_SHINWJ123_LOCATION_H
