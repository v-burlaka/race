#pragma once

class User
{
private:
	int side_;
	int speed_;
public:
	User();
	void inputButtonCheck();
	void setSpeed();
	void reestablishSpeed();
	int getSide() const;
	int getSpeed() const;
	int getSpeedForConsole() const;
};