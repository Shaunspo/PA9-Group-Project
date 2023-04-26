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

	void initTestPlayer();//test function with white square
	void initDuck();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Getters
	const bool getWindowIsOpen() const;

	//Functions
	void pollEvents();
	void updateTestPlayer();//test function with white square
	void updateDuck();
	void TestUpdateCollision();//test function with white square
	void updateCollision();
	void update();
	void renderTestPlayer();//test function with white square
	void renderDuck();
	void render();
};

#endif
