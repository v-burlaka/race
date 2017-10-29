#include <iostream>
#include <conio.h>

#include "Menu.h"

Menu::Menu()
{
	level_ = 1;
}

void Menu::setLevel()
{
	std::cout << "Choise level:\n"
		<< "Two roads  <---\n"
		<< "Four roads ";
	while (button_ != 13)
	{
		button_ = getch();
		switch (button_)
		{
		case 72: level_ = 1;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads  <---\n"
				<< "Four roads";
			break;
		case 80: level_ = 2;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads\n"
				<< "Four roads <---";
			break;
		default: break;
		}
	}
}

int Menu::getLevel() const
{
	return level_;
}
