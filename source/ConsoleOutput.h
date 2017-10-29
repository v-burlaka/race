#pragma once
#include "User.h"
#include "Counter.h"
#include "Barrier.h"

class ConsoleOutput
{
	const int ROAD_LENGHT = 20;
	bool isGame;
public:
	ConsoleOutput();
	void drawCar(User&) const;
	void drawCarOnLeftSide() const;
	void drawCarOnRightSide() const;
	void drawBarrier(const int&, Barrier&) const;
	void drawBarrierOnLeftSide() const;
	void drawBarrierOnRightSide() const;
	void cleanTheTopOfTheRoad(const int&) const;
	void outGame(User&, Counter&, Barrier&);
	void gameOver(const int&, User&, Barrier&, Counter&);
	bool gameStatusCheck() const;
	void outResult(Counter&, User&) const;
};
