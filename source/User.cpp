#include <conio.h>//getch() and kbhit()
#include <iostream>

#include "User.h"

User::User()
{
	side_ = 1;
	speed_ = 100;
}

void User::inputButtonCheck()
{
	char button;
	button = getch();
	switch (button)
	{
	case 75: --side_;
		break;
	case 77: ++side_;
		break;
	case 80: speed_ += 30;
		break;
	case 72: speed_ -= 30;
		break;
	case 13: system("pause");
		break;
	case 27: exit(0);
		break;
	default: break;
	}
	if (speed_ > 200)
		speed_ = 200;
	if (speed_ < 10)
		speed_ = 10;
}

void User::setSpeed()
{
	if (side_ == 3 || side_ == 4)
	{
		speed_ -= 30;
	}
	if (speed_ < 0)
		speed_ = 0;
}

void User::reestablishSpeed()
{
	speed_ += 30;
}

int User::getSide() const
{
	return side_;
}

int User::getSpeed() const
{
	return speed_;
}

int User::getSpeedForConsole() const
{
	return 210 - speed_;
}