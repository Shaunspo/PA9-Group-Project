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

void Game::setView(const sf::View& newView) {
	this->camera = newView;
}

sf::Vector2f Game::getPlayerPos() {
	return Duck->getPosition();
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
	//if (this->Duck->getGlobalBounds().top + this->Duck->getGlobalBounds().height > this->window->getSize().y)
	//{
	//	this->Duck->resetVelocityY();
	//	this->Duck->setPosition(this->Duck->getGlobalBounds().left, this->window->getSize().y - this->Duck->getGlobalBounds().height);
	//	this->Duck->setGrounded(true);
	//}
	//Collision with platform
	for (int i = 0; i < 50; i++)
	{	
		if (this->Duck->getGlobalBounds().intersects(this->TestLevel.getGroundShape(i).getGlobalBounds()))
		{
			// Right side collision
			if (this->Duck->getGlobalBounds().left <= this->TestLevel.getGroundXpos(i) + this->TestLevel.getGroundWidth(i) && this->Duck->getGlobalBounds().top - this->Duck->getGlobalBounds().height < this->TestLevel.getGroundHeight(i))
			{
				this->Duck->resetVelocityX();
				this->Duck->setPosition(this->TestLevel.getGroundXpos(i) + this->TestLevel.getGroundWidth(i) - 5.f, this->Duck->getGlobalBounds().top);
			}
			// Left side collision
			if (this->Duck->getGlobalBounds().left + this->Duck->getGlobalBounds().width >= this->TestLevel.getGroundXpos(i) && this->Duck->getGlobalBounds().top - this->Duck->getGlobalBounds().height < this->TestLevel.getGroundHeight(i))
			{
				this->Duck->resetVelocityX();
				this->Duck->setPosition(this->TestLevel.getGroundXpos(i) - 5.f, this->Duck->getGlobalBounds().top);
			}
			// Collision with top
			else
			{
				this->Duck->resetVelocityY();
				this->Duck->setPosition(this->Duck->getGlobalBounds().left, this->TestLevel.getGroundYpos(i) - this->Duck->getGlobalBounds().height);
				this->Duck->setGrounded(true);
			}
		}
		if (this->Duck->getGlobalBounds().intersects(this->TestLevel.getThinShape(i).getGlobalBounds()))
		{
			// Right side collision
			if (this->Duck->getGlobalBounds().left <= this->TestLevel.getThinXpos(i) + this->TestLevel.getThinWidth(i) && this->Duck->getGlobalBounds().top - this->Duck->getGlobalBounds().height < this->TestLevel.getThinHeight(i))
			{
				this->Duck->resetVelocityX();
				this->Duck->setPosition(this->TestLevel.getThinXpos(i) + this->TestLevel.getThinWidth(i) - 5.f, this->Duck->getGlobalBounds().top);
			}
			// Left side collision
			if (this->Duck->getGlobalBounds().left + this->Duck->getGlobalBounds().width >= this->TestLevel.getThinXpos(i) && this->Duck->getGlobalBounds().top - this->Duck->getGlobalBounds().height < this->TestLevel.getThinHeight(i))
			{
				this->Duck->resetVelocityX();
				this->Duck->setPosition(this->TestLevel.getThinXpos(i) - 5.f, this->Duck->getGlobalBounds().top);
			}
			// Collision with top
			else
			{
				this->Duck->resetVelocityY();
				this->Duck->setPosition(this->Duck->getGlobalBounds().left, this->TestLevel.getThinYpos(i) - this->Duck->getGlobalBounds().height);
				this->Duck->setGrounded(true);
			}
		}

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

	this->window->setView(camera);

	this->window->clear(sf::Color::Blue);

	this->window->draw(background);

	if (Duck->getPosition().y < 1000) {
		background.setPosition(sf::Vector2f(Duck->getPosition().x - 610, Duck->getPosition().y - 380));
	}

	this->TestLevel.renderLevel(*this->window);

	//Draw game objects
	this->renderPlayer();

	this->window->display();
}

void Game::preLoop() {
	TestLevel.buildLevel();
	city.loadFromFile("images/sea-city-cityscape-1.png");
	background.setTexture(city);
}
