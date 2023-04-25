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
	this->window->setFramerateLimit(144);
}

void Game::initTestPlayer()
{
	this->testPlayer = new Entity();
}


//Public Functions

//Constructors / Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initTestPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->testPlayer;
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

	this->updateTestPlayer();
	this->TestUpdateCollision();
}

void Game::updateTestPlayer()
{
	this->testPlayer->update();
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

//Functions
void Game::update()
{
	pollEvents();
}

void Game::renderPlayer()
{
	this->testPlayer->render(*this->window);
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
