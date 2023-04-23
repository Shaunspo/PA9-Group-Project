#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using sf::RenderWindow;
using sf::CircleShape;
using sf::Color;
using sf::VideoMode;
using sf::Event;


int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Test Render");
	CircleShape testshape(100.f);
	testshape.setFillColor(Color::Blue);

	while (window.isOpen())
	{
		Event testEvent;
		while (window.pollEvent(testEvent))
		{
			if (testEvent.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(testshape);
		window.display();

	}



	return 0;
}