#pragma once
#include "Ranger.h"
#include "pch.h"
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

class RangerBullet
{
public:
	RangerBullet(Vector2f);
	Texture* cannonballskin;
	Texture* explosion;
	Sprite cannonball;
	Clock cannonballmover;
	void MoveCannonball();
	void Wait();
	Clock explosionclock;
	int cannonballtexture;

};

