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
	player.setPosition(346.5, 835);
	player.setScale(1.75, 1.75);
	int shootingskinstuff;
	shootingskinstuff = 1;

	// The Background
	Sprite background;
	Texture backgroundskin;
	backgroundskin.loadFromFile("background.png");
	background.setTexture(backgroundskin);
	background.setOrigin(11, 0);
	background.setScale(9, 9);
	Sprite border;
	Texture borderskin;
	borderskin.loadFromFile("bordrz.png");
	border.setTexture(borderskin);
	border.setOrigin(11, 0);
	border.setScale(9, 9);

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
	name.setPosition(346.5, 263.55);
	Sprite start;
	Texture startbutton;
	startbutton.loadFromFile("start.png");
	start.setTexture(startbutton);
	start.setPosition(346.5, 458.5);
	start.setScale(6.5, 6.5);
	start.setOrigin(50, 50);

	// Shooting Stuff
	Clock clock;
	Clock clock2;
	vector<PlayerBullet> projectileVector;

	// Movement
	bool PlayerLeft = false;
	bool PlayerRight = false;
	bool Shooting = false;
	bool Playing = false;
	bool ShotSkin = false;
	bool NameSize = false;

	RenderWindow window(VideoMode(693, 900), "Game Window");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (!Playing) {
				if (event.type == Event::MouseButtonPressed) {
					if (start.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window))) {
						Playing = true;
						player.setPosition(346.5, 835);
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
					player.setTexture(playerskin);
				}
			}
			if (event.type == Event::Closed) {
				window.close();
			}
			
		// PlayerBullet abullet(Vector2f((player.getPosition().x + 5), (player.getPosition().y - 10)));
		// BulletVector.push_back(abullet);

		}

		if (Playing) {

			window.clear();
			window.draw(background);
			window.draw(player);
			window.draw(border);

			for (PlayerBullet p : projectileVector) {
				window.draw(p.bullet);
			}

			window.display();

		}
		else {
			window.clear();
			window.draw(background);
			window.draw(start);
			window.draw(name);
			window.display();
		}


		if (PlayerRight and player.getPosition().x < 593) {
			player.setPosition((player.getPosition().x + .2), (player.getPosition().y));
		}
		if (PlayerLeft and player.getPosition().x > 50) {
			player.setPosition((player.getPosition().x - .2), (player.getPosition().y));
		}

		if (Shooting) {
			player.setTexture(playershoot);
			if ((clock.getElapsedTime().asSeconds() >= .075 and ShotSkin == true)) {
				ShotSkin = false;
				clock.restart();
			}
			else if ((clock.getElapsedTime().asSeconds() >= .075 and ShotSkin == false)) {
				ShotSkin = true;
				PlayerBullet projectile(Vector2f(player.getPosition().x + 28, player.getPosition().y - 80));
				projectileVector.push_back(projectile);
				clock.restart();
			}
		}

		else if (!Shooting) {
			player.setTexture(playerskin);
			ShotSkin = false;
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
			name.setScale(6.6, 6.6);
		}
		else if (NameSize) {
			name.setScale(6.85, 6.85);
		}


		for (PlayerBullet &p : projectileVector) {
			p.MoveBullet();
		}
		
		for (int i = 0; i < projectileVector.size(); i++) {
			if (projectileVector[i].bullet.getPosition().y < -16) {
				projectileVector.erase(projectileVector.begin() + i);
			}
		}

	}
}

// Clock bullettimet;
// if (bullettimet.getElapsedTime[asSeconds] > 2) {


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
