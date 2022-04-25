#include "alien.h"
#include "location.h"

namespace space_invader {
    invader::invader(const Location& location)
            : location_(location), visible_{true} {}

    Location invader::GetLocation() const {
        return location_;
    }

    Location invader::SetLocation(const Location& location) {
        location_ = location;
        return location_;
    }

    void invader::SetVisibility(bool visible) {
        visible_ = visible;
    }

    bool invader::IsVisibile() const {
        return visible_;
    }
}