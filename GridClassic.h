#ifndef GRIDCLASSIC_H
#define GRIDCLASSIC_H

#include "Grid.h"

class GridClassic:public Grid
{
public:
	GridClassic(int widht, int height);
	GridClassic(const Grid &grid);
	~GridClassic();
	virtual void update() override;
private:
};

#endif