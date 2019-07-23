#include "pch.h"
#include "Ranger.h"


Ranger::Ranger(Vector2f pos)
{
	rangerSkin = new Texture();
	rangerSkin->loadFromFile("");
	ranger.setTexture(*rangerSkin);
	ranger.setPosition(pos);
	ranger.setOrigin(50, 50);

}


void Ranger::moveRanger()
{
	if (ranger.getPosition().y < 300) {

		if (rangerSpeed.getElapsedTime().asSeconds() >= .01) {
			ranger.setPosition(ranger.getPosition().x, ranger.getPosition().y + 1);
			rangerSpeed.restart();
		}
	}
}
