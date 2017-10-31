#include <iostream>
#include <conio.h>

#include "FourRoadsOutput.h"

FourRoadsOutput::FourRoadsOutput()
{
	isGame_ = true;
	isCheckSide_ = true;
}

void FourRoadsOutput::gameOver(const int& i, Car& car, Barrier& barrier, Counter& counter) 
{
	if (car.getSide() < 1 || car.getSide() > 4)
	{
		isGame_ = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	if (i >= COLLISION_POINT && car.getSide() == barrier.getSide())
	{
		isGame_ = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

void FourRoadsOutput::outResult(Counter& counter, Car& car) const
{
	std::cout << "speed:" << car.getSpeedForConsole()
		<< " distance: " << counter.getDistance()
		<< " score: " << counter.getScore()
		<< " time:" << counter.getTime() << std::endl;
}

bool FourRoadsOutput::gameStatusCheck() const
{
	return isGame_;
}

void FourRoadsOutput::drawCar(Car& car) const
{
	switch (car.getSide())
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

void FourRoadsOutput::drawBarrier(const int &i, Barrier& barrier) const
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

void FourRoadsOutput::outGame(Car& car, Counter& counter, Barrier& barrier)
{
	barrier.setSideFourRoads();
	for (int i = 0, count = 0; i < ROAD_LENGHT; ++i)
	{
		if (kbhit())
			car.inputButtonCheck();
		if (car.getSide() > 2 && isCheckSide_)
		{
			isCheckSide_ = false;
			car.setSpeed();
		}
		else if (car.getSide() < 3 && !isCheckSide_)
		{
			isCheckSide_ = true;
			car.reestablishSpeed();
		}
		if (i == count)
		{
			count += 3;
			counter.distaceCalculation();
			counter.scoreCalculation(car.getSpeedForConsole());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrier(i, barrier);
			for (int j = i; j < ROAD_LENGHT - car.getLenght(); ++j)
				std::cout << "|        |        ||        |        |\n";
			drawCar(car);
			outResult(counter, car);
		}
		counter.endTimeCalculation();
		gameOver(i, car, barrier, counter);
		if (!isGame_)
			break;
		_sleep(car.getSpeed());
	}
}