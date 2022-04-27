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
}
