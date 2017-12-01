#include <conio.h>
#include <iostream>

#include "Car.h"

using namespace race;

Car::Car() :side_(1), speed_(100)
{

}

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
	case DOWN: speed_ += SPEED_CHAING;
		break;
	case UP: speed_ -= SPEED_CHAING;
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
		speed_ -= SPEED_CHAING;
	}
	if (speed_ < MIN_SPEED)
	{
		speed_ = MIN_SPEED;
	}
	speedCheck();
}

void Car::reestablishSpeed()
{
	speed_ += SPEED_CHAING;
	speedCheck();
}
