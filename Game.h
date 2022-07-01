#pragma once
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
#include <sstream>
using namespace sf;
using namespace std;

bool startgame(); // головно функція гри
void gameRun(); // функція для запуску гри та рестарту