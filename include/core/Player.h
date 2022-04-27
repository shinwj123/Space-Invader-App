#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_PLAYER_CUH
#define FINAL_PROJECT_SHINWJ123_PLAYER_CUH

namespace space_invader_game {

class Player {
public:
    Player(const Location& location);

    Location GetLocation() const;
    Location SetLocation(const Location&);

    void SetVisibility(bool visible);
    bool IsVisibile() const;

private:
    Location location_;
    bool visible_;

}; //class Player

} //namespace space_invader_game


#endif //FINAL_PROJECT_SHINWJ123_PLAYER_CUH
