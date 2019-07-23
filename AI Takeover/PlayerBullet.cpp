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


PlayerBullet::PlayerBullet(Vector2f pos, int skin) {

	bulletskin = new Texture();
	
	switch (skin) {
	case 1:
		bulletskin->loadFromFile("bullet.png");
		break;
	case 2:
		bulletskin->loadFromFile("arrow.png");
		break;
	case 3:
		bulletskin->loadFromFile("ball.png");
		bullet.setScale(.8, .8);
	}
	
	bullet.setTexture(*bulletskin);
	bullet.setPosition(pos);
	bullet.setOrigin(16, 16);
}

PlayerBullet::~PlayerBullet() {
	//delete(bulletskin);
}

void PlayerBullet::MoveBullet() {
	
	if (bullet.getPosition().y > -30) {

		if (bulletmover.getElapsedTime().asSeconds() >= .00075) {
			bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - 1);
			bulletmover.restart();
		}
	}
}