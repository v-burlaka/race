#pragma once
#include <chrono>

class Counter
{
	int distance;
	int score;
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> end;
	int time;
public:
	Counter();
	void distaceCalculation();
	void scoreCalculation(const int&);
	void startTimeCalculation();
	void endTimeCalculation();
	int getTime();
	int getDistance() const;
	int getScore() const;
};