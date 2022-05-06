#include "space_invader_app.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"

namespace spaceInvaderApp {
using cinder::app::KeyEvent;
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

GameApp::GameApp() { }

void GameApp::setup() {
    std::string videoPath = getAssetPath( "media-resources/app_background.mp4" ).string();
    m_Video.loadMovie( videoPath, "Headphones (High Definition Audio Device)" );
    m_Video.play();
    m_Video.setLoop(true);

    game = Game::kStartScreen;
}

void GameApp::update() {
    m_Video.update();

    if (gameEngine.GetPlayer().IsAlive() == false) {
        game = Game::kGameOver;
    }
    if (game == Game::kPlaying && did_start) {
        const auto time = system_clock::now();
        if (time - last_time_invader > std::chrono::milliseconds(invader_speed)) {
            gameEngine.Invader();
            last_time_invader = time;
        }
        if (time - last_time_player > std::chrono::milliseconds(player_speed)) {
            gameEngine.Player();
            last_time_player = time;
        }
        if (time - last_time_projectile
            > std::chrono::milliseconds(projectile_speed)) {
            gameEngine.PlayerProjectileMove();
            last_time_projectile = time;
        }
        if (time - last_time_invader_projectile
            > std::chrono::milliseconds(invader_projectile_speed)) {
            gameEngine.InvaderProjectileMove();
            last_time_invader_projectile = time;
        }
        for (po::SpritesheetAnimationRef invader_anim : invader_spritesheetanim_vector) {
            invader_anim->update();
        }
        mSpritesheetAnimation_nyan_cat->update();

        if (IsWaveClear() || is_r_pressed) {
            NextWave();
        }
    }
    if (game == Game::kGameOver && !gameover_) {
        ci::gl::TextureRef texture = ci::gl::Texture::create(
                loadImage(loadAsset("gameover.png")));
        cinder::JsonTree json = cinder::JsonTree(loadAsset(
                "gameover.json"));
        mSpritesheet_gameover = po::Spritesheet::create(texture, json);
        mSpritesheetAnimation_gameover = po::SpritesheetAnimation::create(
                mSpritesheet_gameover);
        mSpritesheetAnimation_gameover->play();
        mSpritesheetAnimation_gameover->setFrameRate(6);
        gameover_ = true;
    }
    if (game == Game::kGameOver && gameover_) {
        mSpritesheetAnimation_gameover->update();
    }
}

void GameApp::draw() override;

void GameApp::keyDown(KeyEvent keyEvent) {
    switch (keyEvent.getCode()) {
        case KeyEvent::KEY_LEFT: {
            gameEngine.SetDirection(space_invader_game::Action::kLeft);
            break;
        }
        case KeyEvent::KEY_RIGHT: {
            gameEngine.SetDirection(space_invader_game::Action::kRight);
            break;
        }
        case KeyEvent::KEY_SPACE: {
            gameEngine.SetProjectileDirection(space_invader_game::Action::kShoot);
            break;
        }
        case KeyEvent::KEY_p: {
            if (game == Game::kStartScreen) {
                game = Game::kPlaying;
            }
            break;
        }
    }
}

void GameApp::keyUp(KeyEvent keyEvent) {
    switch (keyEvent.getCode()) {
        case KeyEvent::KEY_LEFT: {
            gameEngine.SetDirection(space_invader_game::Movement::kStop);
            break;
        }
        case KeyEvent::KEY_RIGHT: {
            gameEngine.SetDirection(space_invader_game::Movement::kStop);
            break;
        }
        case KeyEvent::KEY_SPACE: {
            gameEngine.SetProjectileDirection(space_invader_game::Movement::kShoot);
            break;
        }
    }
}

void GameApp::ResetGame();

void GameApp::SetWaveAnimation(int wave_number);

void GameApp::DrawInvaderWave();

void GameApp::NextWave();

bool GameApp::IsWaveClear();

void GameApp::DrawPlayer();

void GameApp::DrawPlayerProjectile();

void GameApp::DrawInvaderProjectile();

void GameApp::DrawStartScreen();

void GameApp::DrawGameOver();

void GameApp::DrawScore();


}