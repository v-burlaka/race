#include "Counter.h"

Counter::Counter()
{
	distance = 0;
	score = 0;
	start = std::chrono::system_clock::now();
	end = std::chrono::system_clock::now();
	time = std::chrono::duration_cast<std::chrono::seconds>
		(end - start).count();
}

void Counter::distaceCalculation()
{
	++distance;
}

void Counter::scoreCalculation(const int& speed)
{
	score += 210 - speed;
}

void Counter::startTimeCalculation()
{
	start = std::chrono::system_clock::now();
}

void Counter::endTimeCalculation()
{
	end = std::chrono::system_clock::now();
}

int Counter::getDistance()
{
	return distance;
}

int Counter::getScore()
{
	return score;
}

int Counter::getTime()
{
	time = std::chrono::duration_cast<std::chrono::seconds>
		(end - start).count();
	return time;
}