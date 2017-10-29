#include <iostream>
#include <conio.h>//kbhit()

#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput()
{
	isGame_ = true;
}

void ConsoleOutput::gameOver(const int& i, User& user, Barrier& barrier, Counter& counter)
{
	if (user.getSide() < 1 || user.getSide() > 2)
	{
		isGame_ = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	else if (i >= (ROAD_LENGHT - 2) && user.getSide() == barrier.getSide())//the user's machine is drawn from (ROAD_LECHT - 1)
	{
		isGame_ = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

bool ConsoleOutput::gameStatusCheck() const
{
	return isGame_;
}

void ConsoleOutput::outResult(Counter& counter, User& user) const
{
	std::cout << "speed:" << user.getSpeedForConsole() 
		<< " distance: " << counter.getDistance() 
		<< " score: " << counter.getScore() 
		<< " time:" << counter.getTime() << std::endl;
}

void ConsoleOutput::drawCar(User& user) const
{
	switch (user.getSide())
	{
	case 1: drawCarOnLeftSide();
		break;
	case 2: drawCarOnRightSide();
		break;
	default: break;
	}
}

void ConsoleOutput::drawCarOnLeftSide() const
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void ConsoleOutput::drawCarOnRightSide() const
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void ConsoleOutput::drawBarrier(const int &i, Barrier& barrier) const
{
	for (int j = 0; j < i; ++j)
		std::cout << "|        |        |\n";
	switch (barrier.getSide())
	{
	case 1: drawBarrierOnLeftSide();
		break;
	case 2: drawBarrierOnRightSide();
		break;
	default: break;
	}
}

void ConsoleOutput::drawBarrierOnLeftSide() const
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void ConsoleOutput::drawBarrierOnRightSide() const
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void ConsoleOutput::cleanTheTopOfTheRoad(const int& i) const
{
	system("cls");
	for (int y = 0; y < i; ++y)
		std::cout << "|        |        |\n";
}

void ConsoleOutput::outGame(User& user, Counter& counter, Barrier& barrier)
{
	barrier.setSideBarrier();
	for (int i = 0, count = 0; i < ROAD_LENGHT; ++i)
	{
		if (kbhit())
			user.inputButtonCheck();
		if (i == count)
		{
			count += 3; //draw the car every third iteration
			counter.distaceCalculation();
			counter.scoreCalculation(user.getSpeed());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrier(i, barrier);
			for (int j = i; j < ROAD_LENGHT - 4; ++j)//leave 4 lines to draw the user's machine
				std::cout << "|        |        |\n";
			drawCar(user);
			outResult(counter, user);
		}
		counter.endTimeCalculation();		
		gameOver(i, user, barrier, counter);
		if (!gameStatusCheck())
			break;
		_sleep(user.getSpeed());
	}
}