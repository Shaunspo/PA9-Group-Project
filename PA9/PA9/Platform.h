#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <ctime>

using sf::RectangleShape;
using sf::Vector2f;
using sf::RenderTarget;
using sf::Texture;

// Platform master class
class Platform
{
public:

	// Constructors and destructors
	Platform();

	~Platform();

	Platform(float xPos, float yPos, float w, float h, float rot);

	// Getters and setters
	float getXpos();

	float getYpos();

	float getWidth();

	float getHeight();

	float getRot();

	RectangleShape getRect();

	void setXpos(float xPos);

	void setYpos(float yPos);

	void setWidth(float w);

	void setHeight(float h);

	void setRot(float rot);

	void setRect(RectangleShape newRect);

	void placePlatform();

	void placePlatform(float xPos, float yPos, float w, float h, float rot);

	void renderPlatform(RenderTarget& target);

	// public data member for inhereting classes to use
	RectangleShape rect;
	Texture bricks;

private:

	// data members
	float posX;
	float posY;
	float width;
	float height;
	float rotation;
};

// GroundPlatform class. Creates platforms that are the main surface of the level
class GroundPlatform : public Platform {
public:

	void placePlatform();

	void placePlatform(float xPos, float yPos, float w, float h, float rot);
};

// ThinPlatform class. Creates thin platforms above the surface that the player can jump through
class ThinPlatform : public Platform {
public:

	void placePlatform();

	void placePlatform(float xPos, float yPos, float w, float h, float rot);
};

class Background : public Platform {

	void placePlatform();

	void placePlatform(float xPos, float yPos, float w, float h, float rot);
};