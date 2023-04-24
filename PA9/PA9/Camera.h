#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using sf::RenderWindow;
using sf::CircleShape;
using sf::Color;
using sf::VideoMode;
using sf::Event;
using sf::Texture;
using sf::Sprite;

class Camera {

public:

	//constructor class 
	Camera(double width, double height);

	void update(const sf::Vector2f& targetPosition);

	const sf::View& getCamera() const;

	void setCamera(const sf::View view);


private:

	sf::View camera;

};