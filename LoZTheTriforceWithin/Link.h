//The Link Header File

#pragma once

#include "SFML\Graphics.hpp"

class Link
{
public:
	Link();
	Link(std::string name);
	~Link();

	//getters and setters
	void setName(std::string name);
	std::string getName();

	void setHealth(float health);
	float getHealth();
	
	void setTexture(std::string path);
	sf::Texture getTexture();

	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();

	void setSource(sf::Vector2i source);
	sf::Vector2i getSource();

	void setCoords(sf::Vector2i coords);
	sf::Vector2i getCoords();
	//end getters and setters

protected:
	std::string mName;
	float mHealth;
	std::string mTexturePath = "Images/Link1.png";
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2i mSource;
	sf::Vector2i mCoords;
};

