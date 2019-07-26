#pragma once
#include "pch.h"
#include "Ranger.h"
#include "RangerBullet.h"
#include "PlayerBullet.h"
#include "Pounder.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace std;
using namespace sf;

class Boss
{
public:
	Boss(int);
	int health;
	sprite boss;
	Texture* boss1;
	Texture* boss2;
	Texture* boss3;
	Texture* boss4;
	Texture* boss5;
	Texture* boss6;
	Texture* boss7;
	void moveBoss();
	Clock bossSpeed;

};

