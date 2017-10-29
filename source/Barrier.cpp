#include <iostream>

#include "Barrier.h"

void Barrier::setSideBarrier()
{
	side_ = 1 + rand() % 2;
}

void Barrier::setSideBarrierFourRoads()
{
	side_ = 1 + rand() % 4;
}

int Barrier::getSide() const
{
	return side_;
}