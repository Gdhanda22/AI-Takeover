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


Ranger::moveRanger()
{
	if (ranger.getPosition().y < 300) {

		if (rangerSpeed.getElapsedTime().asSeconds() >= .01) {
			bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y + 1);
			bulletmover.restart();
		}
	}
}
