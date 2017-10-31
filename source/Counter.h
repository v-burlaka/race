#ifndef COUNTER_H
#define COUNTER_H

#include <chrono>

class Counter
{
public:
	Counter();
	void distaceCalculation();
	void scoreCalculation(const int& speed);
	void startTimeCalculation();
	void endTimeCalculation();
	int getTime();
	int getDistance() const;
	int getScore() const;
private:
	int distance_;
	int score_;
	std::chrono::time_point<std::chrono::system_clock> start_;
	std::chrono::time_point<std::chrono::system_clock> end_;
	int time_;
};
#endif 