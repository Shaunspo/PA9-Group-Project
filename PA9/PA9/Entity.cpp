#include "Entity.h"

void Entity::initTexture()
{
	if (!this->textureSheet.loadFromFile(this->textureSheetFile))
	{
		std::cout << "Error could not load texture sheet" << std::endl;
	}
}

void Entity::initSprite()
{
	/*
		Base initialize
		-Just makes the texture a white square
	*/
	sf::Texture testTexture;
	testTexture.create(50, 50);
	this->sprite.setTexture(testTexture);
}

void Entity::initPhysics()
{
	this->velocityMax = 50.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.85f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

Entity::Entity()
{
	this->initTexture();
	this->initSprite();
	this->initPhysics();
}

Entity::~Entity()
{
}

const sf::FloatRect Entity::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

sf::Sprite Entity::getSprite()
{
	return this->sprite;
}

sf::Texture Entity::getTextureSheet()
{
	return this->textureSheet;
}

const sf::IntRect Entity::getCurrentFrame()
{
	return this->currentFrame;
}

void Entity::setTextureSheet(const std::string textureSheetFile)
{
	this->textureSheetFile = textureSheetFile;
}

void Entity::setCurrentFrame(const sf::IntRect frame)
{
	this->currentFrame = frame;
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Entity::move(const float dir_x, const float dir_y)
{
	//Accelerration
	this->velocity.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = velocityMax * ((this->velocity.x < 0) ? -1.f : 1.f);
	}
}

void Entity::updatePhysics()
{
	//Gravity
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = velocityMaxY * ((this->velocity.y < 0) ? -1.f : 1.f);
	}


	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
	{
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocityMin)
	{
		this->velocity.y = 0.f;
	}

	this->sprite.move(this->velocity);
}

void Entity::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->move(-0.4f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->move(0.4f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) //Jump
	{
		this->move(0.f, 5.f);
	}
}

void Entity::update()
{
	this->updateMovement();
	this->updatePhysics();
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
