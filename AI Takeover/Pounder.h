#pragma once
#include "pch.h"
#include "Ranger.h"
#include "RangerBullet.h"
#include "PlayerBullet.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace std;
using namespace sf;

class Pounder
{
public:
	Pounder(Vector2f, int);
	Texture* pounderSkin;
	Sprite pounder;
	Clock pounderSpeed;
	int pounderHP;
	Clock shotClock;
	Clock skinClock;
	void movePounder();
	int skin;
	void gotYotRip(int);
};

