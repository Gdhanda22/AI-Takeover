#include "pch.h"
#include "Pounder.h"


Pounder::Pounder(Vector2f pos, int health)
{
	pounderSkin = new Texture();
	pounderSkin->loadFromFile("puff1.png");
	pounder.setTexture(*pounderSkin);
	pounder.setPosition(pos);
	pounder.setOrigin(32.5, 47.5);
	pounder.setScale(2.25, 2.25);
	pounderHP = health;

}


void Pounder::movePounder()
{
	if (pounder.getPosition().y < 700) {

		if (pounderSpeed.getElapsedTime().asSeconds() >= .0325) {
			pounder.setPosition(pounder.getPosition().x, pounder.getPosition().y + .65);
			pounderSpeed.restart();
		}
		if (skinClock.getElapsedTime().asSeconds() >= .1 and skin == 1) {
			skin = 2;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .1 and skin == 2) {
			skin = 3;
			skinClock.restart();
		}
		switch (skin) {
		case 1:
			pounder.setTexture(*pounderSkin);
			break;

		}
	}
}


void Pounder::gotYotRip(int damage) 
{
	pounderHP -= damage;

}
