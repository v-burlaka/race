#include <conio.h>
#include <iostream>

#include "Car.h"

Car::Car()
{
	side_ = 1;
	speed_ = 100;
}

void Car::speedCheck()
{
	if (speed_ > MAX_SPEED)
		speed_ = MAX_SPEED;
	if (speed_ < MIN_SPEED)
		speed_ = MIN_SPEED;
}

void Car::inputButtonCheck()
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
	speedCheck();
}

void Car::setSpeed()
{
	if (side_ == 3)
		speed_ -= 30;
	if (speed_ < 0)
		speed_ = 0;
	speedCheck();
}

void Car::reestablishSpeed()
{
	speed_ += 30;
	speedCheck();
}

int Car::getSide() const
{
	return side_;
}

int Car::getSpeed() const
{
	return speed_;
}

int Car::getSpeedForConsole() const
{
	return (MAX_SPEED + MIN_SPEED) - speed_;
}

int Car::getLenght() const
{
	return LENGHT;
}