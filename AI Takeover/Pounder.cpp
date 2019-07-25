#include "pch.h"
#include "Pounder.h"


Pounder::Pounder(Vector2f pos, int health)
{
	pounderSkin = new Texture();
	pounderSkin->loadFromFile("");
	pounder.setTexture(*pounderSkin);
	pounder.setPosition(pos);
	pounder.setOrigin(32, 38.5);
	pounder.setScale(3, 3);

	pounderHP = health;

}


void Pounder::movePounder()
{
	if (pounder.getPosition().y < 700) {

		if (pounderSpeed.getElapsedTime().asSeconds() >= .0325) {
			pounder.setPosition(pounder.getPosition().x, pounder.getPosition().y + .5);
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
			pounder.setTexture(*rangerSkin);
			break;
		
	}
}


void Pounder::gotHitRip(int damage)
{
	pounderHP -= damage;

}
