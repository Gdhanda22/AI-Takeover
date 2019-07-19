#include "pch.h"
#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(Vector2f)
{
	bulletskin.loadFromFile("bullet.pixelart.png")
	bullet.setTexture(bulletskin)
	bullet.setPosition((player.getPosition().x + 5), 825)
}

void PlayerBullet::MoveBullet() {
	while (bullet.getPosition().y > 30) {
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y + 2);
	}
}
