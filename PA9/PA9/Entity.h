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


	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;


public:
	Entity();
	~Entity();

	//Core
	void initTexture();
	virtual void initSprite();
	void initPhysics();

	//Getters
	const sf::FloatRect getGlobalBounds() const;
	sf::Sprite getSprite();
	sf::Texture getTextureSheet();
	const sf::IntRect getCurrentFrame();

	//Setters
	void setTextureSheetName(const std::string textureSheetFile);
	void setCurrentFrame(const sf::IntRect frame);
	void setSprite(sf::Texture textureSheet);
	void setFrame(const sf::IntRect currentFrame);

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();

	//Functions
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

