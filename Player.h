#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Player {
public:
    string File;
    float x, y;
    Image image;
    Texture texture;
    Sprite sprite;
    float Fall = 0;
    bool alive;
    Player(string F, int X, int Y); // конструктор класу
    void update(float time); // функція руху персонажа
};

