#include "Entity.h"

void Entity::initTexture()
{
	/*
		Put the png file for the sprite in the quotations
	*/
	if (!this->textureSheet.loadFromFile("image.png"))
	{
		std::cout << "Error could not load texture sheet" << std::endl;
	}
}

void Entity::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
}

Entity::Entity()
{
	this->initTexture();
	this->initSprite();
}

Entity::~Entity()
{
}

void Entity::updatePlayer()
{
}

void Entity::update()
{
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
