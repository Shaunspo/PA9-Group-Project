#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/04B_30__.ttf"))
	{
		cout << "missing font" << endl;
	}

	//play game option
	menuOptions[0].setFont(font);
	menuOptions[0].setFillColor(Color::White);
	menuOptions[0].setString("Play Game!");
	menuOptions[0].setCharacterSize(30);
	menuOptions[0].setPosition(270, 200);

	//rules option
	menuOptions[1].setFont(font);
	menuOptions[1].setFillColor(Color::White);
	menuOptions[1].setString("Rules");
	menuOptions[1].setCharacterSize(30);
	menuOptions[1].setPosition(330, 280);

	//about option
	menuOptions[2].setFont(font);
	menuOptions[2].setFillColor(Color::White);
	menuOptions[2].setString("About");
	menuOptions[2].setCharacterSize(30);
	menuOptions[2].setPosition(330, 360);

	//exit option
	menuOptions[3].setFont(font);
	menuOptions[3].setFillColor(Color::White);
	menuOptions[3].setString("Exit");
	menuOptions[3].setCharacterSize(30);
	menuOptions[3].setPosition(350, 440);

	menuSelected = -1;
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow& window) //draws all of the menu options
{
	for (int i = 0; i < MAX_OPTIONS; ++i)
	{
		window.draw(menuOptions[i]);
	}
}

void Menu::moveUp()
{
	if (menuSelected - 1 >= 0)
	{
		menuOptions[menuSelected].setFillColor(Color::White);
		menuSelected--;
		if (menuSelected == -1)
		{
			menuSelected = 2;
		}
		menuOptions[menuSelected].setFillColor(Color::Yellow);
	}
}

void Menu::moveDown()
{
	if (menuSelected + 1 <= MAX_OPTIONS)
	{
		menuOptions[menuSelected].setFillColor(Color::White);
		menuSelected++;
		if (menuSelected == 4)
		{
			menuSelected = 0;
		}
		menuOptions[menuSelected].setFillColor(Color::Yellow);
	}
}