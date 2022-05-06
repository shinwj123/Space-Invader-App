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

    void SetProjectileDirection(const Movement movement);

    void InvaderMove();
    void PlayerMove();
    void PlayerProjectile();
    void InvaderProjectile();

    Location MoveInvaderWave(bool toRight, int count_to_border);
    Location MovePlayer();
    Location MoveProjectile();
    Location MoveInvaderProjectile();

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

    Movement move_player;
    Movement move_player_projectile;
    Movement move_invader_projectile;

    int count_to_border = 0;
    int projectile_distance = 0;
    int invader_projectile_distance = 0;

    bool toRight = true
}; //class gameEngine

} //namespace space_invader_game



#endif //FINAL_PROJECT_SHINWJ123_GAMEENGINE_H
