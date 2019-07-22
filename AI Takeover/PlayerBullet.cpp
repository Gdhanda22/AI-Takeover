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


PlayerBullet::PlayerBullet(Vector2f pos) {

	bulletskin = new Texture();
	bulletskin->loadFromFile("bullet.png");
	bullet.setTexture(*bulletskin);
	bullet.setPosition(pos);
	bullet.setOrigin(16, 16);
}


void PlayerBullet::MoveBullet() {
	
	if (bullet.getPosition().y > -30) {

		if (bulletmover.getElapsedTime().asSeconds() >= .00075) {
			//cout << bullet.getPosition().y << " ";
			bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - 1);
			//cout << bullet.getPosition().y << endl;
			bulletmover.restart();
		}
	}
	else {

	}


}