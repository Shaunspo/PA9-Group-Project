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

	//Core


	void initTexture();
	void initSprite();

public:
	Entity();
	~Entity();

	//Functions
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

