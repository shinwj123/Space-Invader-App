#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_INVADER_H
#define FINAL_PROJECT_SHINWJ123_INVADER_H

namespace space_invader_game {
    //class for invader
    class invader {
public:
    explicit invader(const Location& location);

    Location GetLocation() const;
    Location SetLocation(const Location&);

    void SetVisibility(bool visible);
    bool IsVisibile() const;
private:
    Location location_;
    bool visible_;

}; //class invader
} //namespace space_invader_game



#endif //FINAL_PROJECT_SHINWJ123_INVADER_H
