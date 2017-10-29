#include <iostream>

#include "Barrier.h"

void Barrier::setSideBarrier()
{
	side = 1 + rand() % 2;
}

void Barrier::setSideBarrierFourRoads()
{
	side = 1 + rand() % 4;
}

int Barrier::getSide() const
{
	return side;
}