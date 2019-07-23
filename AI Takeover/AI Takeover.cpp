// AI Takeover.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Pounder.h"
#include "Ranger.h"
#include "RangerBullet.h"
#include "PlayerBullet.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
using namespace std;
using namespace sf;

int main()
{
	// The Player
	Sprite player;
	Texture playerskin;
	Texture playershoot;
	playershoot.loadFromFile("shot.png");
	playerskin.loadFromFile("player.png");
	player.setTexture(playerskin);
	player.setOrigin(50, 50);
	player.setPosition(720, 826);
	player.setScale(1.85, 1.85);
	int shootingskinstuff;
	shootingskinstuff = 1;

	int playerDamage = 50;

	// Skin Selection 
	Sprite fakeNiv;
	Texture fullarrow;
	fullarrow.loadFromFile("fullarrow.png");
	Texture halfarrow;
	halfarrow.loadFromFile("halfarrow.png");
	Texture noarrow;
	noarrow.loadFromFile("noarrow.png");
	fakeNiv.setTexture(fullarrow);
	fakeNiv.setOrigin(50, 50);
	fakeNiv.setPosition(147, 655);
	fakeNiv.setScale(2.2, 2.2);

	Sprite fakeJux; 
	Texture gunnerJux;
	gunnerJux.loadFromFile("player.png");
	fakeJux.setTexture(gunnerJux);
	fakeJux.setOrigin(50, 50);
	fakeJux.setPosition(342, 658);
	fakeJux.setScale(2.3, 2.3);

	Sprite fakeDel;
	Texture throwerDel;
	throwerDel.loadFromFile("withball.png");
	Texture yeet;
	yeet.loadFromFile("withoutball.png");
	fakeDel.setTexture(throwerDel);
	fakeDel.setOrigin(50, 50);
	fakeDel.setPosition(529, 669);
	fakeDel.setScale(1.95, 1.95);

	int skin = 1;


	// The Background
	Sprite background;
	Texture backgroundskin;
	backgroundskin.loadFromFile("background.png");
	background.setTexture(backgroundskin);
	background.setOrigin(0, 0);
	background.setScale(9, 9);
	Sprite border;
	Texture borderskin;
	borderskin.loadFromFile("brdrz.png");
	border.setTexture(borderskin);
	border.setOrigin(0, 0);
	border.setScale(9, 9);
	Sprite top;
	Texture topskin;
	topskin.loadFromFile("top.png");
	top.setTexture(topskin);
	top.setPosition(0, 0);
	top.setScale(9, 9);

	Music music; 
	music.openFromFile("GameMusic.wav");
	music.play();
	music.setLoop(true);

	//Pounder Stuff
	sf::Sprite pounder;
	sf::Texture pounderskin;
	pounderskin.loadFromFile("pounder.png");
	pounder.setTexture(pounderskin);
	pounder.setPosition(200, 200);
	pounder.setScale(1.75, 1.75);

	// Start Screen Stuff
	Sprite name;
	Texture nameskin;
	nameskin.loadFromFile("name.png");
	name.setTexture(nameskin);
	name.setOrigin(50, 50);
	name.setScale(6.5, 6.5);
	name.setPosition(720, 263.55);
	Sprite start;
	Texture startbutton;
	startbutton.loadFromFile("start.png");
	start.setTexture(startbutton);
	start.setPosition(720, 450);
	start.setScale(6.6969696969, 6.6969696969);
	start.setOrigin(50, 50);

	// Ranger Spawning Timers and Stuff
	Clock decreasetime;
	double decreasethedecrease = 0;
	Clock rangerHealthBoost;
	int rangerHealth = 200;

	// Shooting Stuff
	Clock clock;
	Clock clock2;
	Clock enemy;
	vector<PlayerBullet> projectileVector;
	vector<Ranger> rangerVector;
	random_device rangerx;

	// Movement
	bool PlayerLeft = false;
	bool PlayerRight = false;
	bool Shooting = false;
	bool Playing = false;
	bool ShotSkin = false;
	bool NameSize = false;
	bool Yeeter = false;
	bool EnemySpawn = true;
	bool slow = false;
	double speed = .45;
	double rangertime = 5;
	int arrow = 3;

	RenderWindow window(VideoMode(1440, 900), "Game Window");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (!Playing) {
				if (event.type == Event::MouseButtonPressed) {
					if (fakeJux.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window))) {
						skin = 1;
						player.setTexture(playerskin);
					}
					if (fakeNiv.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window))) {
						skin = 2;
						player.setTexture(fullarrow);
					}
					if (fakeDel.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window))) {
						skin = 3;
						player.setTexture(throwerDel);
					}
					if (start.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window))) {
						Playing = true;
						switch (skin) {
						case 1:
							player.setPosition(720, 826);
						case 2:
							player.setPosition(720, 821);
						case 3:
							player.setPosition(720, 826);
						}
					}
				}
				if (event.type == Event::Closed) {
					window.close();
				}
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::D) {
					PlayerRight = true;
				}
				if (event.key.code == Keyboard::A) {
					PlayerLeft = true;
				}
				if (event.key.code == Keyboard::Space) {
					Shooting = true;
				}
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::D) {
					PlayerRight = false;
				}
				if (event.key.code == Keyboard::A) {
					PlayerLeft = false;
				}
				if (event.key.code == Keyboard::Space) {
					Shooting = false;
					switch (skin) {
					case 1: 
						player.setTexture(playerskin);
						break;
					case 2:
						player.setTexture(fullarrow);
						break;
					case 3:
						player.setTexture(throwerDel);
						break;
					}
					
				}
			}
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (Playing) {

			window.clear();
			window.draw(background);
			window.draw(player);
			for (PlayerBullet p : projectileVector) {
				window.draw(p.bullet);
			}
			for (Ranger p :rangerVector) {
				window.draw(p.ranger);
			}
			window.draw(top);
			window.draw(border);
			window.display();
		}
		else {
			window.clear();
			window.draw(background);
			window.draw(start);
			window.draw(name);
			window.draw(fakeNiv);
			window.draw(fakeJux);
			window.draw(fakeDel);
			window.display();
		}

		if (PlayerRight and player.getPosition().x < 1332 and skin != 3) {
			player.setPosition((player.getPosition().x + speed), (player.getPosition().y));
		}
		if (PlayerLeft and player.getPosition().x > 50 and skin != 3) {
			player.setPosition((player.getPosition().x - speed), (player.getPosition().y));
		}
		if (PlayerRight and player.getPosition().x < 1282 and skin == 3) {
			player.setPosition((player.getPosition().x + speed), (player.getPosition().y));
		}
		if (PlayerLeft and player.getPosition().x > 15 and skin == 3) {
			player.setPosition((player.getPosition().x - speed), (player.getPosition().y));
		}

		if (Shooting) {
			slow = true;
			switch (skin) {
			case 1:
				player.setTexture(playershoot);
				if ((clock.getElapsedTime().asSeconds() >= .075 and ShotSkin == true)) {
					ShotSkin = false;
					clock.restart();
				}
				else if ((clock.getElapsedTime().asSeconds() >= .075 and ShotSkin == false)) {
					ShotSkin = true;
					PlayerBullet projectile(Vector2f(player.getPosition().x + 29.5, player.getPosition().y - 80), skin);
					projectileVector.push_back(projectile);
					clock.restart();
				}
				break;
			case 2:
				player.setTexture(fullarrow);
				if ((clock.getElapsedTime().asSeconds() >= .065 and arrow == 1)) {
					arrow = 2;
					clock.restart();
				}
				else if ((clock.getElapsedTime().asSeconds() >= .065 and arrow == 2)) {
					arrow = 3;
					clock.restart();
				}
				else if ((clock.getElapsedTime().asSeconds() >= .065 and arrow == 3)) {
					arrow = 1;
					PlayerBullet projectile(Vector2f(player.getPosition().x + 30, player.getPosition().y - 72), skin);
					projectileVector.push_back(projectile);
					clock.restart();
				}
				break;
			case 3:
				player.setTexture(throwerDel);
				if ((clock.getElapsedTime().asSeconds() >= .075 and Yeeter == true)) {
					Yeeter = false;
					PlayerBullet projectile(Vector2f(player.getPosition().x + 75, player.getPosition().y - 20), skin);
					projectileVector.push_back(projectile);
					clock.restart();
				}
				else if ((clock.getElapsedTime().asSeconds() >= .075 and Yeeter == false)) {
					Yeeter = true;
					clock.restart();
				}
				break;
			}
		}

		else if (!Shooting) {
			player.setTexture(playerskin);
			ShotSkin = false;
			arrow = 3;
			Yeeter = true;
			slow = false;
		}

		if (ShotSkin == false) {
			player.setTexture(playerskin);
		}
		else if (ShotSkin == true) {
			player.setTexture(playershoot);
		}
		if ((clock2.getElapsedTime().asSeconds() >= .5 and NameSize == true)) {
			NameSize = false;
			clock2.restart();
		}
		else if ((clock2.getElapsedTime().asSeconds() >= .5 and NameSize == false)) {
			NameSize = true;
			clock2.restart();
		}
		if (!NameSize) {
			name.setScale(6.45, 6.45);
		}
		else if (NameSize) {
			name.setScale(6.7, 6.7);
		}

		if (arrow == 1 and skin == 2) {
			player.setTexture(halfarrow);
		}
		if (arrow == 2 and skin == 2) {
			player.setTexture(noarrow);
		}
		if (arrow == 3 and skin == 2) {
			player.setTexture(fullarrow);
		}

		if (Yeeter and skin == 3) {
			player.setTexture(throwerDel);
		}
		if (!Yeeter and skin == 3) {
			player.setTexture(yeet);
		}

		for (PlayerBullet &p : projectileVector) {
			p.MoveBullet();
			for (int i = 0; i < rangerVector.size(); i++) {
				if (rangerVector[i].ranger.getGlobalBounds().contains(p.bullet.getPosition())) {
					rangerVector[i].gotHitRip(playerDamage);
					if (rangerVector.[i].rangerHP <= 0) {
						rangerVector.erase(rangerVector.begin() + i);
					}
				}
			}
		}
		
		for (int i = 0; i < projectileVector.size(); i++) {
			if (projectileVector[i].bullet.getPosition().y < 75) {
				delete projectileVector[i].bulletskin;
				projectileVector.erase(projectileVector.begin() + i);
			}
		}
		if (EnemySpawn) {
			if (enemy.getElapsedTime().asSeconds() >= rangertime) {
				Ranger ranger(Vector2f((rangerx() %1290) + 75, 0), rangerHealth);
				rangerVector.push_back(ranger);
				enemy.restart();
			}
		}
		if (decreasetime.getElapsedTime().asSeconds() >= 60 - decreasethedecrease and rangertime > 1) {
			decreasethedecrease += .5;
			rangertime -= .05;
			decreasetime.restart();
		}
		if (rangerHealthBoost.getElapsedTime().asSeconds() >= 40) {
			rangerHealth += 20;
			rangerHealthBoost.restart();
		}

		if (slow) {
			speed = .3;
		}
		else if (!slow) {
			speed = .6;
		}

		for (Ranger &p : rangerVector) {
			p.moveRanger();
		}
	}
}