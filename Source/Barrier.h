#ifndef BARRIER_H
#define BARRIER_H

class Barrier
{
public:
	Barrier();
	void setSide();
	void setSideFourRoads();
	inline int getSide() const;
private:
	int side_;
};

int Barrier::getSide() const
{
	return side_;
}
#endif