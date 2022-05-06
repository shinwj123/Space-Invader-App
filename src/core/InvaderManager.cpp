#include "InvaderManager.h"

namespace space_invader_game {
    void InvaderManager::fillWave(const Invader& invader) {
        wave.push_back(invader);
    }

    Invader InvaderManager::GetInvader(int row, int col) {
        int invaderNumber = (row * kAliensPerRow) + col;
        return wave.at(invaderNumber);
    }

    Invader InvaderManager::GetCertainAlien(int index) {
        return wave.at(index)
    }

    void InvaderManager::initAddInvader()
    {
        static sf::Clock delay;
        if (delay.getElapsedTime().asSeconds() > 0.02) {
            invader.at(initY * 11 + initX).makeAlive();
            aliveInvader++;
            initX++;

            if (initX == 11) {
                initX = 0;
                initY--;
            }
            delay.restart();
        }
    }
}
