#include "Projectile.h"

namespace space_invader_game {
    Projectile::Projectile(const Location& location) {
        location_ = location;
        visible_ = true;
    }

    void Projectile::update(float dt)
    {
        try {
            float velocity = 650 * (float)location_ * dt;
            location_.y += speed;
        } catch {
            delete location;
        }


    }

    Location Projectile::GetLocation() const {
        return location_;
    }

    Location Projectile::SetLocation(const Location& location) {
        location_ = location;
        return location_;
    }

    void Projectile::SetVisibility(bool visible) {
        visible_ = visible;
    }

    bool Projectile::IsVisibile() const {
        return visible_;
    }
}

