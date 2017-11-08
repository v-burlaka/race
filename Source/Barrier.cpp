#include <iostream>

#include "Barrier.h"

Barrier::Barrier()
{
}

void Barrier::setSide()
{
	side_ = 1 + rand() % 2;
}

void Barrier::setSideFourRoads()
{
	side_ = 1 + rand() % 4;
}

