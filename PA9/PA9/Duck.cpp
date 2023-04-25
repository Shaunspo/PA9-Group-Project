#include "Duck.h"

Duck::Duck()
{
	setTextureSheet("idle_duck_animation.png");
	this->initTexture();
	this->initSprite();
	this->initPhysics();
}

void Duck::initSprite()
{
	this->getSprite().setTexture(this->getTextureSheet());
	this->setCurrentFrame(sf::IntRect(0, 0, 64, 64));
	this->getSprite().setTextureRect(this->getCurrentFrame());
}
