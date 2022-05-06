#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_PLAYER_CUH
#define FINAL_PROJECT_SHINWJ123_PLAYER_CUH

namespace space_invader_game {

class Player {
public:
    //constructor for player
    Player(const Location& location);

    //updates the player velocity when time flows
    void update(float dt);

    //getting the location of the player
    Location GetLocation() const;

    //setting the location of the player
    Location SetLocation(const Location&);

    //setting the visibility of the player when died or not
    void SetAlive(bool alive);

    //showing if the player is live or not
    bool IsAlive() const;

private:
    Player player;
    Location location_;
    bool alive_;
    sf::Vector2f velocity;

}; //class Player

} //namespace space_invader_game


#endif //FINAL_PROJECT_SHINWJ123_PLAYER_CUH
