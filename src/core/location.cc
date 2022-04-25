#include "location.h"

namespace space_invader_game {

Location::Location(int row, int col);

int Location::row() const;
int Location::col() const;

Location& operator+=(const Location& rightLocation) const;{
    *this = *this + rightLocation;
    return *this;
}

} //namespace space_invader_game
