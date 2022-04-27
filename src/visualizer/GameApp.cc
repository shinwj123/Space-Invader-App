#include "space_invader_app.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"

namespace spaceInvaderApp {
using cinder::app::KeyEvent;

GameApp::GameApp() { }

void GameApp::setup() {
    std::string videoPath = getAssetPath( "media-resources/app_background.mp4" ).string();
    mVideo1.loadMovie( videoPath, "Headphones (High Definition Audio Device)" );
    mVideo1.play();
    mVideo1.setLoop(true);

    state = GameState::kStartScreen;
}

void GameApp::update() {
    mVideo1.update();
}


}