#include <iostream>
#include <conio.h>

#include "TwoRoadsOutput.h"

using namespace race;

TwoRoadsOutput::TwoRoadsOutput() : isGame_(true)
{
}

void TwoRoadsOutput::gameOver(const int& i, Car& car, Barrier& barrier, Counter& counter)
{
	if (car.getSide() < FIRST_SIDE || car.getSide() > SECOND_SIDE)
	{
		isGame_ = false;
		system("cls");
		std::cout << "Outside the road! Game Over!\n";
	}
	else if (i >= COLLISION_POINT && car.getSide() == barrier.getSide())
	{
		isGame_ = false;
		system("cls");
		std::cout << "Crash! Game Over!\n";
	}
}

void TwoRoadsOutput::outResult(Counter& counter, Car& car) const
{
	std::cout << "speed:" << car.getSpeedForConsole() 
		<< " distance: " << counter.getDistance() 
		<< " score: " << counter.getScore() 
		<< " time:" << counter.getTime() << std::endl;
}

void TwoRoadsOutput::drawCar(Car& car) const
{
	switch (car.getSide())
	{
	case FIRST_SIDE: drawCarOnLeftSide();
		break;
	case SECOND_SIDE: drawCarOnRightSide();
		break;
	default: break;
	}
}

void TwoRoadsOutput::drawCarOnLeftSide() const
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void TwoRoadsOutput::drawCarOnRightSide() const
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void TwoRoadsOutput::drawBarrier(const int &i, Barrier& barrier) const
{
	for (int j = 0; j < i; ++j)
	{
		std::cout << "|        |        |\n";
	}
	switch (barrier.getSide())
	{
	case 1: drawBarrierOnLeftSide();
		break;
	case 2: drawBarrierOnRightSide();
		break;
	default: break;
	}
}

void TwoRoadsOutput::drawBarrierOnLeftSide() const
{
	std::cout << "|   __   |        |\n"
		<< "| [|__|] |        |\n"
		<< "|  |__|  |        |\n"
		<< "| [|==|] |        |\n";
}

void TwoRoadsOutput::drawBarrierOnRightSide() const
{
	std::cout << "|        |   __   |\n"
		<< "|        | [|__|] |\n"
		<< "|        |  |__|  |\n"
		<< "|        | [|==|] |\n";
}

void TwoRoadsOutput::cleanTheTopOfTheRoad(const int& i) const
{
	system("cls");
	for (int y = 0; y < i; ++y)
	{
		std::cout << "|        |        |\n";
	}
}

void TwoRoadsOutput::outGame(Car& car, Counter& counter, Barrier& barrier)
{
	barrier.setSide();
	for (int i = 0, count = 0; i < ROAD_LENGHT; ++i)
	{
		if (kbhit())
		{
			car.inputButtonCheck();
		}
		if (i == count)
		{
			count += 3;
			counter.distaceCalculation();
			counter.scoreCalculation(car.getSpeed());
			std::cout << i;
			cleanTheTopOfTheRoad(i);
			drawBarrier(i, barrier);
			for (int j = i; j < ROAD_LENGHT - car.getLenght(); ++j)
			{
				std::cout << "|        |        |\n";
			}
			drawCar(car);
			outResult(counter, car);
		}
		counter.endTimeCalculation();		
		gameOver(i, car, barrier, counter);
		if (!gameStatusCheck())
		{
			break;
		}
		_sleep(car.getSpeed());
	}
}