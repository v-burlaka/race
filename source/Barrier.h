#ifndef BARRIER_H
#define BARRIER_H

class Barrier
{
public:
	void setSide();
	void setSideFourRoads();
	int getSide() const;
private:
	int side_;
};
#endif