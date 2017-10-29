#pragma once

class Menu
{
private:
	int level_;
	char button_;
public:
	Menu();
	void setLevel();
	int getLevel() const;
};