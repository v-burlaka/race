#ifndef COUNTER_H
#define COUNTER_H

#include <chrono>
#include <iostream>
#include <fstream>

#include "Menu.h"

class Counter
{
public:
	Counter();
	void distaceCalculation();
	void scoreCalculation(const int& speed);
	void startTimeCalculation();
	void endTimeCalculation();
	inline int getTime();
	inline int getDistance() const;
	inline int getScore() const;
	void saveScore(Menu& menu);
private:
	int distance_;
	int score_;
	int time_;
	std::chrono::time_point<std::chrono::system_clock> start_;
	std::chrono::time_point<std::chrono::system_clock> end_;
};

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
#endif 