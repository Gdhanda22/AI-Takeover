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
	
	switch skin{
	case 1:
		bulletskin.loadFromFile("bullet.pixelart.png");
		break:
	case 2:
		bulletskin.loadFromFile("");
		break;
	case 3:
		bulletskin.loadFromFile("");
		break;
	}
	
	bullet.setTexture(bulletskin);
	bullet.setPosition(pos);
	bullet.setScale(5, 5);
	window.draw(bullet)

	while (bullet.getPosition().y > 30) {
		if (bulletmover.getElapsedTime().asSeconds() >= .05) {

			bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - 2);
			bulletmover.restart();
			window.draw(bullet)

		}
	}

}