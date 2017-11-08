#ifndef MENU_H
#define MENU_H

#include "Helper.h"

class Menu
{
public:
	Menu();
	void outMenu(const int& paragraph_);
	void checkParagraph();
	void setParagraph();
	void setLevel();
	void outParagraph(const int& paragraph_);
	void outRecords();
	void gameRules();
	void startGame();
	inline int getLevel() const;
private:
	int paragraph_;
	int level_;
	char button_;
};

int Menu::getLevel() const
{
	return level_;
}
#endif 