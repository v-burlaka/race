#ifndef CAR_H
#define CAR_H

#include "Helper.h"

using namespace race;

class Car
{
public:
	void inputButtonCheck();
	void setSpeed();
	void reestablishSpeed();
	void speedCheck();
	inline int getSide() const;
	inline int getSpeed() const;
	inline int getSpeedForConsole() const;
	inline int getLenght() const;
private:
	int side_ = 1;
	int speed_ = 100;
};


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
#endif