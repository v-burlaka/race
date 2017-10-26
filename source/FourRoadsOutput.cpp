#include "FourRoadsOutput.h"
#include <iostream>
#include <conio.h>

FourRoadsOutput::FourRoadsOutput()
{
	gameStatus = true;
	checkSide = true;
}

void FourRoadsOutput::gameOver(const int& i, User& user, Barrier& barrier, Counter& counter)
{
	if (user.getSide() < 1 || user.getSide() > 4)
	{
		gameStatus = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	if (i >= (roadLenght - 2) && user.getSide() == barrier.getSide())
	{
		gameStatus = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

void FourRoadsOutput::outResult(Counter& counter, User& user)
{
	std::cout << "speed:" << user.getSpeedForConsole() << " distance: " << counter.getDistance() << " score: " << counter.getScore() << " time:" << counter.getTime() << std::endl;
}

bool FourRoadsOutput::gameStatusCheck()
{
	return gameStatus;
}

void FourRoadsOutput::drawCar(User& user)
{
	switch (user.getSide())
	{
	case 1: drawCarOnFirstSide();
		break;
	case 2: drawCarOnSecondSide();
		break;
	case 3: drawCarOnThirdSide();
		break;
	case 4: drawCarOnFourthSide();
		break;
	default: break;
	}
}

void FourRoadsOutput::drawCarOnFirstSide()
{
	std::cout << "|   __   |        ||        |        |\n"
		<< "| [|__|] |        ||        |        |\n"
		<< "|  |__|  |        ||        |        |\n"
		<< "| [|==|] |        ||        |        |\n";
}

void FourRoadsOutput::drawCarOnSecondSide()
{
	std::cout << "|        |   __   ||        |        |\n"
		<< "|        | [|__|] ||        |        |\n"
		<< "|        |  |__|  ||        |        |\n"
		<< "|        | [|==|] ||        |        |\n";
}

void FourRoadsOutput::drawCarOnThirdSide()
{
	std::cout << "|        |        ||   __   |        |\n"
		<< "|        |        || [|__|] |        |\n"
		<< "|        |        ||  |__|  |        |\n"
		<< "|        |        || [|==|] |        |\n";
}

void FourRoadsOutput::drawCarOnFourthSide()
{
	std::cout << "|        |        ||        |   __   |\n"
		<< "|        |        ||        | [|__|] |\n"
		<< "|        |        ||        |  |__|  |\n"
		<< "|        |        ||        | [|==|] |\n";
}

void FourRoadsOutput::drawBarrierFourRoads(const int &i, Barrier& barrier)
{
	for (int j = 0; j < i; ++j)
		std::cout << "|        |        ||        |        |\n";
	switch (barrier.getSide())
	{
	case 1: drawBarrierOnFirstSide();
		break;
	case 2: drawBarrierOnSecondSide();
		break;
	case 3: drawBarrierOnThirdSide();
		break;
	case 4: drawBarrierOnFourthSide();
		break;
	default: break;
	}
}

void FourRoadsOutput::drawBarrierOnFirstSide()
{
	std::cout << "|   __   |        ||        |        |\n"
		<< "| [|__|] |        ||        |        |\n"
		<< "|  |__|  |        ||        |        |\n"
		<< "| [|==|] |        ||        |        |\n";
}

void FourRoadsOutput::drawBarrierOnSecondSide()
{
	std::cout << "|        |   __   ||        |        |\n"
		<< "|        | [|__|] ||        |        |\n"
		<< "|        |  |__|  ||        |        |\n"
		<< "|        | [|==|] ||        |        |\n";
}

void FourRoadsOutput::drawBarrierOnThirdSide()
{
	std::cout << "|        |        ||   __   |        |\n"
		<< "|        |        || [|==|] |        |\n"
		<< "|        |        ||  |__|  |        |\n"
		<< "|        |        || [|__|] |        |\n";
}

void FourRoadsOutput::drawBarrierOnFourthSide()
{
	std::cout << "|        |        ||        |   __   |\n"
		<< "|        |        ||        | [|==|] |\n"
		<< "|        |        ||        |  |__|  |\n"
		<< "|        |        ||        | [|__|] |\n";
}

void FourRoadsOutput::cleanTheTopOfTheRoad(const int& i)
{
	system("cls");
	for (int y = 0; y < i; ++y)
		std::cout << "|        |        ||        |        |\n";
}

void FourRoadsOutput::outGame(User& user, Counter& counter, Barrier& barrier)
{
	barrier.setSideBarrierFourRoads();
	for (int i = 0, count = 0; i < roadLenght; ++i)
	{
		if (kbhit())
			user.inputButtonCheck();
		if (user.getSide() > 2 && checkSide)
		{
			checkSide = false;
			user.setSpeed();
		}
		else if (user.getSide() < 3 && !checkSide)
		{
			checkSide = true;
			user.reestablishSpeed();
		}
		if (i == count)
		{
			counter.distaceCalculation();
			counter.scoreCalculation(user.getSpeed());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrierFourRoads(i, barrier);
			count += 3;
			for (int j = i; j < roadLenght - 5; ++j)
				std::cout << "|        |        ||        |        |\n";
			drawCar(user);
			outResult(counter, user);
		}
		counter.endTimeCalculation();
		gameOver(i, user, barrier, counter);
		if (!gameStatus)
			break;
		_sleep(user.getSpeed());
	}
}