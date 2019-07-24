#include "pch.h"
#include "Ranger.h"


Ranger::Ranger(Vector2f pos, int health)
{
	rangerSkin = new Texture();
	rangerSkin->loadFromFile("Ranger1.png");
	rangerSkin2 = new Texture();
	rangerSkin2->loadFromFile("Ranger2.png");
	ranger.setTexture(*rangerSkin);
	ranger.setPosition(pos);
	ranger.setOrigin(21, 24);
	ranger.setScale(1.5, 1.5);

	rangerHP = health;

}


void Ranger::moveRanger()
{
	if (ranger.getPosition().y < 373) {

		if (rangerSpeed.getElapsedTime().asSeconds() >= .0325) {
			ranger.setPosition(ranger.getPosition().x, ranger.getPosition().y + 1.25);
			rangerSpeed.restart();
		}
		if (skinclock.getElapsedTime().asSeconds() >= .2 and skin == true) {
			skin = false;
			skinclock.restart();
		}
		else if (skinclock.getElapsedTime().asSeconds() >= .2 and skin == false) {
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
	else {
		if (shotclock.getElapsedTime().asSeconds() >= 1.5) {
			RangerBullet ranger(Vector2f(ranger.getPosition().x, ranger.getPosition().y + 20));
			rangerbulletVector.push_back(ranger);
			shotclock.restart;
		}
	}
}

void Ranger::gotHitRip(int damage)
{
	rangerHP -= damage;

}