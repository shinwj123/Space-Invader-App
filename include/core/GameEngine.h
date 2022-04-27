#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_GAMEENGINE_H
#define FINAL_PROJECT_SHINWJ123_GAMEENGINE_H

namespace space_invader_game {

class GameEngine {
public:
    GameEngine();
    InvaderManager GetWaveInvader() const;
    Player GetPlayer() const;
    Projectile* GetPlayerProjectile() const;
    Projectile* GetInvaderProjectile() const;

    void SetUpWave();
    Location GetInitialInvaderPosition(int n);

    void NextWave();
    void ResetGame();

    int GetScore() const;
    int GetHighScore() const;



private:
    int score = 0;
    int high_score = 0;

    InvaderManager wave_invader_;
    Player player_;
    Projectile* player_projectile_;
    Projectile* invader_projectile_;

    int kDimension = 48;
    int kNumberOfRows = 4;
    int kNumberOfCols = 7;
}; //class gameEngine

} //namespace space_invader_game



#endif //FINAL_PROJECT_SHINWJ123_GAMEENGINE_H
