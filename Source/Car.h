#ifndef CAR_H
#define CAR_H

class Car
{
public:
	Car();
	void inputButtonCheck();
	void setSpeed();
	void reestablishSpeed();
	void speedCheck();
	int getSide() const;
	int getSpeed() const;
	int getSpeedForConsole() const;
	int getLenght() const;
private:
	int side_;
	int speed_;
	const int MAX_SPEED = 190;
	const int MIN_SPEED = 10;
	const int LENGHT = 4;
};
#endif