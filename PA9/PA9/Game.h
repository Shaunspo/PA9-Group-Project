#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Entity.h"
#include "Level.h"

/*
	Class that acts as game engine
*/

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	Entity* Duck;
	Level TestLevel;
	sf::View camera;

	void initVariable();
	void initWindow();

	void initPlayer();//test function with white square

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Getters and setters
	const bool getWindowIsOpen() const;
	void setView(const sf::View& newView);
	sf::Vector2f getPlayerPos();

	//Functions
	void pollEvents();
	void updatePlayer();//test function with white square
	void updateCollision();//test function with white square
	void update();
	void renderPlayer();//test function with white square
	void render();
	void preLoop();
};

#endif
