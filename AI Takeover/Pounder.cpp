#include "pch.h"
#include "Pounder.h"


Pounder::Pounder(Vector2f pos, int health)
{
	pounderSkin = new Texture();
	pounderSkin->loadFromFile("pounder1.png");
	puff1 = new Texture();
	puff1->loadFromFile("puff1.png");
	puff2 = new Texture();
	puff2->loadFromFile("puff2.png");
	puff3 = new Texture();
	puff3->loadFromFile("puff3.png");
	puff4 = new Texture();
	puff4->loadFromFile("puff4.png");
	puff5 = new Texture();
	puff5->loadFromFile("puff5.png");
	puff6 = new Texture();
	puff6->loadFromFile("puff6.png");

	pounder.setTexture(*pounderSkin);
	pounder.setPosition(pos);
	pounder.setOrigin(32.5, 47.5);
	pounder.setScale(2.25, 2.25);
	pounderHP = health;
	skin = 1

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
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 2) {
			skin = 3;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 3) {
			skin = 4;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 4) {
			skin = 5;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 5) {
			skin = 6;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 6) {
			skin = 7;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .05 and skin == 7) {
			skin = 1;
			skinClock.restart();
		}
		switch (skin) {
		case 1:
			pounder.setTexture(*pounderSkin);
			break;
		case 2:
			pounder.setTexture(*puff1);
			break;
		case 3:
			pounder.setTexture(*puff2);
			break;
		case 4:
			pounder.setTexture(*puff3);
			break;
		case 5:
			pounder.setTexture(*puff4);
			break;
		case 6:
			pounder.setTexture(*puff5);
			break;
		case 7:
			pounder.setTexture(*puff6);
			break;

		}
	}
}


void Pounder::gotYotRip(int damage) 
{
	pounderHP -= damage;

}
