#include <iostream>
#include <conio.h>

#include "FourRoadsOutput.h"

FourRoadsOutput::FourRoadsOutput()
{
	isGame = true;
	isCheckSide = true;
}

void FourRoadsOutput::gameOver(const int& i, User& user, Barrier& barrier, Counter& counter) 
{
	if (user.getSide() < 1 || user.getSide() > 4)
	{
		isGame = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	if (i >= (ROAD_LENGHT - 1) && user.getSide() == barrier.getSide())//the user's machine is drawn from (ROAD_LECHT - 1)
	{
		isGame = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

void FourRoadsOutput::outResult(Counter& counter, User& user) const
{
	std::cout << "speed:" << user.getSpeedForConsole()
		<< " distance: " << counter.getDistance()
		<< " score: " << counter.getScore()
		<< " time:" << counter.getTime() << std::endl;
}

bool FourRoadsOutput::gameStatusCheck() const
{
	return isGame;
}

void FourRoadsOutput::drawCar(User& user) const
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

void FourRoadsOutput::drawCarOnFirstSide() const
{
	std::cout << "|   __   |        ||        |        |\n"
		<< "| [|__|] |        ||        |        |\n"
		<< "|  |__|  |        ||        |        |\n"
		<< "| [|==|] |        ||        |        |\n";
}

void FourRoadsOutput::drawCarOnSecondSide() const
{
	std::cout << "|        |   __   ||        |        |\n"
		<< "|        | [|__|] ||        |        |\n"
		<< "|        |  |__|  ||        |        |\n"
		<< "|        | [|==|] ||        |        |\n";
}

void FourRoadsOutput::drawCarOnThirdSide() const
{
	std::cout << "|        |        ||   __   |        |\n"
		<< "|        |        || [|__|] |        |\n"
		<< "|        |        ||  |__|  |        |\n"
		<< "|        |        || [|==|] |        |\n";
}

void FourRoadsOutput::drawCarOnFourthSide() const
{
	std::cout << "|        |        ||        |   __   |\n"
		<< "|        |        ||        | [|__|] |\n"
		<< "|        |        ||        |  |__|  |\n"
		<< "|        |        ||        | [|==|] |\n";
}

void FourRoadsOutput::drawBarrierFourRoads(const int &i, Barrier& barrier) const
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

void FourRoadsOutput::drawBarrierOnFirstSide() const
{
	std::cout << "|   __   |        ||        |        |\n"
		<< "| [|__|] |        ||        |        |\n"
		<< "|  |__|  |        ||        |        |\n"
		<< "| [|==|] |        ||        |        |\n";
}

void FourRoadsOutput::drawBarrierOnSecondSide() const
{
	std::cout << "|        |   __   ||        |        |\n"
		<< "|        | [|__|] ||        |        |\n"
		<< "|        |  |__|  ||        |        |\n"
		<< "|        | [|==|] ||        |        |\n";
}

void FourRoadsOutput::drawBarrierOnThirdSide() const
{
	std::cout << "|        |        ||   __   |        |\n"
		<< "|        |        || [|==|] |        |\n"
		<< "|        |        ||  |__|  |        |\n"
		<< "|        |        || [|__|] |        |\n";
}

void FourRoadsOutput::drawBarrierOnFourthSide() const
{
	std::cout << "|        |        ||        |   __   |\n"
		<< "|        |        ||        | [|==|] |\n"
		<< "|        |        ||        |  |__|  |\n"
		<< "|        |        ||        | [|__|] |\n";
}

void FourRoadsOutput::cleanTheTopOfTheRoad(const int& i) const
{
	system("cls");
	for (int y = 0; y < i; ++y)
		std::cout << "|        |        ||        |        |\n";
}

void FourRoadsOutput::outGame(User& user, Counter& counter, Barrier& barrier)
{
	barrier.setSideBarrierFourRoads();
	for (int i = 0, count = 0; i < ROAD_LENGHT; ++i)
	{
		if (kbhit())
			user.inputButtonCheck();
		if (user.getSide() > 2 && isCheckSide)
		{
			isCheckSide = false;
			user.setSpeed();
		}
		else if (user.getSide() < 3 && !isCheckSide)
		{
			isCheckSide = true;
			user.reestablishSpeed();
		}
		if (i == count)
		{
			count += 3;//draw the car every third iteration
			counter.distaceCalculation();
			counter.scoreCalculation(user.getSpeed());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrierFourRoads(i, barrier);
			for (int j = i; j < ROAD_LENGHT - 4; ++j)//leave 4 lines to draw the user's machine
				std::cout << "|        |        ||        |        |\n";
			drawCar(user);
			outResult(counter, user);
		}
		counter.endTimeCalculation();
		gameOver(i, user, barrier, counter);
		if (!isGame)
			break;
		_sleep(user.getSpeed());
	}
}