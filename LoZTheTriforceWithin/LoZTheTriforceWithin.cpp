// LoZTheTriforceWithin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <sfml/Graphics.hpp>
#include "Link.h"

#include <thread>
#include <chrono>

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
			{
				source.y = Up;
				source.x++;
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				source.y = Right;
				source.x++;
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				source.y = Down;
				source.x++;
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				source.y = Left;
				source.x++;
			}
			break;
		}

		//std::this_thread::sleep_for(std::chrono::seconds(1));

		mSprite = spriteLink.getSprite();
		mSprite.setTextureRect(sf::IntRect(source.x * 24, source.y * 32, 24, 32));
		spriteLink.setSprite(mSprite);

		if (source.x >= spriteLink.getTexture().getSize().x)
			source.x = 0;

		//clear the window
		window.clear();

		//draw the things (window.draw(stuff to draw here))
		window.draw(spriteLink.getSprite());

		//display the window
		window.display();
	}

	return 0;
}