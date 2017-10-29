#pragma once
#include <chrono>

class Counter
{
private:
	int distance_;
	int score_;
	std::chrono::time_point<std::chrono::system_clock> start_;
	std::chrono::time_point<std::chrono::system_clock> end_;
	int time_;
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