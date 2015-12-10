#include "stdafx.h"
#include "WorldPosition.h"


WorldPosition::WorldPosition()
{
}

WorldPosition::~WorldPosition()
{
}

void WorldPosition::CreateWorld(sf::Vector2i &coords)
{
	
	coords.x = 0;
	coords.y = 0;

	mWorldCoordinates = coords;

}