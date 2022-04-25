#include "main.h"

sf::Texture spritesheet;
sf::Sprite invader;

void main::Load() {
    if (!spritesheet.loadFromFile("media-resources/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void main::Render() {
    window.draw(invader);
}
