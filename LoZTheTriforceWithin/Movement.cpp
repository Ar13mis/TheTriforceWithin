#include "stdafx.h"
#include "Movement.h"
#include "Link.h"

void MovingAround(Link &character) 
{
	//get the information from my character class
	sf::Sprite mSprite = character.getSprite();

	//move with the arrow keys
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		mSprite.move(0, -1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mSprite.move(1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mSprite.move(0, 1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mSprite.move(-1, 0);

	//push the sprite information back to the class
	character.setSprite(mSprite);
}

void DecideEdges(Link &character, int windowX, int windowY)
{
	//get the information from my character class
	sf::Sprite mSprite = character.getSprite();
	sf::Vector2f mPosition = mSprite.getPosition();

	//determine if you should be able to go outside the screen or not
	if (mPosition.x > windowX - 48)
		mSprite.setPosition(windowX - 48, mPosition.y);
	else if (mPosition.x < 0)
		mSprite.setPosition(0, mPosition.y);
	else if (mPosition.y > windowY - 64)
		mSprite.setPosition(mPosition.x, windowY - 64);
	else if (mPosition.y < 0)
		mSprite.setPosition(mPosition.x, 0);

	//push the sprite information to the class
	character.setSprite(mSprite);
}

void AnimateWalk(Link &character)
{
	sf::Texture mTexture = character.getTexture();
	sf::Vector2i mSource = character.getSource();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		mSource.y = 0;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mSource.y = 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mSource.y = 2;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mSource.y = 3;

	mSource.x++;

	if ((mSource.x) >= 12)
		mSource.x = 1;

	sf::Sprite mSprite = character.getSprite();
	mSprite.setTextureRect(sf::IntRect(mSource.x * 24, mSource.y * 32, 24, 32));
	character.setSprite(mSprite);
}