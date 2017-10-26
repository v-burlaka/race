#include "ConsoleOutput.h"
#include <iostream>
#include <conio.h>//kbhit()

ConsoleOutput::ConsoleOutput()
{
	gameStatus = true;
}

void ConsoleOutput::gameOver(const int& i, User& user, Barrier& barrier, Counter& counter)
{
	if (user.getSide() < 1 || user.getSide() > 2)
	{
		gameStatus = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	else if (i >= (roadLenght - 2) && user.getSide() == barrier.getSide())
	{
		gameStatus = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

bool ConsoleOutput::gameStatusCheck()
{
	return gameStatus;
}

void ConsoleOutput::outResult(Counter& counter, User& user)
{
	std::cout << "speed:" << user.getSpeedForConsole() << " distance: " << counter.getDistance() << " score: " << counter.getScore() << " time:" << counter.getTime() << std::endl;
}

void ConsoleOutput::drawCar(User& user)
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

void ConsoleOutput::drawCarOnLeftSide()
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void ConsoleOutput::drawCarOnRightSide()
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void ConsoleOutput::drawBarrier(const int &i, Barrier& barrier)
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

void ConsoleOutput::drawBarrierOnLeftSide()
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void ConsoleOutput::drawBarrierOnRightSide()
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void ConsoleOutput::cleanTheTopOfTheRoad(const int& i)
{
	system("cls");
	for (int y = 0; y < i; ++y)
		std::cout << "|        |        |\n";
}

void ConsoleOutput::outGame(User& user, Counter& counter, Barrier& barrier)
{
	barrier.setSideBarrier();
	for (int i = 0, count = 0; i < roadLenght; ++i)
	{
		if (kbhit())
			user.inputButtonCheck();
		if (i == count)
		{
			counter.distaceCalculation();
			counter.scoreCalculation(user.getSpeed());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrier(i, barrier);
			count += 3; 
			for (int j = i; j < roadLenght - 5; ++j)
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