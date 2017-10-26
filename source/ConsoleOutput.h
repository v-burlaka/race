#pragma once
#include "User.h"
#include "Counter.h"
#include "Barrier.h"

class ConsoleOutput
{
	const int roadLenght = 20;
	bool gameStatus;
public:
	ConsoleOutput();
	void drawCar(User&);
	void drawCarOnLeftSide();
	void drawCarOnRightSide();
	void drawBarrier(const int&, Barrier&);
	void drawBarrierOnLeftSide();
	void drawBarrierOnRightSide();
	void cleanTheTopOfTheRoad(const int&);
	void outGame(User&, Counter&, Barrier&);
	void gameOver(const int&, User&, Barrier&, Counter&);
	bool gameStatusCheck();
	void outResult(Counter&, User&);
};
