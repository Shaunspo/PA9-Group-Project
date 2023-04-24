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
	/*
		Uncomment and delete other line when texture is added
	*/
	//this->sprite.setTexture(this->textureSheet);
	sf::Texture testTexture;
	testTexture.create(50, 50);
	this->sprite.setTexture(testTexture);
}

Entity::Entity()
{
	this->initTexture();
	this->initSprite();
}

Entity::~Entity()
{
}

void Entity::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Up
	{
		this->sprite.move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
	}
}

void Entity::update()
{
	this->updateMovement();
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
