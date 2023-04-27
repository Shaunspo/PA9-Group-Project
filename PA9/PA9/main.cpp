#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Game.h"
#include "Menu.h"

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
	//main menu startup
	RenderWindow MENU(VideoMode(800, 600), "Main Menu", sf::Style::Default);
	Menu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//Menu background
	RectangleShape menuBackground;
	menuBackground.setSize(Vector2f(800, 600));
	Texture menuTexture;
	menuTexture.loadFromFile("images/menu.jpg");
	menuBackground.setTexture(&menuTexture);

	//Rules background
	RectangleShape rulesBackground;
	rulesBackground.setSize(Vector2f(800, 600));
	Texture rulesTexture;
	rulesTexture.loadFromFile("images/Rules.jpg"); //rules image
	rulesBackground.setTexture(&rulesTexture);

	//About background
	RectangleShape aboutBackground;
	aboutBackground.setSize(Vector2f(800, 600));
	Texture aboutTexture;
	aboutTexture.loadFromFile("images/About.jpg"); //about image
	aboutBackground.setTexture(&aboutTexture);



	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}

			if (event.type == Event::KeyReleased) //navigate menu
			{
				if (event.key.code == sf::Keyboard::W)
				{
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					mainMenu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					RenderWindow RULES(VideoMode(800, 600), "RULES");
					RenderWindow ABOUT(VideoMode(800, 600), "ABOUT");
					int o = mainMenu.menuPressed();
					if (o == 0) //PLAY GAME is chosen, any changes to the implementation of game in main must be done in here!
					{
						Game game;

						sf::View cam(sf::Vector2f(0.f, 0.f), sf::Vector2f(800.f, 600.f));

						game.preLoop();

						//Game loop
						while (game.getWindowIsOpen())
						{
							if (game.getPlayerPos().y < 1000) {
								cam.setCenter(game.getPlayerPos());
							}
							//Update
							game.update();

							//Render
							game.render();
							game.setView(cam);
						}
					}
					if (o == 1)
					{
						while (RULES.isOpen()) //rules is chosen
						{
							Event revent;
							while (RULES.pollEvent(revent)) {
								if (revent.type == Event::Closed)
								{
									RULES.close();
								}
								if (revent.type == Event::KeyPressed)
								{
									if (revent.key.code == Keyboard::Escape)
									{
										RULES.close();
									}
								}
							}
							RULES.clear();
							RULES.draw(rulesBackground);
							ABOUT.close();
							RULES.display();
						}
					}
					if (o == 2) //about is chosen
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
							RULES.close();
							ABOUT.clear();
							ABOUT.draw(aboutBackground);
							ABOUT.display();
						}
					}
					if (o == 3) //exit is chosen
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(menuBackground);
		mainMenu.draw(MENU);
		MENU.display();

	}

	return 0;
}