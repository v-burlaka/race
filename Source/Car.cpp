#include <conio.h>
#include <iostream>

#include "Car.h"

using namespace race;

void Car::speedCheck()
{
	if (speed_ > MAX_SPEED)
	{
		speed_ = MAX_SPEED;
	}
	if (speed_ < MIN_SPEED)
	{
		speed_ = MIN_SPEED;
	}
}

void Car::inputButtonCheck()
{
	char button;
	button = getch();
	switch (button)
	{
	case LEFT: --side_;
		break;
	case RIGHT: ++side_;
		break;
	case DOWN: speed_ += 30;
		break;
	case UP: speed_ -= 30;
		break;
	case ENTER: system("pause");
		break;
	case ESC: exit(0);
		break;
	default: break;
	}
	speedCheck();
}

void Car::setSpeed()
{
	if (side_ == THIRD_SIDE)
	{
		speed_ -= 30;
	}
	if (speed_ < 0)
	{
		speed_ = 0;
	}
	speedCheck();
}

void Car::reestablishSpeed()
{
	speed_ += 30;
	speedCheck();
}
