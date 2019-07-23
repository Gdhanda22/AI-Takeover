#include "pch.h"
#include "Ranger.h"


Ranger::Ranger(Vector2f pos)
{
	rangerSkin = new Texture();
	rangerSkin->loadFromFile("Ranger1.png");
	rangerSkin2 = new Texture();
	rangerSkin2->loadFromFile("Ranger2.png");
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
		if (skinclock.getElapsedTime().asSeconds() >= .3 and skin == true) {
			skin = false;
			skinclock.restart();
		}
		else if (skinclock.getElapsedTime().asSeconds() >= .3 and skin == false) {
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

