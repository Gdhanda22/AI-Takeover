#include "pch.h"
#include "Boss.h"


Boss::Boss(int bossHealth)
{
	health = bossHealth
	boss.setTexture(*boss1);
	boss.setPosition(720, -15);
	boss.setOrigin(26, 35);
	pounder.setScale(4, 4);

	boss1 = new Texture();
	boss1->loadFromFile("boss1.png");
	boss2 = new Texture();
	boss2->loadFromFile("boss2.png");
	boss3 = new Texture();
	boss3->loadFromFile("boss3.png");
	boss4 = new Texture();
	boss4->loadFromFile("boss4.png");
	boss5 = new Texture();
	boss5->loadFromFile("boss5.png");
	boss6 = new Texture();
	boss6->loadFromFile("boss6.png");
	boss7 = new Texture();
	boss7->loadFromFile("boss7.png");

}

void Boss::moveBoss()
{
	if (boss.getPosition().y < 550) {

		if (bossSpeed.getElapsedTime().asSeconds() >= .05) {
			boss.move(0, -1);
			bossSpeed.restart();
		}
		if (skinClock.getElapsedTime().asSeconds() >= .3 and skin == 1) {
			skin = 2;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 2) {
			skin = 3;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 3) {
			skin = 4;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 4) {
			skin = 5;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 5) {
			skin = 6;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 6) {
			skin = 7;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 7) {
			skin = 8;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 8) {
			skin = 9;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 9) {
			skin = 10;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 10) {
			skin = 11;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 11) {
			skin = 12;
			skinClock.restart();
		}
		else if (skinClock.getElapsedTime().asSeconds() >= .12 and skin == 12) {
			skin = 1;
			skinClock.restart();
		}
		
		switch (skin) {
		case 1:
			boss.setTexture(*boss1);
			break;
		case 2:
			boss.setTexture(*boss2);
			break;
		case 3:
			boss.setTexture(*boss3);
			break;
		case 4:
			boss.setTexture(*boss4);
			break;
		case 5:
			boss.setTexture(*boss5);
			break;
		case 6:
			boss.setTexture(*boss6;
			break;
		case 7:
			boss.setTexture(*boss7);
			break;
		case 8:
			boss.setTexture(*boss6);
			break;
		case 9:
			boss.setTexture(*boss5);
			break;
		case 10:
			boss.setTexture(*boss4);
			break;
		case 11:
			boss.setTexture(*boss3);
			break;
		case 12:
			boss.setTexture(*boss2);
			break;
		
		}
	}
}