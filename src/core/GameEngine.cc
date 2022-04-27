#include "GameEngine.h"

namespace space_invader_game {
GameEngine::GameEngine() {

}

InvaderManager GameEngine::GetWaveInvader() const {
    return wave_invader_;
}
Player GameEngine::GetPlayer() const {
    return player_;
}
Projectile* GameEngine::GetPlayerProjectile() const {
    return player_projectile_;
}
Projectile* GameEngine::GetInvaderProjectile() const; {
    return invader_projectile_;
}

void GameEngine::SetUpWave() {
    for (int i = 0; i < kNumberOfRows; i++) {
        for (int j = 0; j < kNumberOfCols; j++) {
            Location location(j * kNumberOfCols, i * kNumberOfCols + kNumberOfCols);
            wave_invader_.FillWave(Invader(location));
        }
    }
    Location scaled(wave_invader_.GetInvader(2, 1).GetLocation().Row() + 1,
                    wave_invader_.GetInvader(2, 1).GetLocation().Col() + 2);
    invader_projectile_ = new Projectile(scaled);
}

Location GameEngine::GetInitialInvaderPosition(int num_Count) {
    Location loc(0,0);
    int count = 0;

    for (int i = 0; i < kNumberOfRows; i++) {
        for (int j = 0; j < kNumberOfCols; j++) {
            if (count == num_Count) {
                Location initial(j * kNumberOfCols,
                                 i * kNumberOfCols + kNumberOfCols);
                loc = initial;
            }
            count++;
        }
    }
    return loc;
}


void GameEngine::NextWave() {
    int position_count = 0;
    for (Invader& invader : wave_invader_) {
        invader.SetVisibility(true);
        invader.SetLocation(GetInitialInvaderPosition(position_count));
        position_count++;
    }
}

void GameEngine::ResetGame() {
    int position_count = 0;

    for (Invader& invader : wave_invader_) {
        invader.SetVisibility(true);
        invader.SetLocation(GetInitialInvaderPosition(position_count));
        position_count++;
    }

    if (score > high_score) {
        high_score = score;
    }

    score = 0;

    player.SetVisibility(true);
}

int GameEngine::GetScore() const {
    return score;
}
int GameEngine::GetHighScore() const {
    return high_score;
}

} //namespace space_invader_game
