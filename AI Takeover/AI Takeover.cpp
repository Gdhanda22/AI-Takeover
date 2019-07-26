// AI Takeover.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Pounder.h"
#include "Ranger.h"
#include "RangerBullet.h"
#include "PlayerBullet.h"
#include "Boss.h"
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
	double playerDamage = 50;

	//High Score
	Font font;
	font.loadFromFile("foont.ttf");
	fstream HighScoreFile;
	string filename = "HighScoreFile.txt";
	int HighScore;
	Text YourScore;
	Text HighScoreText;
	YourScore.setFont(font);
	HighScoreText.setFont(font);
	YourScore.setFillColor(Color::Black);
	HighScoreText.setFillColor(Color::Black);
	HighScoreText.setScale(2, 2);
	YourScore.setScale(2, 2);
	HighScoreText.setPosition(350, 645);
	YourScore.setPosition(350, 555);

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

	// Start Screen Stuff
	Sprite name;
	Texture nameskin;
	nameskin.loadFromFile("name.png");
	name.setTexture(nameskin);
	name.setOrigin(50, 50);
	name.setScale(6.5, 6.5);
	name.setPosition(720,250);
	Sprite start;
	Texture startbutton;
	startbutton.loadFromFile("start.png");
	start.setTexture(startbutton);
	start.setPosition(720, 450);
	start.setScale(5.95, 5.95);
	start.setOrigin(28.5, 13.5);

	// Ranger Spawning Timers and Stuff
	Clock decreasetime;
	double decreasethedecrease = 0;
	Clock rangerHealthBoost;
	int rangerHealth = 350;
	vector<RangerBullet> rangerbulletVector;

	// Score Stuff
	int score = 0;
	Text scoretext;
	scoretext.setFont(font);
	scoretext.setScale(1.3, 1.3);
	scoretext.setPosition(530, 26);
	scoretext.setFillColor(Color(80, 80, 80));
	Clock scorepersecond;
	Clock increasesps;
	int sps = 5;
	int scoreperranger = 50;

	// Tower Health Stuff
	Sprite heart;
	Texture heartSkin;
	heartSkin.loadFromFile("Heart.png");
	heart.setTexture(heartSkin);
	heart.setOrigin(17, 16.5);
	heart.setScale(1, 1);
	heart.setPosition(115, 48.5);
	int towerHealth = 10000;
	Text health;
	health.setFont(font);
	health.setFillColor(Color(80, 80, 80));
	health.setScale(1.3, 1.3);
	health.setPosition(140, 26);
	health.setString(to_string(towerHealth));

	//Money Stuff
	int money = 250;
	Text moneytext;
	moneytext.setFont(font);
	moneytext.setFillColor(Color(80, 80, 80));
	moneytext.setScale(1.3, 1.3);
	moneytext.setPosition(365, 26);
	moneytext.setString(to_string(money));
	int moneyperranger = 25;
	Sprite dollar;
	Texture dollarSkin;
	dollarSkin.loadFromFile("dollar.png");
	dollar.setTexture(dollarSkin);
	dollar.setOrigin(15.5, 15.5);
	dollar.setScale(1.4, 1.4);
	dollar.setPosition(335, 48.5);

	// Shooting Stuff
	Clock clock;
	Clock clock2;
	Clock enemy;
	vector<PlayerBullet> projectileVector;
	vector<Ranger> rangerVector;
	random_device rangerx;
	int bulletToKill;
	bool killBullet = false;
	int rangerDamage = 40;

	//Pounder Stuff
	vector<Pounder> pounderVector;
	Clock pounderspawn;
	Clock pounderspawnTime;
	int pounderHealth = 2500;
	int pounderTime = 25;
	double decreasePounderDecrease = 0;
	int pounderDamage = 200;
	int pounderCoins = 100;
	int pounderPoints = 350;
	bool hitTower = false;

	//Game Over
	Sprite gameovertext;
	Texture gameovertext2;
	gameovertext2.loadFromFile("gameover.png");
	gameovertext.setTexture(gameovertext2);
	gameovertext.setPosition(720, 250);
	gameovertext.setOrigin(37, 5);
	gameovertext.setScale(13, 13);
	Sprite tint;
	Texture tintTexture;
	tintTexture.loadFromFile("tint.png");
	tint.setTexture(tintTexture);
	tint.setOrigin(16, 16);
	tint.setPosition(720, 450);
	tint.setScale(50, 50);
	Clock gameOverMove;

	// Upgrade Buttons
	Sprite repairbuttonSprite;
	Texture repairbuttonTexture;
	Sprite attackbuttonSprite;
	Texture attackbuttonTexture;
	Sprite multiplierSprite;
	Texture multiplierTexture;
	repairbuttonTexture.loadFromFile("RepairWall.png");
	attackbuttonTexture.loadFromFile("AttackBoost.png");
	multiplierTexture.loadFromFile("multiplier.png");
	repairbuttonSprite.setTexture(repairbuttonTexture);
	attackbuttonSprite.setTexture(attackbuttonTexture);
	multiplierSprite.setTexture(multiplierTexture);
	repairbuttonSprite.setScale(1.9, 1.9);
	attackbuttonSprite.setScale(1.9, 1.9);
	multiplierSprite.setScale(1.9, 1.9);
	repairbuttonSprite.setPosition(1135, 20);
	attackbuttonSprite.setPosition(1280, 20);
	multiplierSprite.setPosition(938, 20);
	Clock waittime; 
	Clock waittime2;
	Clock waittime3;
	int scoremultiplier = 1;

	// Movement and other stuuf
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
	double rangertime = 4;
	int arrow = 3;
	bool ALIVE = true;



	// THE BOSS BOI STUFF
	int bossCoins = 500;
	int bossHealth = 5000;
	int bossPoints = 1000;
	int bossDamage = 1;
	Clock bossSpawn;
	vector<Boss> bossVector;






	RenderWindow window(VideoMode(1440, 900), "Game Window");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			
				if (!Playing and ALIVE) {
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
							scorepersecond.restart();
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
							player.setPosition(player.getPosition().x, (player.getPosition().y - 10));
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
			if (ALIVE == false) {
				HighScoreFile.open("HighScoreFile.txt", ios::in);
				HighScoreFile >> HighScore;
					if (score > HighScore) {
						HighScore = score;
					}
					HighScoreFile.close();
					HighScoreFile.open("HighScoreFile.txt", ios::out);
				HighScoreFile << HighScore;
				HighScoreFile.close();
			}
			if (Playing and scorepersecond.getElapsedTime().asSeconds() > .5 and ALIVE) {
				score += (sps * scoremultiplier);
				scorepersecond.restart();
			}
			if (Playing and increasesps.getElapsedTime().asSeconds() > 120) {
				sps += 5;
				increasesps.restart();
			}
			scoretext.setString("Score  " + to_string(score));
			health.setString(to_string(towerHealth));
			moneytext.setString(to_string(money));

			if (Playing and ALIVE) {

				window.clear();
				window.draw(background);
				for (PlayerBullet p : projectileVector) {
					window.draw(p.bullet);
				}
				for (Pounder p : pounderVector) {
					window.draw(p.pounder);
				}
				for (RangerBullet p : rangerbulletVector) {
					window.draw(p.cannonball);
				}
				for (Ranger p : rangerVector) {
					window.draw(p.ranger);
				}
				for (Boss p : bossVector) {
					window.draw(p.boss);
				}
				window.draw(player);
				window.draw(top);
				window.draw(health);
				window.draw(heart);
				window.draw(dollar);
				window.draw(scoretext);
				window.draw(moneytext);
				window.draw(repairbuttonSprite);
				window.draw(attackbuttonSprite);
				window.draw(multiplierSprite);
				window.draw(border);
				window.display();
			}
			else if (!Playing and ALIVE) {
				window.clear();
				window.draw(background);
				window.draw(start);
				window.draw(name);
				window.draw(fakeNiv);
				window.draw(fakeJux);
				window.draw(fakeDel);
				window.display();
			}
			else if (ALIVE == false) {
				if (player.getPosition().x > 720) {
					player.move(-.1, 0);
				}
				else if (player.getPosition().x < 720) {
					player.move(.1, 0);
				}
				YourScore.setString("Your Score  " + to_string(score));
				HighScoreText.setString("High Score  " + to_string(HighScore));
				window.clear();
				window.draw(background);
				for (PlayerBullet p : projectileVector) {
					window.draw(p.bullet);
				}
				for (RangerBullet p : rangerbulletVector) {
					window.draw(p.cannonball);
				}
				window.draw(player);
				window.draw(top);
				window.draw(health);
				window.draw(heart);
				window.draw(dollar);
				window.draw(scoretext);
				window.draw(moneytext);
				window.draw(repairbuttonSprite);
				window.draw(attackbuttonSprite);
				window.draw(multiplierSprite);
				window.draw(border);
				window.draw(tint);
				window.draw(gameovertext);
				window.draw(YourScore);
				window.draw(HighScoreText);
				window.display();
			}

			if (PlayerRight and player.getPosition().x < 1332 and skin != 3 and ALIVE) {
				player.setPosition((player.getPosition().x + speed), (player.getPosition().y));
			}
			if (PlayerLeft and player.getPosition().x > 50 and skin != 3 and ALIVE) {
				player.setPosition((player.getPosition().x - speed), (player.getPosition().y));
			}
			if (PlayerRight and player.getPosition().x < 1282 and skin == 3 and ALIVE) {
				player.setPosition((player.getPosition().x + speed), (player.getPosition().y));
			}
			if (PlayerLeft and player.getPosition().x > 15 and skin == 3 and ALIVE) {
				player.setPosition((player.getPosition().x - speed), (player.getPosition().y));
			}

			if (Shooting and ALIVE) {
				slow = true;
				switch (skin) {
				case 1:
					player.setTexture(playershoot);
					if ((clock.getElapsedTime().asSeconds() >= .065 and ShotSkin == true)) {
						ShotSkin = false;
						clock.restart();
					}
					else if ((clock.getElapsedTime().asSeconds() >= .065 and ShotSkin == false)) {
						ShotSkin = true;
						PlayerBullet projectile(Vector2f(player.getPosition().x + 30, player.getPosition().y - 75), skin);
						projectileVector.push_back(projectile);
						clock.restart();
					}
					break;
				case 2:
					player.setTexture(fullarrow);
					if ((clock.getElapsedTime().asSeconds() >= .043 and arrow == 1)) {
						arrow = 2;
						clock.restart();
					}
					else if ((clock.getElapsedTime().asSeconds() >= .043 and arrow == 2)) {
						arrow = 3;
						clock.restart();
					}
					else if ((clock.getElapsedTime().asSeconds() >= .043 and arrow == 3)) {
						arrow = 1;
						PlayerBullet projectile(Vector2f(player.getPosition().x + 42, player.getPosition().y - 55), skin);
						projectileVector.push_back(projectile);
						clock.restart();
					}
					break;
				case 3:
					player.setTexture(throwerDel);
					if ((clock.getElapsedTime().asSeconds() >= .065 and Yeeter == true)) {
						Yeeter = false;
						PlayerBullet projectile(Vector2f(player.getPosition().x + 75, player.getPosition().y - 20), skin);
						projectileVector.push_back(projectile);
						clock.restart();
					}
					else if ((clock.getElapsedTime().asSeconds() >= .065 and Yeeter == false)) {
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

			for (int j = 0; j < projectileVector.size(); j++) {
				projectileVector[j].MoveBullet();
				for (int i = 0; i < rangerVector.size(); i++) {
					if (rangerVector[i].ranger.getGlobalBounds().contains(projectileVector[j].bullet.getPosition())) {
						rangerVector[i].gotHitRip(playerDamage);
						bulletToKill = j;
						killBullet = true;
						if (rangerVector[i].rangertexture == 1 and rangerVector[i].rangerHP <= 0) {
							rangerVector[i].Explodey();
							rangerVector[i].rangerExplodeClock.restart();
						}
					}	
				}
				for (int r = 0; r < pounderVector.size(); r++) {
					if (pounderVector[r].pounder.getGlobalBounds().contains(projectileVector[j].bullet.getPosition())) {
						pounderVector[r].gotYotRip(playerDamage);
						bulletToKill = j;
						killBullet = true;
						if (pounderVector[r].poundertexture == 1 and pounderVector[r].pounderHP <= 0) {
							pounderVector[r].Explode();
							pounderVector[r].pounderExplodeClock.restart();
						}
					}
				}
			}
			for (int r = 0; r < pounderVector.size(); r++) {
				if (pounderVector[r].poundertexture == 2 and pounderVector[r].pounderExplodeClock.getElapsedTime().asSeconds() > .1) {
					pounderVector.erase(pounderVector.begin() + r);
					score += (pounderPoints * scoremultiplier);
					money += pounderCoins;
				}
			}
			for (int i = 0; i < rangerVector.size(); i++) {
				if (rangerVector[i].rangertexture == 2 and rangerVector[i].rangerHP <= 0 and rangerVector[i].rangerExplodeClock.getElapsedTime().asSeconds() > .1) {
					rangerVector.erase(rangerVector.begin() + i);
					score += (scoreperranger * scoremultiplier);
					money += moneyperranger;
				}
			}

			if (killBullet) {
				projectileVector.erase(projectileVector.begin() + bulletToKill);
				killBullet = false;
			}

			for (int i = 0; i < projectileVector.size(); i++) {
				if (projectileVector[i].bullet.getPosition().y < 75) {
					delete projectileVector[i].bulletskin;
					projectileVector.erase(projectileVector.begin() + i);
				}
			}
			if (EnemySpawn and Playing) {
				if (enemy.getElapsedTime().asSeconds() >= rangertime) {
					Ranger ranger(Vector2f((rangerx() % 1290) + 75, 0), rangerHealth);
					rangerVector.push_back(ranger);
					enemy.restart();
				}
				if (pounderspawn.getElapsedTime().asSeconds() >= pounderTime) {
					Pounder pounder(Vector2f((rangerx() % 1290) + 75, 0), pounderHealth);
					pounderVector.push_back(pounder);
					pounderspawn.restart();
				}
				if (bossSpawn.getElapsedTime().asSeconds() >= 180) {
					Boss boss(bossHealth, Vector2f(720, -20));
					bossVector.push_back(boss);
					bossSpawn.restart();
				}
			}
			if (decreasetime.getElapsedTime().asSeconds() >= 60 - decreasethedecrease and rangertime > .5) {
				decreasethedecrease += .5;
				rangertime -= .05;
				decreasetime.restart();
			}
			if (rangerHealthBoost.getElapsedTime().asSeconds() >= 60) {
				rangerHealth += 150;
				rangerDamage *= 1.15;
				moneyperranger += 25;
				scoreperranger += 50;
				pounderHealth += 500;
				pounderDamage *= 1.15;
				pounderPoints += 350;
				pounderCoins += 50;
				rangerHealthBoost.restart();
			}
			if (pounderspawnTime.getElapsedTime().asSeconds() >= 60 - decreasethedecrease and pounderTime > 5) {
				decreasePounderDecrease += .5;
				pounderTime -= .05;
				pounderspawnTime.restart();
			}

			if (slow) {
				speed = .3;
			}
			else if (!slow) {
				speed = .8;
			}
			for (Ranger &p : rangerVector) {
				if (ALIVE) {
					p.moveRanger();
					if (p.ranger.getPosition().y >= 373) {
						if (p.shotclock.getElapsedTime().asSeconds() >= 1.5) {
							RangerBullet cannonball(Vector2f(p.ranger.getPosition().x, p.ranger.getPosition().y + 30));
							rangerbulletVector.push_back(cannonball);
							p.shotclock.restart();
						}
					}
				}
			}
			for (RangerBullet &p : rangerbulletVector) {
				p.MoveCannonball();
			}
			for (int i = 0; i < rangerbulletVector.size(); i++) {
				if (rangerbulletVector[i].cannonball.getPosition().y >= 783) {
					if (rangerbulletVector[i].cannonballtexture == 1) {
						rangerbulletVector[i].Wait();
						rangerbulletVector[i].explosionclock.restart();
						towerHealth -= rangerDamage;
					}
					else if (rangerbulletVector[i].cannonballtexture == 2 and rangerbulletVector[i].explosionclock.getElapsedTime().asSeconds() > .075) {
						delete rangerbulletVector[i].cannonballskin;
						delete rangerbulletVector[i].explosion;
						rangerbulletVector.erase(rangerbulletVector.begin() + i);
					}
				}
			}
			if (towerHealth > 20000) {
				towerHealth = 20000;
			}
			if (towerHealth < 0) {
				towerHealth = 0;
			}
			if (money > 2500) {
				money = 2500;
			}
			if (money < 0) {
				money = 0;
			}
			if (Playing and event.type == Event::MouseButtonPressed and ALIVE) {
				if (attackbuttonSprite.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window)) and waittime.getElapsedTime().asSeconds() > .15) {
					if (money >= 500) {
						money -= 500;
						playerDamage *= 1.075;
						waittime.restart();
					}
				}
				if (repairbuttonSprite.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window)) and waittime2.getElapsedTime().asSeconds() > .15) {
					if (money >= 500) {
						money -= 500;
						towerHealth += 1000;
						waittime2.restart();
					}
				}
				if (multiplierSprite.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window)) and waittime3.getElapsedTime().asSeconds() > .15) {
					if (money >= 1000) {
						money -= 1000;
						scoremultiplier += 1;
						waittime3.restart();
					}
				}
			}
			for (Pounder &p : pounderVector) {
				if (ALIVE) {
					p.movePounder();
				}
			}

			for (Pounder &p : pounderVector) {
				if (p.atLocation == 1) {
					p.firstDamage.restart();
					if (p.pounder.getPosition().y >= 716) {
						p.atLocation = 2;
					}
					
				}
				if (p.atLocation == 2) {
					if (p.firstDamage.getElapsedTime().asSeconds() > .15)
						towerHealth -= pounderDamage;
					p.firstDamage.restart();
					p.doDamage.restart();
					p.atLocation = 3;
				}
				if (p.atLocation == 3) {
					if (p.doDamage.getElapsedTime().asSeconds() > .8) {
						towerHealth -= pounderDamage;
						p.doDamage.restart();
					}
				}
			}
			
			if (towerHealth <= 0) {
				ALIVE = false;
				towerHealth = 0;
			}
			for (Boss &p : bossVector) {
				p.moveBoss();
			}
		}
	}