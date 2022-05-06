#include "player.h"

namespace space_invader_game {
    Player::Player(const Location& location) {
        location_ = location;
        visible_ = true;
    }

    void Player::update(float dt) {
        if (visible_) {
            velocity *= 0.95f;
            if (player.getPosition().x <= 0) {
                velocity.x = 1.0f;
                player.setPosition(1.0f, 95f);
            }
        }
    }

    Location Player::GetLocation() const {
        return location_;
    }

    Location Player::SetLocation(const Location& location) {
        location_ = location;
        return location_;
    }

    void Player::SetAlive(bool alive) {
        alive_ = alive;
    }

    bool Player::IsAlive() const {
        return alive_;
    }
}
