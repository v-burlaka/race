#include "Counter.h"

void Counter::distaceCalculation()
{
	++distance_;
}

void Counter::scoreCalculation(const int& speed)
{
	score_ +=  speed;
}

void Counter::startTimeCalculation()
{
	start_ = std::chrono::system_clock::now();
}

void Counter::endTimeCalculation()
{
	end_ = std::chrono::system_clock::now();
}

void Counter::saveScore(Menu& menu)
{
	char name[15];
	std::cout << "Enter you name: ";
	std::cin.getline(name, 15);
	std::ofstream fout;
	fout.open("Records.txt", std::ios::app);
	if (!fout)
	{
		std::cout << "File con not be opened!";
		return;
	}
	fout << "distance: " << getDistance() 
		<< " | score: " << getScore() 
		<< " | time: " << getTime()
		<< " | level: " << menu.getLevel() 
		<< " | name: " << name << std::endl;
	fout.close();
}