#include "pch.h"
#include "Ranger.h"


Ranger::Ranger(Vector2f pos, int health)
{
	rangerSkin = new Texture();
	rangerSkin->loadFromFile("Ranger1.png");
	rangerSkin2 = new Texture();
	rangerSkin2->loadFromFile("Ranger2.png");
	rangerExplosion = new Texture();
	rangerExplosion->loadFromFile("explosion.png");
	ranger.setTexture(*rangerSkin);
	ranger.setPosition(pos);
	ranger.setOrigin(21, 24);
	ranger.setScale(1.5, 1.5);
	rangertexture = 1;
	rangerHP = health;

}


void Ranger::moveRanger()
{
	if (ranger.getPosition().y < 373 and rangertexture == 1) {

		if (rangerSpeed.getElapsedTime().asSeconds() >= .0325) {
			ranger.setPosition(ranger.getPosition().x, ranger.getPosition().y + 1.25);
			rangerSpeed.restart();
		}
		if (skinclock.getElapsedTime().asSeconds() >= .15 and skin == true) {
			skin = false;
			skinclock.restart();
		}
		else if (skinclock.getElapsedTime().asSeconds() >= .15 and skin == false) {
			skin = true;
			skinclock.restart();
		}
		if (skin) {
			ranger.setTexture(*rangerSkin);
		}
		else if (!skin) {
			ranger.setTexture(*rangerSkin2);
		}
	}
}

void Ranger::gotHitRip(int damage)
{
	rangerHP -= damage;

}

void Ranger::Explodey() {
	ranger.setTexture(*rangerExplosion);
	ranger.setScale(2.75, 2.75);
	ranger.setOrigin(16.5, 16.5);
	rangertexture = 2;
}