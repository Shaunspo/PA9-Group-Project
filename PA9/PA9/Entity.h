#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


class Entity
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//Animation

	//Movement

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//Core
	void initTexture();
	void initSprite();
	void initPhysics();

public:
	Entity();
	~Entity();

	//Functions
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

