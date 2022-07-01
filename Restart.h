#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include <sstream>

class Restart {
public:
    ostringstream ScoreCount; // створюємо потокову змінну
    bool Isrestart = true;
    Image image;
    Texture background, text;
    Sprite backgSprite, textSprite;
    Text scores;
    Font font;
    Button exit, restartGame;
    Restart(RenderWindow& window, int& score);
    bool update_events(RenderWindow& window); // функція для перевірки нажать
    void draw(RenderWindow& window); // функція для відображення елементів вікна рестарту
};