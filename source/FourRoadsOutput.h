#pragma once
#include "Barrier.h"
#include "User.h"
#include "Counter.h"

class FourRoadsOutput
{
	const int roadLenght = 20;
	bool gameStatus;
	bool checkSide;
public:
	FourRoadsOutput();
	void drawCar(User&);
	void drawCarOnFirstSide();
	void drawCarOnSecondSide();
	void drawCarOnThirdSide();
	void drawCarOnFourthSide();
	void drawBarrierFourRoads(const int&, Barrier&);
	void drawBarrierOnFirstSide();
	void drawBarrierOnSecondSide();
	void drawBarrierOnThirdSide();
	void drawBarrierOnFourthSide();
	void cleanTheTopOfTheRoad(const int&);
	void outGame(User&, Counter&, Barrier&);
	void gameOver(const int&, User&, Barrier&, Counter&);
	bool gameStatusCheck();
	void outResult(Counter&, User&);
};