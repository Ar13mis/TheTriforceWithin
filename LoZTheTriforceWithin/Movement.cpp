//The Movement C++ File

#include "stdafx.h"
#include "Movement.h"
#include "Link.h"

//declare variables
int counter = 0;

void MovingAround(Link &character) 
{
	//get the information from my character class
	sf::Sprite mSprite = character.getSprite();

	//declare variable for speed
	float speed = 1.f;

	//move with the arrow keys
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))		
		mSprite.move(0, -speed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mSprite.move(speed, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mSprite.move(0, speed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mSprite.move(-speed, 0);

	//push the sprite information back to the class
	character.setSprite(mSprite);
}

void DecideEdges(Link &character, sf::Vector2i &coords, int windowX, int windowY)
{
	//get the information from my character class
	sf::Sprite mSprite = character.getSprite();
	sf::Vector2f mPosition = mSprite.getPosition();

	//determine if you should be able to go outside the screen or not
	if (mPosition.x > windowX - 48)
	{
		mSprite.setPosition(windowX - 48, mPosition.y);
		coords.x += 1;
	}
	else if (mPosition.x < 0)
	{
		mSprite.setPosition(0, mPosition.y);
		coords.x -= 1;
	}
	else if (mPosition.y > windowY - 64)
	{
		mSprite.setPosition(mPosition.x, windowY - 64);
		coords.y += 1;
	}
	else if (mPosition.y < 0)
	{
		mSprite.setPosition(mPosition.x, 0);
		coords.y -= 1;
	}

	//push the sprite information to the class
	character.setSprite(mSprite);
}

//Function for walking animation
void AnimateWalk(Link &character)
{
		//declare local variables for texture and source
		sf::Texture mTexture = character.getTexture();
		sf::Vector2i mSource = character.getSource();

		//set the look direction of the sprite
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			mSource.y = 0;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			mSource.y = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			mSource.y = 2;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			mSource.y = 3;
		//stop moving
		else
			mSource.x = 0;

		//increment walk
		mSource.x++;

		//reset the walk
		if ((mSource.x) >= 12)
			mSource.x = 1;

		//get the sprite
		sf::Sprite mSprite = character.getSprite();

		//crop the sprite
		mSprite.setTextureRect(sf::IntRect(mSource.x * 24, mSource.y * 32, 24, 32));

		//make the change slower
		counter++;
		if (counter - 10 == 0)
		{
			//push back source for reference
			character.setSource(mSource);

			//reset the counter
			counter = 0;
		}

		//push back sprite
		character.setSprite(mSprite);
	
}

//Function for collision detection
bool CollisionDetection(sf::Sprite sprite1, sf::Sprite sprite2)
{
	if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds))
	{
		return true;
	}
	else
	{
		return false;
	}
}
