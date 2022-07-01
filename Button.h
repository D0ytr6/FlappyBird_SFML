#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Button {
public:
    
    Texture button;
    Sprite ButtonSprite;
    string File;
    float x, y;
    float scaleX, scaleY;
    Button(string F, int X, int Y, float Scalex, float Scaley); // конструктор класа для завантаження параметрів
};