#pragma once
#include "pch.h"
#include "Pounder.h"
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
	Ranger(Vector2f, int);
	Texture* rangerSkin;
	Texture* rangerSkin2;
	Texture* exploSion;
	Sprite ranger;
	Clock rangerSpeed;
	int rangerHP;
	Clock skinclock;
	Clock shotclock;
	void moveRanger();
	bool skin;
	void gotHitRip(int);
	int rangertexture;
	void Explodey();
	Texture* rangerExplosion;
	Clock rangerExplodeClock;
};

