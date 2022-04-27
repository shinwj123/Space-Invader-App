#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H
#define FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H

namespace space_invader_game {
using namespace std;
    //class for invader manager
class InvaderManager {
public:
    deque<Invader>::iterator begin();

    void fillWave(const Invader& invader);

    Invader GetInvader(int row, int col);

    Invader GetCertainAlien(int index);

    int kAliensPerRow = 7;

private:
    deque<Invader> wave;


}; //class InvaderManager

} //namespace space_invader_game


#endif //FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H
