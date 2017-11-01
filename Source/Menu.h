#ifndef MENU_H
#define MENU_H

#include "Helper.h"

class Menu
{
public:
	void outMenu(const int& punkt_);
	void checkParagraph();
	void setParagraph();
	void setLevel();
	void outParagraph(const int& punkt_);
	void outRecords();
	void gameRules();
	void startGame();
	inline int getLevel() const;
private:
	int paragraph_ = 1;
	int level_ = 1;
	char button_;
};

int Menu::getLevel() const
{
	return level_;
}
#endif 