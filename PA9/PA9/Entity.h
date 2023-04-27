#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


class Entity
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	std::string textureSheetFile;

	//Animation
	sf::IntRect currentFrame;
	bool moving;
	sf::Clock animationTimer;


	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;
	bool isGrounded;


public:
	Entity();
	~Entity();

	//Core
	void initvariables();
	void initTexture();
	virtual void initSprite();
	void initPhysics();
	void initAnimations();

	//Getters
	const sf::FloatRect getGlobalBounds() const;
	sf::Sprite getSprite();
	sf::Texture getTextureSheet();
	const sf::IntRect getCurrentFrame();
	sf::Vector2f getPosition();

	//Setters
	void setTextureSheetName(const std::string textureSheetFile);
	void setCurrentFrame(const sf::IntRect frame);
	void setSprite(sf::Texture textureSheet);
	void setFrame(const sf::IntRect currentFrame);
	void setGrounded(const bool grounded);

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();
	void resetVelocityX();

	//Functions
	void move(const float dir_x, const float dir_y);
	void updateAnimations();
	void updatePhysics();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

