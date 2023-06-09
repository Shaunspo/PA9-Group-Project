#include "Entity.h"

void Entity::initvariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Entity::initTexture()
{
	if (!this->textureSheet.loadFromFile("images/duck spritesheet-fixed.png"))
	{
		std::cout << "Error could not load texture sheet" << std::endl;
	}
}

void Entity::initSprite()
{
	/*
		Base initialize
	*/
	this->sprite.setTexture(this->textureSheet);
	//this->sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

	this->currentFrame = sf::IntRect(0, 0, 64, 64);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.2f, 2.2f);
}

void Entity::initPhysics()
{
	this->velocityMax = 50.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.85f;
	this->gravity = 4.f;
	this->velocityMaxY = 200.f;
}

void Entity::initAnimations()
{
	this->animationTimer.restart();
}

Entity::Entity()
{
	this->initvariables();
	this->initTexture();
	this->initSprite();
	this->initPhysics();
	this->initAnimations();
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

void Entity::setTextureSheetName(const std::string textureSheetFile)
{
	this->textureSheetFile = textureSheetFile;
}

void Entity::setCurrentFrame(const sf::IntRect frame)
{
	this->currentFrame = frame;
}

void Entity::setSprite(sf::Texture textureSheet)
{
	this->sprite.setTexture(textureSheet);
}

void Entity::setFrame(const sf::IntRect currentFrame)
{
	this->sprite.setTextureRect(currentFrame);
}

void Entity::setGrounded(const bool grounded)
{
	isGrounded = grounded;
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Entity::resetVelocityX()
{
	this->velocity.x = 0.f;
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

	this->velocity.y += dir_y * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = velocityMax * ((this->velocity.y < 0) ? -1.f : 1.f);
	}
}

void Entity::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 64.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 64.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

	}
	else if (this->animState == PLAYER_ANIMATION_STATES::JUMPING)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 64.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
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

	// Test Case 2
	// this->velocityMaxY = 400.f;


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

	// Test Case 3
	// this->sprite.move(0.f, -20000.f);
}

void Entity::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isGrounded == true) //Jump
	{
		this->move(0.f, -3000.f);
		this->animState = PLAYER_ANIMATION_STATES::JUMPING;
		setGrounded(false);
	}
}

void Entity::update()
{
	this->updateMovement();
	this->updatePhysics();
	this->updateAnimations();
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

sf::Vector2f Entity::getPosition() {
	return this->sprite.getPosition();
}
