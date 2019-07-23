#pragma once
#include "pch.h"
#include "Pounder.h"
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

class Ranger
{
public:
	Ranger(Vector2f);
	Texture* rangerSkin;
	Sprite ranger;
	Clock rangerSpeed;
	void moveRanger();
};

