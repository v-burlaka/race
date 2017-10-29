#include <ctime>

#include "ConsoleOutput.h"
#include "FourRoadsOutput.h"
#include "Menu.h"

void main()
{
	srand(time(0));
	User user;
	Menu menu;
	Counter counter;
	Barrier barrier;
	menu.setLevel();
	if (menu.getLevel() == 1)
	{
		ConsoleOutput console;
		counter.startTimeCalculation();
		while (console.gameStatusCheck())
		{
			console.outGame(user, counter, barrier);
		}
		console.outResult(counter, user);
	}
	else
	{
		FourRoadsOutput console;
		counter.startTimeCalculation();
		while (console.gameStatusCheck())
		{
			console.outGame(user, counter, barrier);
		}
		console.outResult(counter, user);
	}
	_sleep(1000);
	system("pause");
}