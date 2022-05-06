#include "alien.h"
#include "location.h"

namespace space_invader_game {
    Invader::Invader(const Location& location) {
        location_ = location;
        visible_ = true;
    }

    Location Invader::GetLocation() const {
        return location_;
    }

    Location Invader::SetLocation(const Location& location) {
        location_ = location;
        return location_;
    }

    void Invader::SetAlive(bool visible) {
        alive_ = alive;
    }

    bool Invader::IsAlive() const {
        return alive_;
    }
}