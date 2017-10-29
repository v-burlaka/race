#pragma once

class Barrier
{
private:
	int side_;
public:
	void setSideBarrier();
	void setSideBarrierFourRoads();
	int getSide() const;
};