#pragma once
#include "SFML\Graphics.hpp"
class WorldPosition
{
public:
	WorldPosition();
	~WorldPosition();

	void CreateWorld(sf::Vector2i &coords);

protected:
	sf::Vector2i mWorldCoordinates;
};

