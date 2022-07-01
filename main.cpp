#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <random>
#include <ctime>
#include "Pipe.h"
#include "Button.h"
#include "Restart.h"
#include "Menu.h"
#include "Collision.h"
#include "Game.h"
#include <sstream>
#include <vector>
using namespace sf;
using namespace std;

int main()
{
    gameRun(); // виклик функції для запуску гри
    return 0;
}