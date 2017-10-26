#include "Menu.h"
#include <iostream>
#include <conio.h>

Menu::Menu()
{
	level = 1;
}

void Menu::setLevel()
{
	std::cout << "Choise level:\n"
		<< "Two roads  <---\n"
		<< "Four roads ";
	while (button != 13)
	{
		button = getch();
		switch (button)
		{
		case 72: level = 1;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads  <---\n"
				<< "Four roads";
			break;
		case 80: level = 2;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads\n"
				<< "Four roads <---";
			break;
		default: break;
		}
	}
}

int Menu::getLevel()
{
	return level;
}
