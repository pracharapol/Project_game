#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include<SFML/Audio.hpp>
#include<time.h>
int main() {
	int score = 0;
	int level = 1;
	int heart = 5;
	int Bomb = 0;
	int hit = 0;
	int hit2 = 0;
	sf::RenderWindow myWindow(sf::VideoMode(1024, 720), "My Game");
	//Font
	char s[] = "Score : ";
	sf::Font myFont;
	myFont.loadFromFile("CENTURY.ttf");
	
	sf::Text myText;
	myText.setFont(myFont);
	myText.setFillColor(sf::Color::Green);
	myText.setCharacterSize(20);
	
	char l[] = "Level : ";
	sf::Font myFont1;
	myFont1.loadFromFile("CENTURY.ttf");

	sf::Text myText1;
	myText1.setFont(myFont1);
	myText1.setFillColor(sf::Color::Cyan);
	myText1.setCharacterSize(20);

	char h[] = "Heart : ";
	sf::Font myFont2;
	myFont2.loadFromFile("CENTURY.ttf");

	sf::Text myText2;
	myText2.setFont(myFont2);
	myText2.setFillColor(sf::Color::Red);
	myText2.setCharacterSize(20);

	char b[] = "Bomb : ";
	sf::Font myFont3;
	myFont3.loadFromFile("CENTURY.ttf");

	sf::Text myText3;
	myText3.setFont(myFont3);
	myText3.setFillColor(sf::Color::Red);
	myText3.setCharacterSize(20);
	
	
	
	
	//////sound background
	sf::SoundBuffer myBuffer;
	myBuffer.loadFromFile("sound01.wav");
	sf::Sound backgroundSound;
	backgroundSound.setBuffer(myBuffer);
	backgroundSound.play();
	backgroundSound.setLoop(true);
	backgroundSound.setVolume(2);
	//////sound hit
	sf::SoundBuffer myBuffer1;
	myBuffer1.loadFromFile("hitsound.wav");
	sf::Sound hitsound;
	hitsound.setBuffer(myBuffer1);
	
	
	
	//Background
	sf::Texture myBackground;
	myBackground.loadFromFile("galaxy.png");

	sf::Sprite myBg;
	myBg.setTexture(myBackground);
	myBg.setPosition(-200, -1200);
	myBg.setScale(2, 2);

	//Ship
	sf::Texture myShipTex;
	myShipTex.loadFromFile("shipsprite.png");

	sf::Sprite myShip;
	myShip.setTexture(myShipTex);
	myShip.setPosition(200, 500);
	myShip.setScale(2.5, 2.5);

	int spritesizeX = myShipTex.getSize().x / 3;
	int spritesizeY = myShipTex.getSize().y / 8;

	myShip.setTextureRect(sf::IntRect(0, 0, spritesizeX, spritesizeY));
	//rock
	sf::Texture myRockTex;
	myRockTex.loadFromFile("rock.png");

	sf::Sprite myRock;
	myRock.setTexture(myRockTex);
	myRock.setScale(0.6, 0.6);

	int spritesizeRockX = myRockTex.getSize().x / 8;
	int spritesizeRockY = myRockTex.getSize().y / 8;

	myRock.setTextureRect(sf::IntRect(0, 0, spritesizeRockX, spritesizeRockY));
	//rock 2
	sf::Texture myRockTex2;
	myRockTex2.loadFromFile("rock.png");

	sf::Sprite myRock2;
	myRock2.setTexture(myRockTex2);
	myRock2.setScale(0.7, 0.7);

	int spritesizeRockX2 = myRockTex2.getSize().x / 8;
	int spritesizeRockY2 = myRockTex2.getSize().y / 8;

	myRock2.setTextureRect(sf::IntRect(spritesizeRockX2*3, spritesizeRockY2*5, spritesizeRockX2, spritesizeRockY2));
	//rock 3
	sf::Texture myRockTex3;
	myRockTex3.loadFromFile("rock.png");

	sf::Sprite myRock3;
	myRock3.setTexture(myRockTex3);
	myRock3.setScale(0.7, 0.7);

	int spritesizeRockX3 = myRockTex3.getSize().x / 8;
	int spritesizeRockY3 = myRockTex3.getSize().y / 8;

	myRock3.setTextureRect(sf::IntRect(spritesizeRockX3*2, spritesizeRockY3*6, spritesizeRockX3, spritesizeRockY3));
	
	//rock 4
	sf::Texture myRockTex4;
	myRockTex4.loadFromFile("rock.png");

	sf::Sprite myRock4;
	myRock4.setTexture(myRockTex4);
	myRock4.setScale(0.8, 0.8);

	int spritesizeRockX4 = myRockTex4.getSize().x / 8;
	int spritesizeRockY4 = myRockTex4.getSize().y / 8;

	myRock4.setTextureRect(sf::IntRect(0, 0, spritesizeRockX4, spritesizeRockY4));
	
	//rock 5
	sf::Texture myRockTex5;
	myRockTex5.loadFromFile("rock.png");

	sf::Sprite myRock5;
	myRock5.setTexture(myRockTex5);
	myRock5.setScale(0.7, 0.8);

	int spritesizeRockX5 = myRockTex5.getSize().x / 8;
	int spritesizeRockY5 = myRockTex5.getSize().y / 8;

	myRock5.setTextureRect(sf::IntRect(0, 0, spritesizeRockX5, spritesizeRockY5));

	//rock 6
	sf::Texture myRockTex6;
	myRockTex6.loadFromFile("rock.png");

	sf::Sprite myRock6;
	myRock6.setTexture(myRockTex6);
	myRock6.setScale(2, 2);

	int spritesizeRockX6 = myRockTex6.getSize().x / 8;
	int spritesizeRockY6 = myRockTex6.getSize().y / 8;

	myRock6.setTextureRect(sf::IntRect(0, 0, spritesizeRockX6, spritesizeRockY6));

	//heart
	sf::Texture myHeartTex;
	myHeartTex.loadFromFile("heart.png");

	sf::Sprite myHeart;
	myHeart.setTexture(myHeartTex);
	myHeart.setScale(0.01, 0.01);

	int spritesizeHeartX = myHeartTex.getSize().x / 1;
	int spritesizeHeartY = myHeartTex.getSize().y / 1;

	myHeart.setTextureRect(sf::IntRect(0, 0, spritesizeHeartX, spritesizeHeartY));

	//Bomb item
	
	sf::Texture myBombTex1;
	myBombTex1.loadFromFile("bomb.png");

	sf::Sprite myBomb1;
	myBomb1.setTexture(myBombTex1);
	myBomb1.setScale(0.25, 0.25);

	int spritesizeBombX1 = myBombTex1.getSize().x / 1;
	int spritesizeBombY1 = myBombTex1.getSize().y / 1;

	myBomb1.setTextureRect(sf::IntRect(0, 0, spritesizeBombX1, spritesizeBombY1));
	myBomb1.setPosition(500, -3000);

	//bullet
	sf::Texture myBulletTex;
	myBulletTex.loadFromFile("bullet.png");

	sf::Sprite myBullet;
	myBullet.setTexture(myBulletTex);
	myBullet.setScale(0.1, 0.1);

	int spritesizeBulletX = myBulletTex.getSize().x / 1;
	int spritesizeBulletY = myBulletTex.getSize().y / 1;

	myBullet.setTextureRect(sf::IntRect(0, 0, spritesizeBulletX, spritesizeBulletY));
	myBullet.setPosition(-1000, -2000);
	//bomb
	sf::Texture myBombTex;
	myBombTex.loadFromFile("bomb.png");

	sf::Sprite myBomb;
	myBomb.setTexture(myBombTex);
	myBomb.setScale(0.25, 0.25);

	int spritesizeBombX = myBombTex.getSize().x / 1;
	int spritesizeBombY = myBombTex.getSize().y / 1;

	myBomb.setTextureRect(sf::IntRect(0, 0, spritesizeBombX, spritesizeBombY));
	myBomb.setPosition(-1000, -2000);
	int animationFrame = 0;

	float Xbullet = 0.0f, Ybullet = 0.0f;
	//random ROCK
	
		myRock.setPosition(500, -100);
		myRock6.setPosition(550, -800);
		myRock2.setPosition(700, -100);
		myRock3.setPosition(600, -100);
		myRock4.setPosition(400, -100);
		myRock5.setPosition(800, -100);
		
		myHeart.setPosition(400, -100);
	//Boom
	sf::Texture myBoomTex;
	myBoomTex.loadFromFile("boom.png");

	sf::Sprite myBoom;
	myBoom.setTexture(myBoomTex);
	myBoom.setScale(0.02, 0.02);

	int spritesizeBoomX = myBoomTex.getSize().x / 1;
	int spritesizeBoomY = myBoomTex.getSize().y / 1;

	myBoom.setTextureRect(sf::IntRect(0, 0, spritesizeBoomX, spritesizeBoomY));
	myBoom.setPosition(-1000, -2000);
	//WHILE LOOPPPPP_________________________________________________________
	while (true) {
		myWindow.draw(myBg);
		srand(time(NULL));
		int ranX = rand() % 10;

		int ranY = rand() % 10;

		int ranRockX = 600, ranRockY = -100;//YYYY
		
		int ranX2 = rand() % 10;

		int ranRockX2 = 500;
			
		int ranX3 = rand() % 10;

		int ranRockX3 = 400;
		
		int ranX4 = rand() % 10;

		int ranRockX4 = 300;
		
		int ranX5 = rand() % 10;

		int ranRockX5 = 200;

		int ranX6 = rand() % 10;

		int ranRockX6 = 100;

		int ranX7 = rand() % 10;

		int ranRockX7 = 700;

		int heartX = rand() % 10;

		int ranHeartY = -5000;

		int ranHeartX = 500;
		
		int bombX = rand() % 10;

		int ranBombX = 500;
		
		int ranBombY = -4000;	
		//random rock	
			if (ranX < 2) {
				ranRockX = 800;
			}
			else if (ranX < 5 && ranX >= 2) {
				ranRockX = 100;
			}
			else if (ranX < 8 && ranX >= 5) {
				ranRockX = 500;
			}
			if (ranX2 < 2) {
				ranRockX2 = 600;
			}
			else if (ranX2 < 5 && ranX2 >= 2) {
				ranRockX2 = 300;
			}
			else if (ranX2 < 8 && ranX2 >= 5) {
				ranRockX2 = 900;
			}
			if (ranX3 < 2) {
				ranRockX3 = 200;
			}
			else if (ranX3 < 5 && ranX2 >= 2) {
				ranRockX3 = 400;
			}
			else if (ranX3 < 8 && ranX2 >= 5) {
				ranRockX3 = 600;
			}
			if (ranX4 < 2) {
				ranRockX4 = 250;
			}
			else if (ranX4 < 5 && ranX2 >= 2) {
				ranRockX4 = 350;
			}
			else if (ranX4 < 8 && ranX2 >= 5) {
				ranRockX4 = 850;
			}
			if (ranX5 < 2) {
				ranRockX5 = 180;
			}
			else if (ranX5 < 5 && ranX2 >= 2) {
				ranRockX5 = 360;
			}
			else if (ranX5 < 8 && ranX2 >= 5) {
				ranRockX5 = 540;
			}
			if (ranX6 < 2) {
				ranRockX6 = 50;
			}
			else if (ranX6 < 5 && ranX2 >= 2) {
				ranRockX6 = 480;
			}
			else if (ranX6 < 8 && ranX2 >= 5) {
				ranRockX6 = 860;
			}
			if (ranX7 < 2) {
				ranRockX7 = 100;
			}
			else if (ranX7 < 5 && ranX2 >= 2) {
				ranRockX7 = 200;
			}
			else if (ranX7 < 8 && ranX2 >= 5) {
				ranRockX7 = 300;
			}
			//ran heart		
			if (heartX< 2) {
				ranHeartX = 700;
			}
			else if (heartX < 5 && ranX2 >= 2) {
				ranHeartX = 800;
			}
			else if (heartX < 8 && ranX2 >= 5) {
				ranHeartX = 900;
			}
			//ran bomb
			if (bombX < 2) {
				ranBombX = 700;
			}
			else if (bombX < 5 && ranX2 >= 2) {
				ranBombX = 800;
			}
			else if (bombX < 8 && ranX2 >= 5) {
				ranBombX = 900;
			}
			//level run_____________________________________________________________________________
			if (level == 1) {
				myRock.move(0.0f, 0.5f);

				if (myRock.getPosition().y >= 700) {
					myRock.setPosition(ranRockX, ranRockY);
				}
				myRock2.move(0.0f, 0.6f);
				if (myRock2.getPosition().y >= 700) {
					myRock2.setPosition(ranRockX2, ranRockY);
				}
			}			
			//heart
			myHeart.move(0.0f,0.3f);
			if (myHeart.getPosition().y >= 700) {
				myHeart.setPosition(ranHeartX, ranHeartY);
			}
			//bomb
			myBomb1.move(0.0f,0.3f);
			if (myBomb1.getPosition().y >= 700) {
				myBomb1.setPosition(ranBombX, ranBombY);
			}		
			//level 2
			if (level == 2) {
				myRock.move(0.0f, 0.5f);

				if (myRock.getPosition().y >= 700) {
					myRock.setPosition(ranRockX, ranRockY);
				}
				myRock2.move(0.0f, 0.6f);
				if (myRock2.getPosition().y >= 700) {
					myRock2.setPosition(ranRockX2, ranRockY);
				}
				myRock3.move(0.0f, 0.4f);
				if (myRock3.getPosition().y >= 700) {
					myRock3.setPosition(ranRockX3, ranRockY);
				}
				
			}
			//level 3
			if (level == 3) {
				myRock.move(0.0f, 0.5f);

				if (myRock.getPosition().y >= 700) {
					myRock.setPosition(ranRockX, ranRockY);
				}
				myRock2.move(0.0f, 0.6f);
				if (myRock2.getPosition().y >= 700) {
					myRock2.setPosition(ranRockX2, ranRockY);
				}
				myRock3.move(0.0f, 0.4f);
				if (myRock3.getPosition().y >= 700) {
					myRock3.setPosition(ranRockX3, ranRockY);
				}
				myRock4.move(0.0f, 0.35f);
				if (myRock4.getPosition().y >= 700) {
					myRock4.setPosition(ranRockX4, ranRockY);
				}
			}
			//level 4
			if (level == 4) {
				myRock.move(0.0f, 0.5f);

				if (myRock.getPosition().y >= 700) {
					myRock.setPosition(ranRockX, ranRockY);
				}
				myRock2.move(0.0f, 0.6f);
				if (myRock2.getPosition().y >= 700) {
					myRock2.setPosition(ranRockX2, ranRockY);
				}
				myRock3.move(0.0f, 0.4f);
				if (myRock3.getPosition().y >= 700) {
					myRock3.setPosition(ranRockX3, ranRockY);
				}
				myRock4.move(0.0f, 0.35f);
				if (myRock4.getPosition().y >= 700) {
					myRock4.setPosition(ranRockX4, ranRockY);	
				}
				myRock5.move(0.0f, 0.6f);
				if (myRock5.getPosition().y >= 700) {
					myRock5.setPosition(ranRockX5, ranRockY);
				}
			}
			//level 5
			if (level == 5) {
				myRock.move(0.0f, 0.5f);

				if (myRock.getPosition().y >= 700) {
					myRock.setPosition(ranRockX, ranRockY);
				}
				myRock2.move(0.0f, 0.6f);
				if (myRock2.getPosition().y >= 700) {
					myRock2.setPosition(ranRockX2, ranRockY);
				}
				myRock3.move(0.0f, 0.4f);
				if (myRock3.getPosition().y >= 700) {
					myRock3.setPosition(ranRockX3, ranRockY);
				}
				myRock4.move(0.0f, 0.35f);
				if (myRock4.getPosition().y >= 700) {
					myRock4.setPosition(ranRockX4, ranRockY);
				}
				myRock5.move(0.0f, 0.6f);
				if (myRock5.getPosition().y >= 700) {
					myRock5.setPosition(ranRockX5, ranRockY);
				}
				myRock6.move(0.0f, 0.2f);
				if (myRock6.getPosition().y >= 700) {
					myRock6.setPosition(ranRockX6, -500);
				}
			}

		// background move
			myBg.move(0.0f, 0.1f);
		if (myBg.getPosition().y >= -100) {
			myBg.setPosition(myBg.getPosition().x, -1200);
		}
		//Ship Control

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			myShip.move(0.0f, -0.8f);
			myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 0, spritesizeX, spritesizeY));

			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			myShip.move(0.8f, 0.0f);
			myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 0, spritesizeX, spritesizeY));
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			myShip.move(-0.8f, 0.0f);
			myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 0, spritesizeX, spritesizeY));
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			myShip.move(0.0f, 0.8f);
			myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 0, spritesizeX, spritesizeY));
		}

		if (animationFrame >= 2) {
			animationFrame = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			myWindow.close();
			backgroundSound.stop();
		}
		animationFrame++;
		//bullet shoot
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			if (myBullet.getPosition().y <= 0) {
				myBullet.setPosition(myShip.getPosition().x + 18, myShip.getPosition().y);
				hitsound.play();
			}
			Xbullet = 0.0f;
			Ybullet = -3.0f;
		}
		myBullet.move(Xbullet, Ybullet);
		//bomb shoot
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			if (Bomb > 0) {
				if (myBomb.getPosition().y <= 0) {
					myBomb.setPosition(myShip.getPosition().x + 18, myShip.getPosition().y);
				Bomb--;
				}
				
			}
			
		}
		myBomb.move(0.0f, -1.0f);
		//bound ship
		if (myShip.getPosition().x <= 0) {
			myShip.setPosition(0, myShip.getPosition().y);
		}
		if (myShip.getPosition().x >= 947) {
			myShip.setPosition(947, myShip.getPosition().y);
		}
		if (myShip.getPosition().y <= 250) {
			myShip.setPosition(myShip.getPosition().x, 250);
		}
		if (myShip.getPosition().y >= 635) {
			myShip.setPosition(myShip.getPosition().x, 635);
		}
		//bound Bullet myrock
		if (myBullet.getGlobalBounds().intersects(myRock.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);			
			score++;
			hit++;
			if (hit == 4) {
					myBoom.setPosition(myRock.getPosition().x, myRock.getPosition().y);
				}
			if (hit >= 5) {
				myRock.setPosition(ranRockX, ranRockY);
				
				if (hit >= 5) {
					hit = 0;
				}
			}
		}
		if (myBullet.getGlobalBounds().intersects(myRock2.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);
			score++;
			hit++;
			if (hit == 4) {
					myBoom.setPosition(myRock2.getPosition().x, myRock2.getPosition().y);
				}
			if (hit >= 5) {
				myRock2.setPosition(ranRockX2, ranRockY);
				
				if (hit >= 5) {
					hit = 0;
				}
			}
		}
		if (myBullet.getGlobalBounds().intersects(myRock3.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);
			score++;
			hit++;
			if (hit == 4) {
					myBoom.setPosition(myRock3.getPosition().x, myRock3.getPosition().y);
				}
			if (hit >= 5) {
				myRock3.setPosition(ranRockX3, ranRockY);
				
				if (hit >= 5) {
					hit = 0;
				}
			}
		}
		if (myBullet.getGlobalBounds().intersects(myRock4.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);
			score++;
			hit++;
			if (hit == 4) {
					myBoom.setPosition(myRock4.getPosition().x, myRock4.getPosition().y);
				}
			if (hit >= 5) {
				myRock4.setPosition(ranRockX4, ranRockY);
				
				if (hit >= 5) {
					hit = 0;
				}
			}
		}		
		if (myBullet.getGlobalBounds().intersects(myRock5.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);
			score++;	
			hit++;
			if (hit == 4) {
						myBoom.setPosition(myRock5.getPosition().x, myRock5.getPosition().y);
					}
			if (hit >= 5) {  
				
					myRock5.setPosition(ranRockX5, ranRockY);
				
				if (hit >= 5) {
					hit = 0;
				}
			}
		
		}
		if (myBullet.getGlobalBounds().intersects(myRock6.getGlobalBounds())) {
			myBullet.setPosition(-1000, -1000);
			score++;
			hit++;
			if (hit == 19) {
				myBoom.setPosition(myRock6.getPosition().x, myRock6.getPosition().y);
			}
			if (hit >= 20) {

				myRock6.setPosition(ranRockX6, -500);

				if (hit >= 20) {
					hit = 0;
				}
			}

		}
		
		if (hit == 0) {
			myBoom.setPosition(-1000, -2000);
		}
		if (hit == 5) {
			myBoom.setPosition(-1000, -2000);
		}
		//bound Bomb myrock
		if (myBomb.getGlobalBounds().intersects(myRock.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock.setPosition(ranRockX, ranRockY);
			score += 100;
		}
		if (myBomb.getGlobalBounds().intersects(myRock2.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock2.setPosition(ranRockX2, ranRockY);
			score += 100;
		}
		if (myBomb.getGlobalBounds().intersects(myRock3.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock3.setPosition(ranRockX3, ranRockY);
			score+= 100;
		}
		if (myBomb.getGlobalBounds().intersects(myRock4.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock4.setPosition(ranRockX4, ranRockY);
			score += 100;
		}	
		if (myBomb.getGlobalBounds().intersects(myRock5.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock5.setPosition(ranRockX5, ranRockY);
			score += 100;
		}
		if (myBomb.getGlobalBounds().intersects(myRock6.getGlobalBounds())) {
			myBomb.setPosition(-1000, -1000);
			myRock6.setPosition(ranRockX6, -500);
			score += 100;
		}
			//bound ship heart
		if (myShip.getGlobalBounds().intersects(myHeart.getGlobalBounds())) {
			myHeart.setPosition(ranHeartX, ranHeartY);
			if (heart <=9) { 
				heart++;
			}
			else {
				heart = heart;
			}
		}
		//bound ship bomb item
		if (myShip.getGlobalBounds().intersects(myBomb1.getGlobalBounds())) {
			myBomb1.setPosition(ranBombX, ranBombY);
			if (Bomb <= 4) {
				Bomb++;
			}
			else {
				Bomb = Bomb;
			}
		}	
		//bound ship rock
		if (myShip.getGlobalBounds().intersects(myRock.getGlobalBounds())) {
			myRock.setPosition(ranRockX, ranRockY);
			
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}		
			
			
		
		}
		if (myShip.getGlobalBounds().intersects(myRock2.getGlobalBounds())) {
			myRock2.setPosition(ranRockX2, ranRockY);
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}
		}
		if (myShip.getGlobalBounds().intersects(myRock3.getGlobalBounds())) {
			myRock3.setPosition(ranRockX3, ranRockY);
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}
		}
		if (myShip.getGlobalBounds().intersects(myRock4.getGlobalBounds())) {
			myRock4.setPosition(ranRockX4, ranRockY);
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}
		}
		if (myShip.getGlobalBounds().intersects(myRock5.getGlobalBounds())) {
			myRock5.setPosition(ranRockX5, ranRockY);
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}
		}
		if (myShip.getGlobalBounds().intersects(myRock6.getGlobalBounds())) {
			myRock6.setPosition(ranRockX6, -500);
			if (heart > 0) {
				heart--;
			}
			else {
				heart = heart;
			}
		}
		//score
		if (score >= 200 && score <500) {
			level = 2;
		}
		if (score >= 500 && score < 900) {
			level = 3;
		}
		if (score >= 900 && score < 1500) {
			level = 4;
		}
		if (score >= 1500 && score < 3000) {
			level = 5;
		}
		if (score >= 3000) {
			level = 6;
		}
		
		
		
		myText.setPosition(0, 0);
		myText.setString("Score : ");
		myWindow.draw(myText);
		myText.setPosition(70, 0);
		sprintf(s, "%d", score);
		myText.setString(s);
		myWindow.draw(myText);
		
		myText1.setPosition(0, 40);
		myText1.setString("Level : ");
		myWindow.draw(myText1);
		myText1.setPosition(70, 40);
		sprintf(l, "%d", level);
		myText1.setString(l);
		myWindow.draw(myText1);
		
		myText2.setPosition(900, 0);
		myText2.setString("Heart : ");
		myWindow.draw(myText2);
		myText2.setPosition(980, 0);
		sprintf(h, "%d", heart);
		myText2.setString(h);
		myWindow.draw(myText2);
		
		myText3.setPosition(900, 40);
		myText3.setString("Bomb : ");
		myWindow.draw(myText3);
		myText3.setPosition(980, 40);
		sprintf(b, "%d", Bomb);
		myText3.setString(b);
		myWindow.draw(myText3);
		
		myWindow.draw(myBullet);
		myWindow.draw(myBomb);
		myWindow.draw(myShip);

		myWindow.draw(myRock);
		myWindow.draw(myRock2);
		myWindow.draw(myRock3);
		myWindow.draw(myRock4);
		myWindow.draw(myRock5);
		myWindow.draw(myRock6);
		myWindow.draw(myHeart);
		myWindow.draw(myBomb1);
		myWindow.draw(myBoom);


		myWindow.display();
		myWindow.clear();
	}
}
