// LoZTheTriforceWithin.cpp : Defines the entry point for the console application.
// The Main Class For Game Loop

#include "stdafx.h"
#include "iostream"
#include <sfml/Graphics.hpp>
#include "Link.h"
#include "Movement.h"
#include "WorldPosition.h"

const int windowX = 800;
const int windowY = 600;

int main()
{
	//create the world
	sf::Vector2i coords;
	//WorldPosition CreateWorld(sf::Vector2i(coords));

	//create a character
	Link spriteLink("Jake");
	sf::Sprite mSprite;

	//Create the floor
	sf::Sprite floorSprite;
	sf::Texture floorTexture;
	if (!floorTexture.loadFromFile("Images/StoneTile.png"))
	{
		std::cout << "Error loading texture 'Images/StoneTile.png'" << std::endl;
	}
	floorSprite.setTexture(floorTexture);
	floorSprite.setScale(sf::Vector2f(25.f, 19.f));

	//Create the throne
	sf::Sprite throne;
	sf::Texture throneTexture;
	if (!throneTexture.loadFromFile("Images/IronThrone.png"))
	{
		std::cout << "Error loading texture 'Images/IronThrone.png'" << std::endl;
	}
	throne.setTexture(throneTexture);
	throne.setPosition(300, 10);

	//create the window
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "The Triforce Within");

	///GAME LOOP
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//move with the arrow keys (Movement.cpp)
		MovingAround(spriteLink);

		//check if you are on the edge of the screen (Movement.cpp)
		DecideEdges(spriteLink, coords, windowX, windowY);

		//animate the walking of the sprite
		AnimateWalk(spriteLink);

		//check for collision
		bool throneHit = CollisionDetection(spriteLink.getSprite(), throne);

		if (throneHit == true)
		{
			std::cout << "You are the King of the Iron Throne." << std::endl;
		}

		//draw the things (window.draw(stuff to draw here))
		window.draw(floorSprite);
		window.draw(throne);
		window.draw(spriteLink.getSprite());

		//display the window
		window.display();

		//clear the window
		window.clear();
	}

	return 0;
}