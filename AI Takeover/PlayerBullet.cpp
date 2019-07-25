#include "pch.h"
#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(Vector2f pos, int skin) {

	bulletskin = new Texture();
	
	switch (skin) {
	case 1:
		bulletskin->loadFromFile("bullet.png");
		break;
	case 2:
		bulletskin->loadFromFile("arrow.png");
		break;
	case 3:
		bulletskin->loadFromFile("ball.png");
		bullet.setScale(.8, .8);
		break;
	}
	
	bullet.setTexture(*bulletskin);
	bullet.setPosition(pos);
	bullet.setOrigin(16, 32);
}

void PlayerBullet::MoveBullet() {
	
	if (bullet.getPosition().y > 0) {

		if (bulletmover.getElapsedTime().asSeconds() >= .00075) {
			bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - 3);
			bulletmover.restart();
		}
	}
}