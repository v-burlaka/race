#include <ctime>
#include <iostream>

#include "Menu.h"

void main()
{
	srand(time(0));
	Menu menu;
	menu.startGame();
	system("pause");
}