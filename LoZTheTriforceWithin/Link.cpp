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
}

//main constructor
Link::Link(std::string name)
	: mName(name)
	, mHealth(10.f)
{
	mSprite.setPosition(10, 10);

	if (!mTexture.loadFromFile(mTexturePath)) 
	{
		//error loading texturesa
		std::cout << "Error loading texture link" << std::endl;
	}

	mSprite.setTexture(mTexture);
	mSprite.scale(sf::Vector2f(2.f, 2.f));
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