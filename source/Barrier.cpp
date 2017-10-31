#include <iostream>

#include "Barrier.h"

void Barrier::setSide()
{
	side_ = 1 + rand() % 2;
}

void Barrier::setSideFourRoads()
{
	side_ = 1 + rand() % 4;
}

int Barrier::getSide() const
{
	return side_;
}