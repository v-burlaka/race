#include "User.h"
#include <conio.h>//getch() and kbhit()
#include <iostream>

User::User()
{
	side = 1;
	speed = 100;
}

void User::inputButtonCheck()
{
	char button;
	button = getch();
	switch (button)
	{
	case 75: --side;
		break;
	case 77: ++side;
		break;
	case 80: speed += 30;
		break;
	case 72: speed -= 30;
		break;
	case 13: system("pause");
		break;
	case 27: exit(0);
		break;
	default: break;
	}
	if (speed > 200)
		speed = 200;
	if (speed < 10)
		speed = 10;
}

void User::setSpeed()
{
	if (side == 3 || side == 4)
	{
		speed -= 30;
	}
	if (speed < 0)
		speed = 0;
}

void User::reestablishSpeed()
{
	speed += 30;
}

int User::getSide()
{
	return side;
}

int User::getSpeed()
{
	return speed;
}

int User::getSpeedForConsole()
{
	return 210 - speed;
}