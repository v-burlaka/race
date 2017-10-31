#include <ctime>

#include "TwoRoadsOutput.h"
#include "FourRoadsOutput.h"
#include "Menu.h"

void main()
{
	srand(time(0));
	Car car;
	Menu menu;
	Counter counter;
	Barrier barrier;
	menu.setLevel();
	if (menu.getLevel() == 1)
	{
		TwoRoadsOutput console;
		counter.startTimeCalculation();
		while (console.gameStatusCheck())
		{
			console.outGame(car, counter, barrier);
		}
		console.outResult(counter, car);
	}
	else
	{
		FourRoadsOutput console;
		counter.startTimeCalculation();
		while (console.gameStatusCheck())
		{
			console.outGame(car, counter, barrier);
		}
		console.outResult(counter, car);
	}
	_sleep(1000);
	system("pause");
}