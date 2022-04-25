#include "location.h"

namespace space_invader_game {

location::location(int row, int col);

int location::row() const;
int location::col() const;

Location& operator+=(const Location& rightLocation) const;{
    *this = *this + rightLocation;
    return *this;
}

} //namespace space_invader_game
