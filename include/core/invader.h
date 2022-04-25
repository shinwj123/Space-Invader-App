#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_INVADER_H
#define FINAL_PROJECT_SHINWJ123_INVADER_H

namespace space_invader_game {
    //class for invader
class Invader {
public:
    Invader(const Location& location);

    Location GetLocation() const;
    Location SetLocation(const Location&);

    void SetVisibility(bool visible);
    bool IsVisibile() const;

    void fillWave(const space_invader::Invader& invader);
    Invader GetInvader(int row, int col);

    constexpr static float WIDTH = 50;
    constexpr static float HEIGHT = 27;

    int kAliensPerRow = 7;

private:
    Location location_;
    bool visible_;

}; //class invader
} //namespace space_invader_game



#endif //FINAL_PROJECT_SHINWJ123_INVADER_H
