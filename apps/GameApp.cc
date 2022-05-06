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

        if (invader.IsVisibile() != true) {
            gameEngine.NextWave();
            wave_count++;
            int current_wave = wave_count % 3;
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

void GameApp::draw() override {
    cinder::gl::clear();
    m_Video.draw( 0, 0, 800, 800 );

    if (state == GameState::kStartScreen) {
        DrawStartScreen();
        return;
    }

    if (gameEngine.GetPlayer().IsAlive() == false) {
        DrawPlayer();
        DrawPlayerProjectile();
        DrawInvader();
        DrawInvaderProjectile();
    }

    if (state == GameState::kGameOver) {
        cinder::gl::clear();
        m_Video.draw( 0, 0, 800, 800 );
        DrawGameOver();
    }
}

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
        case KeyEvent::KEY_r: {
            if (state == GameState::kGameOver) {
                gameEngine.ResetGame();
                wave_count = 0;
                gameover_ = false;
                game = Game::kStartScreen;
            }
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

void GameApp::DrawInvader() {
    space_invader_game::Location invader_loc;
    invader_loc = gameEngine.GetInvader().GetLocation();
    cinder::vec2 invader_location = cinder::vec2(
            invader_loc.Row() * kTileSize,
            invader_loc.Col() * kTileSize);
    ci::gl::draw(ci::gl::Texture::create(loadImage(
            loadAsset("invaders.png"))), invader_location);
}

void GameApp::DrawPlayer() {
    space_invader_game::Location player_loc;
    player_loc = gameEngine.GetPlayer().GetLocation();
    cinder::vec2 player_location = cinder::vec2(
            player_loc.Row() * kTileSize,
            player_loc.Col() * kTileSize);
    ci::gl::draw(ci::gl::Texture::create(loadImage(
            loadAsset("player.png"))), player_location);
}

void GameApp::DrawPlayerProjectile() {
    space_invader_game::Location player_projectile_loc;
    player_projectile_loc = gameEngine.GetPlayerProjectile().GetLocation();
    cinder::vec2 player_projectile_location = cinder::vec2(
            player_projectile_loc.Row() * kTileSize,
            player_projectile_loc.Col() * kTileSize);
    ci::gl::draw(ci::gl::Texture::create(loadImage(
            loadAsset("playerProjectile.png"))), player_projectile_location);
}

void GameApp::DrawInvaderProjectile() {
    space_invader_game::Location invader_projectile_loc;
    invader_projectile_loc = gameEngine.GetInvaderProjectile().GetLocation();
    cinder::vec2 invader_projectile_location = cinder::vec2(
            invader_projectile_loc.Row() * kTileSize,
            invader_projectile_loc.Col() * kTileSize);
    ci::gl::draw(ci::gl::Texture::create(loadImage(
            loadAsset("invader_bullet.png"))), invader_projectile_location);
}


void GameApp::DrawStartScreen() {
    const Color color = Color::yellow();
    const cinder::vec2 game_title = getWindowCenter();
    const cinder::vec2 play_message = {getWindowCenter().x,getWindowCenter().y + 50};
    const cinder::vec2 size = {500, 50};
    PrintText("SPACE  INVADERS", color, size, game_title);
    PrintText("PRESS P TO PLAY", color, size, play_message);
}

void GameApp::DrawGameOver() {
    mPos = ci::vec2(getWindowCenter().x - 180, getWindowCenter().y);
    ci::gl::pushModelView();
    ci::vec2 val = mPos.value();
    ci::gl::translate(val.x, val.y);
    mSpritesheetAnimation_gameover -> draw();
    ci::gl::popModelView();

    const Color color = Color::white();
    const cinder::vec2 restart_message = {getWindowCenter().x,
                                          getWindowCenter().y + 100};
    const cinder::ivec2 size = {500, 50};
    PrintText("PRESS R TO RESTART", color, size, restart_message);
}

} //namespace