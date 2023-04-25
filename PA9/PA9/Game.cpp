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

void Game::initTestPlayer()
{
	this->testPlayer = new Entity();
}

void Game::initDuck()
{
	this->duck = new Duck();
}


//Public Functions

//Constructors / Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	//this->initTestPlayer();
	this->initDuck();
}

Game::~Game()
{
	delete this->window;
	delete this->testPlayer;
	delete this->duck;
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

	//this->updateTestPlayer();
	//this->TestUpdateCollision();
	this->updateDuck();
	this->updateCollision();
}

void Game::updateTestPlayer()
{
	this->testPlayer->update();
}

void Game::updateDuck()
{
	this->duck->update();
}

void Game::TestUpdateCollision()
{
	//Collision bottom of screen
	if (this->testPlayer->getGlobalBounds().top + this->testPlayer->getGlobalBounds().height > this->window->getSize().y)
	{
		this->testPlayer->resetVelocityY();
		this->testPlayer->setPosition(this->testPlayer->getGlobalBounds().left, this->window->getSize().y - this->testPlayer->getGlobalBounds().height);
	}
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->duck->getGlobalBounds().top + this->duck->getGlobalBounds().height > this->window->getSize().y)
	{
		this->duck->resetVelocityY();
		this->duck->setPosition(this->duck->getGlobalBounds().left, this->window->getSize().y - this->duck->getGlobalBounds().height);
	}
}

//Functions
void Game::update()
{
	pollEvents();
}

void Game::renderTestPlayer()
{
	this->testPlayer->render(*this->window);
}

void Game::renderDuck()
{
	this->duck->render(*this->window);
}

void Game::render()
{
	/*
		Renders the game objects
	*/

	this->window->clear(sf::Color::Blue);

	//Draw game objects
	//this->renderTestPlayer();
	this->renderDuck();

	this->window->display();
}
