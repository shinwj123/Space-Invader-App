#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_LOCATION_H
#define FINAL_PROJECT_SHINWJ123_LOCATION_H

namespace space_invader_game {

class location {
public:
    Location(int row, int col);

    int row() const;
    int col() const;

    Location& operator+=(const Location& rightLocation) const;

private:
    int row_;
    int col_;
}; //class location
} //namespace space_invader_game

#endif //FINAL_PROJECT_SHINWJ123_LOCATION_H
