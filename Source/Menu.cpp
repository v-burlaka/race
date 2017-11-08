#include <iostream>
#include <fstream>
#include <conio.h>

#include "Menu.h"
#include "FourRoadsOutput.h"
#include "TwoRoadsOutput.h"
#include "Counter.h"

using namespace race;

Menu::Menu() : paragraph_(1), level_(1)
{
}

void Menu::outMenu(const int& paragraph_)
{
		switch (paragraph_)
		{
		case FIRST_PARAGRAPH: system("cls");
			std::cout << "Start game <---\n"
				<< "Highscore table\n"
				<< "Rules\n"
				<< "Exit";
			break;
		case SECOND_PARAGRAPH: system("cls");
			std::cout << "Start game\n" 
				<< "Highscore table <---\n"
				<< "Rules\n"
				<< "Exit";
			break;
		case THIRD_PARAGRAPH: system("cls");
			std::cout << "Start game\n" 
				<< "Highscore table \n"
				<< "Rules <---\n"
				<< "Exit";
			break;
		case FOURTH_PARAGRAPH: system("cls");
			std::cout << "Start game\n" 
				<< "Highscore table \n"
				<< "Rules\n"
				<< "Exit <---";
			break;
		default: break;
		}
}

void Menu::setParagraph()
{
	std::cout << "Start game <---\n"
		<< "Highscore table\n"
		<< "Rules\n"
		<< "Exit";
	paragraph_ = 1;
	while (button_ != ENTER)
	{
		button_ = getch();
		switch (button_)
		{
		case UP: --paragraph_;
			checkParagraph();
			outMenu(paragraph_);
			break;
		case DOWN: ++paragraph_;
			checkParagraph();
			outMenu(paragraph_);
			break;
		default: break;
		}
	}
	outParagraph(paragraph_);
}

void Menu::outParagraph(const int& paragraph_)
{
	switch (paragraph_)
	{
	case FIRST_PARAGRAPH: system("cls");
		setLevel();
		break;
	case SECOND_PARAGRAPH: system("cls");
		outRecords();
		break;
	case THIRD_PARAGRAPH: system("cls");
		gameRules();
		break;
	case FOURTH_PARAGRAPH: exit(0);
		break;
	default: break;
	}
}

void Menu::gameRules() 
{
	char buff[100];
	int i = 0;
	std::ifstream fin("Rules.txt");

	if (!fin.is_open())
	{
		std::cout << "File con not be opened!";
		return;
	}
	while (!fin.eof())
	{
		fin.getline(buff, 100);
		std::cout << buff << std::endl;
		++i;
	}
	fin.close();
	while (button_ != ESC)
	{
		button_ = getch();
	}
	system("cls");
	setParagraph();
}

void Menu::outRecords() 
{
	char buff[100];
	int i = 0;
	std::ifstream fin("Records.txt");

	if (!fin.is_open())
	{
		std::cout << "File con not be opened!";
		return;
	}
	while (!fin.eof())
	{
		fin.getline(buff, 100);
		std::cout << buff << std::endl;
		++i;
	}
	fin.close();
	std::cout << "ESC - back";
	while (button_ != ESC)
	{
		button_ = getch();
	}
	system("cls");
	setParagraph();
}

void Menu::checkParagraph()
{
	if (paragraph_ < FIRST_PARAGRAPH)
	{
		paragraph_ = FOURTH_PARAGRAPH;
	}
	if (paragraph_ > FOURTH_PARAGRAPH)
	{
		paragraph_ = FIRST_PARAGRAPH;
	}
}

void Menu::setLevel()
{
	std::cout << "Choise level:\n"
		<< "Two roads  <---\n"
		<< "Four roads ";
	button_ = 0;
	while (button_ != ENTER)
	{
		button_ = getch();
		switch (button_)
		{
		case UP: level_ = FIRST_LEVEL;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads  <---\n"
				<< "Four roads";
			break;
		case DOWN: level_ = SECOND_LEVEL;
			system("cls");
			std::cout << "Choise level:\n"
				<< "Two roads\n"
				<< "Four roads <---";
			break;
		default: break;
		}
	}
}

void Menu::startGame()
{
	Car car;
	Barrier barrier;
	Counter counter;
	setParagraph();
	if (getLevel() == 1)
	{
		TwoRoadsOutput console;
		counter.startTimeCalculation();
		while (console.gameStatusCheck())
		{
			console.outGame(car, counter, barrier);
		}
		console.outResult(counter, car);
		counter.saveScore(*this);
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
		counter.saveScore(*this);
	}
	button_ = 0;
	system("cls");
	startGame();
}