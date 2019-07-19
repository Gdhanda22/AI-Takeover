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
	Texture playerskin; // lihjiuh
	Texture playershoot;
	playershoot.loadFromFile("shot.png");
	playerskin.loadFromFile("player.png");
	player.setTexture(playerskin);
 	player.setOrigin(50, 50);
 	player.setPosition(346.5, 835);
 	player.setScale(1.6, 1.6);

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
	aitakeover.loadFromFile("name.png");
	name.setTexture(aitakeover);
	name.setPosition(346.5, 200);
	name.setOrigin(45.5, 7);
	name.setScale(5.5, 5.5);

	// Movement
	bool PlayerLeft = false;
	bool PlayerRight = false;
	bool Shooting = false;
	bool Playing = false;

	RenderWindow window(VideoMode(693, 900), "Game Window");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			while (Playing) {
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
				}
			}
		}
		
		if (PlayerRight and player.getPosition().x < 593) {
			player.setPosition((player.getPosition().x + .2), (player.getPosition().y));
		}
		if (PlayerLeft and player.getPosition().x > 100) {
			player.setPosition((player.getPosition().x - .2), (player.getPosition().y));
		}
		if (Shooting) {
			player.setTexture(playershoot);
		}
		else {
			player.setTexture(playerskin);
		}

		window.clear();
		window.draw(background);
		window.draw(player);
		window.draw(name);
		window.display();
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
