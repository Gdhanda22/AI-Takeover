#include "pch.h"
#include "Ranger.h"


Ranger::Ranger(Vector2f pos)
{
	rangerSkin = new Texture();
	rangerSkin->loadFromFile("Ranger1.png");
	ranger.setTexture(*rangerSkin);
	ranger.setPosition(pos);
	ranger.setOrigin(50, 50);
	ranger.setScale(1.5, 1.5);

}


void Ranger::moveRanger()
{
	if (ranger.getPosition().y < 393) {

		if (rangerSpeed.getElapsedTime().asSeconds() >= .0375) {
			ranger.setPosition(ranger.getPosition().x, ranger.getPosition().y + 1);
			rangerSpeed.restart();
		}
	}
}
