#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include<SFML/Audio.hpp>
int main() {
	

	sf::RenderWindow myWindow(sf::VideoMode(1024,720),"My Game");
	
	//////sound background
	sf::SoundBuffer myBuffer;
	myBuffer.loadFromFile("sound01.wav");
	sf::Sound backgroundSound;
	backgroundSound.setBuffer(myBuffer);
	backgroundSound.play();
	backgroundSound.setLoop(true);
			
	//Background
	sf::Texture myBackground;
	myBackground.loadFromFile("galaxy.png");
	
	sf::Sprite myBg;
	myBg.setTexture(myBackground);
	myBg.setPosition(-200,-1200);
	myBg.setScale(2,2);
	
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
	myRock.setPosition(200, 500);
	myRock.setScale(0.5, 0.5);

	int spritesizeRockX = myRockTex.getSize().x / 8;
	int spritesizeRockY = myRockTex.getSize().y / 8;

	myRock.setTextureRect(sf::IntRect(0, 0, spritesizeRockX, spritesizeRockY));
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


	int animationFrame = 0;
	while (true) {
		myWindow.draw(myBg);
		myWindow.draw(myBullet);
		myBg.move(0.0f, 0.2f);
		if (myBg.getPosition().y >= -100) {
			myBg.setPosition(myBg.getPosition().x, -1200);
		}
		
		myWindow.draw(myShip);
		myWindow.draw(myRock);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W )) {			
			myShip.move(0.0f, -0.5f);						
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 1, spritesizeX, spritesizeY));			
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 4, spritesizeX, spritesizeY));
			}
			
			else  {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 0, spritesizeX, spritesizeY));
				
			}			
						
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			myShip.move(0.5f, 0.0f);			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 1, spritesizeX, spritesizeY));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 3, spritesizeX, spritesizeY));
			}
			else {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 2, spritesizeX, spritesizeY));
			}
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			myShip.move(-0.5f, 0.0f);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 4, spritesizeX, spritesizeY));

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 6, spritesizeX, spritesizeY));

			}			
			else {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 5, spritesizeX, spritesizeY));
			}
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			myShip.move(0.0f, 0.5f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 3, spritesizeX, spritesizeY));

			}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 6, spritesizeX, spritesizeY));

			}
				else {
				myShip.setTextureRect(sf::IntRect(spritesizeX * animationFrame, spritesizeY * 7, spritesizeX, spritesizeY));
			}
			
			if (animationFrame >= 2) {
				animationFrame = 0;
			}
		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				myWindow.close();
				backgroundSound.stop();
			}
		animationFrame++;
		//bullet
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			if (myBullet.getPosition().y<=0) {
				myBullet.setPosition(myShip.getPosition().x + 18, myShip.getPosition().y);
			}
		}
		
		myBullet.move(0.0f, -2.0f);
		
		
		//bound ship
		if (myShip.getPosition().x <= 0) {
			myShip.setPosition(0, myShip.getPosition().y);
		}
		if (myShip.getPosition().x >= 947) {
			myShip.setPosition(947, myShip.getPosition().y);
		}
		if (myShip.getPosition().y <= 0) {
			myShip.setPosition(myShip.getPosition().x, 0);
		}
		if (myShip.getPosition().y >= 635) {
			myShip.setPosition(myShip.getPosition().x, 635);
		}
		
		
		myWindow.display();
		myWindow.clear();
	}
}