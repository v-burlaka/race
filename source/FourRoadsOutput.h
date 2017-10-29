#pragma once
#include "Barrier.h"
#include "User.h"
#include "Counter.h"

class FourRoadsOutput
{
	const int ROAD_LENGHT = 20;
	bool isGame;
	bool isCheckSide;
public:
	FourRoadsOutput();
	void drawCar(User&) const;
	void drawCarOnFirstSide() const;
	void drawCarOnSecondSide() const;
	void drawCarOnThirdSide() const;
	void drawCarOnFourthSide() const;
	void drawBarrierFourRoads(const int&, Barrier&) const;
	void drawBarrierOnFirstSide() const;
	void drawBarrierOnSecondSide() const;
	void drawBarrierOnThirdSide() const;
	void drawBarrierOnFourthSide() const;
	void cleanTheTopOfTheRoad(const int&) const;
	void outGame(User&, Counter&, Barrier&);
	void gameOver(const int&, User&, Barrier&, Counter&);
	bool gameStatusCheck() const;
	void outResult(Counter&, User&) const;
};