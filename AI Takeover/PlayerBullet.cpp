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


PlayerBullet::PlayerBullet(Vector2f pos)
{
	bulletskin.loadFromFile("bullet.pixelart.png");
	bullet.setTexture(bulletskin);
	bullet.setPosition(pos);
	bullet.setScale(5, 5);
}

void PlayerBullet::MoveBullet() {
	while (bullet.getPosition().y > 30) {
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - 2);
	}
}
