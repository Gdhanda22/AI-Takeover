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

	//Pounder Stuff
	sf::Sprite pounder;
	sf::Texture pounderskin;
	pounderskin.loadFromFile("pounder.png");
	pounder.setTexture(pounderskin);
	pounder.setPosition(200, 200);
	pounder.setScale(1.75, 1.75);

	// Start Screen Stuff
	Sprite name;
	Texture aitakeover;
	aitakeover.loadFromFile(".png");
	name.setTexture(aitakeover);
	name.setPosition(346.5, 200);
	name.setOrigin(45.5, 7);
	name.setScale(6, 6);
	Sprite description;
	Texture defendcastle;
	defendcastle.loadFromFile("name.png");
	description.setTexture(defendcastle);
	description.setOrigin(50, 50);
	description.setScale(6.5, 6.5);
	description.setPosition(346.5, 263.55);
	Sprite start;
	Texture startbutton;
	startbutton.loadFromFile("start.png");
	start.setTexture(startbutton);
	start.setPosition(346.5, 458.5);
	start.setScale(6.5, 6.5);
	start.setOrigin(50, 50);

	// Shooting Stuff
	vector<PlayerBullet> BulletVector;
	Clock clock;
	Clock clock2;

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
			window.display();
		}
		else {
			if ((clock2.getElapsedTime().asSeconds() >= .6 and NameSize == true)) {
				NameSize = false;
				clock2.restart();
			}
			else if ((clock2.getElapsedTime().asSeconds() >= .6 and NameSize == false)) {
				NameSize = true;
				clock2.restart();
			}
			window.clear();
			window.draw(background);
			window.draw(name);
			window.draw(start);
			window.draw(description);
			window.display();
		}


		if (PlayerRight and player.getPosition().x < 593) {
			player.setPosition((player.getPosition().x + .2), (player.getPosition().y));
		}
		if (PlayerLeft and player.getPosition().x > 100) {
			player.setPosition((player.getPosition().x - .2), (player.getPosition().y));
		}
		if (Shooting) {
			player.setTexture(playershoot);
			if ((clock.getElapsedTime().asSeconds() >= .089 and ShotSkin == true)) {
				ShotSkin = false;
				clock.restart();
			}
			else if ((clock.getElapsedTime().asSeconds() >= .089 and ShotSkin == false)) {
				ShotSkin = true;
				clock.restart();
			}
		}
		else if (!Shooting) {
			player.setTexture(playerskin);
			ShotSkin = false;
		}
		for (int i = 0; i < BulletVector.size(); i++) {
			BulletVector[i].MoveBullet();
			window.draw(BulletVector[i].bullet);
		}
		if (ShotSkin == false) {
			player.setTexture(playerskin);
		}
		else if (ShotSkin == true) {
			player.setTexture(playershoot);
		}
		if (!NameSize) {
			description.setScale(6.5, 6.5);
		}
		else if (NameSize) {
			description.setScale(6.8, 6.8);
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
