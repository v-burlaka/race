#ifndef TWO_ROADS_OUTPUT_H
#define TWO_POADS_OUTPUT_H

#include "car.h"
#include "Counter.h"
#include "Barrier.h"

class TwoRoadsOutput
{
public:
	void drawCar(Car& car) const;
	void drawCarOnLeftSide() const;
	void drawCarOnRightSide() const;
	void drawBarrier(const int& i, Barrier& barrier) const;
	void drawBarrierOnLeftSide() const;
	void drawBarrierOnRightSide() const;
	void cleanTheTopOfTheRoad(const int& i) const;
	void outGame(Car& car, Counter& counter, Barrier& barrier);
	void gameOver(const int& i, Car& car, Barrier& barrier, Counter& counter);
	inline bool gameStatusCheck() const;
	void outResult(Counter& counter, Car& car) const;
private:
	bool isGame_ = true;
};

bool TwoRoadsOutput::gameStatusCheck() const
{
	return isGame_;
}
#endif
