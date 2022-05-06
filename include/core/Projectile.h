#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_PROJECTILE_H
#define FINAL_PROJECT_SHINWJ123_PROJECTILE_H

namespace space_invader_game {

class Projectile {
public:
    //constructor for projectile
    Projectile(const Location& location);

    //updates the projectile velocity when time flows
    void update(float dt);

    //getting the location of the projectile
    Location GetLocation() const;

    //setting the location of the projectile
    Location SetLocation(const Location&);

    //setting the visibility of the projectile when died or not
    void SetAlive(bool alive);

    //showing if the projectile is live or not
    bool IsAlive() const;

private:
    Location location_;
    bool alive_;
    sf::Vector2f velocity;
}; //class Projectile

} //namespace space_invader_game
#endif //FINAL_PROJECT_SHINWJ123_PROJECTILE_H
