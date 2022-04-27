#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_LOCATION_H
#define FINAL_PROJECT_SHINWJ123_LOCATION_H

namespace space_invader_game {

class Location {
public:
    Location(int row, int col);

    int row() const;
    int col() const;

    Location& operator+=(const Location& rightLocation) const;

    bool operator()(const Location& lhs, const Location& rhs) const;

    Location operator+(const Location& rhs) const;

    Location operator%(const Location& rhs) const;

    int modular(int a, int b);

private:
    int row_;
    int col_;
}; //class location
} //namespace space_invader_game

#endif //FINAL_PROJECT_SHINWJ123_LOCATION_H
