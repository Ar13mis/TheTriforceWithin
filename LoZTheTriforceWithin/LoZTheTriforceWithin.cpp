// LoZTheTriforceWithin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <sfml/Graphics.hpp>

const int windowX = 800;
const int windowY = 600;

int main()
{

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "The Triforce Within");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//clear the window
		window.clear();

		//draw the window


		//display the window
		window.display();
	}

	return 0;
}