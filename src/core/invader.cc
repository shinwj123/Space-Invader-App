#include "alien.h"
#include "location.h"

namespace space_invader {
    Invader::Invader(const Location& location)
            : location_(location), visible_{true} {}

    Location Invader::GetLocation() const {
        return location_;
    }

    Location Invader::SetLocation(const Location& location) {
        location_ = location;
        return location_;
    }

    void Invader::SetVisibility(bool visible) {
        visible_ = visible;
    }

    bool Invader::IsVisibile() const {
        return visible_;
    }
}