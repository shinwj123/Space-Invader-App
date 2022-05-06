#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H
#define FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H
#include "Invader.h"

namespace space_invader_game {
using namespace std;
    //class for invader manager
class InvaderManager {
public:
    //beginning the wave
    deque<Invader>::iterator begin();

    //filling the wave
    void fillWave(const Invader& invader);

    //gets the invader for wave
    Invader GetInvader(int row, int col);

    //gets certain invader
    Invader GetCertainAlien(int index);

    //adds invader
    void initAddInvader();

    int kAliensPerRow = 7;

private:
    deque<Invader> wave;
    unsigned aliveInvader = 0;
    int initX = 0;
    int initY = 4;

}; //class InvaderManager

} //namespace space_invader_game


#endif //FINAL_PROJECT_SHINWJ123_INVADERMANAGER_H
