//The Link C++ Class File

#include "stdafx.h"
#include "iostream"
#include "Link.h"
#include <string>
#include <SFML/Graphics.hpp>

//default constructor
Link::Link()
	: mName("Link")
	, mHealth(10.f)
{
	//set the sprite position
	mSprite.setPosition(10, 10);

	if (!mTexture.loadFromFile(mTexturePath))
	{
		//error loading texture
		std::cout << "Error loading texture link" << std::endl;
	}

	//set the texture and size of the sprite
	mSprite.setTexture(mTexture);
	mSprite.scale(sf::Vector2f(2.f, 2.f));

	//declare variables for animating the sprite
	enum direction { Up, Right, Down, Left };
	mSource.x = 0;
	mSource.y = Up;

	setSource(mSource);
}

//main constructor
Link::Link(std::string name)
	: mName(name)
	, mHealth(10.f)
{
	//set the sprite position
	mSprite.setPosition(10, 10);

	if (!mTexture.loadFromFile(mTexturePath)) 
	{
		//error loading texture
		std::cout << "Error loading texture link" << std::endl;
	}
	//set the sprite texture and scale
	mSprite.setTexture(mTexture);
	mSprite.scale(sf::Vector2f(2.f, 2.f));

	//declare variables for animating the sprite
	enum direction { Up, Right, Down, Left };
	mSource.x = 0;
	mSource.y = Up;

	setSource(mSource);
}

//default destructor
Link::~Link()
{
}


//getters and setters
//set name
void Link::setName(std::string name) 
{
	mName = name;
}

//get name
std::string Link::getName()
{
	return mName;
}

//set health
void Link::setHealth(float health)
{
	mHealth = health;
}

//get health
float Link::getHealth()
{
	return mHealth;
}

//set texture
void Link::setTexture(std::string path) 
{
	mTexturePath = path;
}

//get texture
sf::Texture Link::getTexture()
{
	return mTexture;
}

//set sprite
void Link::setSprite(sf::Sprite sprite) 
{
	mSprite = sprite;
}

//get sprite
sf::Sprite Link::getSprite()
{
	return mSprite;
}

//set source
void Link::setSource(sf::Vector2i source)
{
	mSource = source;
}

//get source
sf::Vector2i Link::getSource()
{
	return mSource;
}

//set coords
void Link::setCoords(sf::Vector2i coords)
{
	mCoords = coords;
}

sf::Vector2i Link::getCoords()
{
	return mCoords;
}