#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Entity.h"

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

	Entity* testPlayer;

	void initVariable();
	void initWindow();

	void initTestPlayer();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void updateTestPlayer();
	void update();
	void renderPlayer();
	void render();
};

#endif
