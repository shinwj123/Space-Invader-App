#include "location.h"

namespace space_invader_game {

Locations::Location(int row, int col) : row_(row), col_(col){

}

int Locations::row() const {
    return row_;
}
int Location::col() const {

}

bool Location::operator()(const Location& leftLocation, const Location& rightLocation) const {
    return leftLocation <= rightLocation;
}

Location Location::operator+(const Location& rightLocation) const {
    return {row_ + rightLocation.row_, col_ + rightLocation.col_};
}

LocationLocation:: operator%(const Location& rightLocation) const {
    return {modular(row_, rightLocation.row_), modular(col_, rightLocation.col_)};

}

Location& Location::operator+=(const Location& rightLocation) const {
*this = *this + rightLocation;
return *this;
}

int Location::modular(int a, int b) {
    int c = a % b;
    return c + (c < 0 ? b : 0);
}

} //namespace space_invader_game
