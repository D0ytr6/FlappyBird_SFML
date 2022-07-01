#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>
using namespace sf;
using namespace std;
class Pipe {
public:
    string File;
    float x, y1, y2;
    float check, check2;
    Image image, image2;
    Texture texture, texture2;
    Sprite sprite, sprite2;
    float Move = 0;
    int random;
    int counter = 0;
    Pipe(string F, int X);
    int RandY(); // функція для генерування координати Y
    void update_pipe(float times); // функція для руху перешкод
    void draw_pipe(RenderWindow &window); // функція для відрисовування перешкод
};
