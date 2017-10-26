#include "Barrier.h"
#include <iostream>

void Barrier::setSideBarrier()
{
	side = 1 + rand() % 2;
}

void Barrier::setSideBarrierFourRoads()
{
	side = 1 + rand() % 4;
}

int Barrier::getSide()
{
	return side;
}