#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	Menu();
	void setLevel();
	int getLevel() const;
private:
	int level_;
	char button_;
};
#endif 