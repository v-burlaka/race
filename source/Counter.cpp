#include "Counter.h"

Counter::Counter()
{
	distance_ = 0;
	score_ = 0;
	start_ = std::chrono::system_clock::now();
	end_ = std::chrono::system_clock::now();
	time_ = std::chrono::duration_cast<std::chrono::seconds>
		(end_ - start_).count();
}

void Counter::distaceCalculation()
{
	++distance_;
}

void Counter::scoreCalculation(const int& speed)
{
	score_ += 210 - speed;
}

void Counter::startTimeCalculation()
{
	start_ = std::chrono::system_clock::now();
}

void Counter::endTimeCalculation()
{
	end_ = std::chrono::system_clock::now();
}

int Counter::getDistance() const
{
	return distance_;
}

int Counter::getScore() const
{
	return score_;
}

int Counter::getTime()
{
	time_ = std::chrono::duration_cast<std::chrono::seconds>
		(end_ - start_).count();
	return time_;
}