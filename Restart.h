#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include <sstream>

class Restart {
public:
    ostringstream ScoreCount; // ��������� �������� �����
    bool Isrestart = true;
    Image image;
    Texture background, text;
    Sprite backgSprite, textSprite;
    Text scores;
    Font font;
    Button exit, restartGame;
    Restart(RenderWindow& window, int& score);
    bool update_events(RenderWindow& window); // ������� ��� �������� ������
    void draw(RenderWindow& window); // ������� ��� ����������� �������� ���� ��������
};