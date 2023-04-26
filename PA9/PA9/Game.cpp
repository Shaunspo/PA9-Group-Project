#include "Game.h"

//Private Functions
void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(30);
}

void Game::initPlayer()
{
	this->Duck = new Entity();
}


//Public Functions

//Constructors / Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->Duck;
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}

	this->updatePlayer();
	this->updateCollision();
}

void Game::updatePlayer()
{
	this->Duck->update();
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->Duck->getGlobalBounds().top + this->Duck->getGlobalBounds().height > this->window->getSize().y)
	{
		this->Duck->resetVelocityY();
		this->Duck->setPosition(this->Duck->getGlobalBounds().left, this->window->getSize().y - this->Duck->getGlobalBounds().height);
	}
}

//Functions
void Game::update()
{
	pollEvents();
}

void Game::renderPlayer()
{
	this->Duck->render(*this->window);
}

void Game::render()
{
	/*
		Renders the game objects
	*/

	this->window->clear(sf::Color::Blue);

	//Draw game objects
	this->renderPlayer();

	this->window->display();
}
