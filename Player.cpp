#include "Player.h"

    Player::Player(string F, int X, int Y) {
        File = F;
        x = X;
        y = Y;
        image.loadFromFile(File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
    }
    void Player::update(float time) {
        x = 0;
        y = Fall * time;
        sprite.move(x, y);
    }