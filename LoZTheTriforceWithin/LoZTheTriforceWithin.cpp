// LoZTheTriforceWithin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <sfml/Graphics.hpp>
#include "Link.h"

const int windowX = 800;
const int windowY = 600;

int main()
{

	enum direction { Up, Right, Down, Left};
	sf::Vector2i source(0, Up);

	Link spriteLink("Jake");
	sf::Sprite mSprite;

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "The Triforce Within");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Up)
				source.y = Up;
			else if (event.key.code == sf::Keyboard::Right)
				source.y = Right;
			else if (event.key.code == sf::Keyboard::Down)
				source.y = Down;
			else if (event.key.code == sf::Keyboard::Left)
				source.y = Left;
			break;
		}

		mSprite = spriteLink.getSprite();
		mSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 24, 32));
		spriteLink.setSprite(mSprite);

		//clear the window
		window.clear();

		//draw the things (window.draw(stuff to draw here))
		window.draw(spriteLink.getSprite());

		//display the window
		window.display();
	}

	return 0;
}