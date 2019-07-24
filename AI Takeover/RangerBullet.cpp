#include "pch.h"
#include "RangerBullet.h"


RangerBullet::RangerBullet(Vector2f pos)
{
	cannonballskin = new Texture;
	cannonballskin->loadFromFile("cannonball.png");
	explosion = new Texture;
	explosion->loadFromFile("explosion.png");
	cannonball.setTexture(*cannonballskin);
	cannonball.setPosition(pos);
	cannonball.setOrigin(16, 16);
	cannonball.setScale(.5, .5);
	cannonballtexture = 1;
}

void RangerBullet::MoveCannonball() {
	
	if (cannonball.getPosition().y < 783) {

		if (cannonballmover.getElapsedTime().asSeconds() >= .00075) {
			cannonball.setPosition(cannonball.getPosition().x, cannonball.getPosition().y + .75);
			cannonballmover.restart();
		}
	}
}

void RangerBullet::Wait() {
	cannonball.setTexture(*explosion);
	cannonball.setScale(1.25, 1.25);
	cannonballtexture = 2;
}