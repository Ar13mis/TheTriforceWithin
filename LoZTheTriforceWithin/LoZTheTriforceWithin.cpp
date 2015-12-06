// LoZTheTriforceWithin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <sfml/Graphics.hpp>
#include "Link.h"
#include "Movement.h"

const int windowX = 800;
const int windowY = 600;

int main()
{
	//create a character
	Link spriteLink("Jake");
	sf::Sprite mSprite;

	//set the source vector for the animation
	Link setSource(sf::Vector2i(source));

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
		DecideEdges(spriteLink, windowX, windowY);

		//animate the walking of the sprite
		AnimateWalk(spriteLink);

		//std::cout << spriteLink.getSprite().getPosition().x << spriteLink.getSprite().getPosition().y << std::endl;

		//draw the things (window.draw(stuff to draw here))
		window.draw(spriteLink.getSprite());

		//display the window
		window.display();

		//clear the window
		window.clear();
	}

	return 0;
}