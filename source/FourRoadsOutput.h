#ifndef FOUR_ROADS_OUTPUTS_H
#define FOUR_ROADS_OUTPUTS_H

#include "Barrier.h"
#include "Car.h"
#include "Counter.h"

class FourRoadsOutput
{
public:
	FourRoadsOutput();
	void drawCar(Car& car) const;
	void drawCarOnFirstSide() const;
	void drawCarOnSecondSide() const;
	void drawCarOnThirdSide() const;
	void drawCarOnFourthSide() const;
	void drawBarrier(const int& i, Barrier& barrier) const;
	void drawBarrierOnFirstSide() const;
	void drawBarrierOnSecondSide() const;
	void drawBarrierOnThirdSide() const;
	void drawBarrierOnFourthSide() const;
	void cleanTheTopOfTheRoad(const int& i) const;
	void outGame(Car& car, Counter& counter, Barrier& barrier);
	void gameOver(const int& i, Car& car, Barrier& barrier, Counter& counter);
	bool gameStatusCheck() const;
	void outResult(Counter& counter, Car& car) const;
private:
	const int COLLISION_POINT = 19;
	const int ROAD_LENGHT = 20;
	bool isGame_;
	bool isCheckSide_;
};
#endif