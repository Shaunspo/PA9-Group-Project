#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define MAX_OPTIONS 4

class Menu
{
public:

	//constructor
	Menu(float width, float height);
	//destructor
	~Menu();

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int menuPressed()
	{
		return menuSelected;
	}

private:
	int menuSelected;
	Font font;
	Text menuOptions[MAX_OPTIONS];
	Text game_title;

}; //end of Menu class