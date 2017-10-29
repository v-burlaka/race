#pragma once

class User
{
	int side;
	int speed;
public:
	User();
	void inputButtonCheck();
	void setSpeed();
	void reestablishSpeed();
	int getSide() const;
	int getSpeed() const;
	int getSpeedForConsole() const;
};