#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Game.h"

using sf::RenderWindow;
using sf::CircleShape;
using sf::Color;
using sf::VideoMode;
using sf::Event;
using sf::Texture;
using sf::Sprite;

//int main()
//{
//	Texture map;
//	Sprite background;
//	if (map.loadFromFile("gameconcept2.png"))
//	{
//		std::cout << "Error unable to load map background!" << std::endl;
//	}
//
//	background.setTexture(map);
//
//	RenderWindow window(VideoMode(1920, 1080), "Test Render");
//	CircleShape testshape(100.f);
//	testshape.setFillColor(Color::Blue);
//
//	while (window.isOpen())
//	{
//		Event testEvent;
//		while (window.pollEvent(testEvent))
//		{
//			if (testEvent.type == Event::Closed)
//				window.close();
//		}
//		window.clear();
//		
//		window.draw(background);
//
//		window.draw(testshape);
//
//		
//
//		window.display();
//
//	}
//
//
//
//	return 0;
//}

/*
	Main function using game class
*/
int main()
{
	Game game;

	sf::View cam(sf::Vector2f(0.f, 0.f), sf::Vector2f(800.f, 600.f));

	game.preLoop();

	//Game loop
	while (game.getWindowIsOpen())
	{
		cam.setCenter(game.getPlayerPos());
		//Update
		game.update();

		//Render
		game.render();
		game.setView(cam);
	}
}