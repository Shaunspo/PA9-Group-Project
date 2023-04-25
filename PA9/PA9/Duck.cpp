#include "Duck.h"

Duck::Duck()
{
	setTextureSheetName("images/idle_duck_animation.png");
	this->initTexture();
	this->initSprite();
}

void Duck::initSprite()
{
	this->setSprite(this->getTextureSheet());
	this->setCurrentFrame(sf::IntRect(0, 0, 64, 64));
	this->getSprite().setTextureRect(this->getCurrentFrame());
}
