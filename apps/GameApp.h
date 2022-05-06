#pragma once
#ifndef FINAL_PROJECT_SHINWJ123_SPACE_INVADER_APP_H
#define FINAL_PROJECT_SHINWJ123_SPACE_INVADER_APP_H

#include <cinder/ImageIo.h>
#include <cinder/gl/Texture.h>
#include <cinder/Tween.h>
#include <cinder/app/App.h>
#include <poSpritesheet/poSpritesheet.h>
#include <poSpritesheet/poSpritesheetAnimation.h>
#include <cinder/audio/audio.h>
#include <ciWMFVideoPlayer.h>
#include <cinder/params/Params.h>

#include "../src/GameEngine.h"


namespace spaceInvaderApp {
using std::chrono::time_point;
using std::chrono::system_clock;
using cinder::app::KeyEvent;


enum class Game {
    kStartScreen,
    kPlaying,
    kGameOver,
};

class GameApp {

public:
    //empty constructor for space invader application
    GameApp();

    //setting up the background of the application
    void setup() override;

    //updates the acitivities in application
    void update() override;

    //drawing for the game
    void draw() override;

    //clicking the down key
    void keyDown(KeyEvent keyEvent) override;

    //clicking the up key
    void keyUp(KeyEvent keyEvent) override;

    //reset game
    void ResetGame();

    //setting animation for wave
    void SetWaveAnimation(int wave_number);

    //drawing the wave
    void DrawInvaderWave();

    //moving on to the next wave
    void NextWave();

    //checking the wave
    bool IsWaveClear();

    //drawing player
    void DrawPlayer();

    //drawing projectile from player
    void DrawPlayerProjectile();

    //drawing projectile from invader
    void DrawInvaderProjectile();

    //drawing the starting screen
    void DrawStartScreen();

    //drawing the game over screen
    void DrawGameOver();

    //drawing the score
    void DrawScore();

private:
    space_invader::GameEngine gameEngine;

    Game game;

    ciWMFVideoPlayer m_Video;

    bool gameover_ = false;

    time_point<system_clock> last_time_invader;
    time_point<system_clock> last_time_player;
    time_point<system_clock> last_time_projectile;
    time_point<system_clock> last_time_invader_projectile;


};  //class space_invader_app

} //namespace spaceInvaderApp



#endif //FINAL_PROJECT_SHINWJ123_SPACE_INVADER_APP_H
