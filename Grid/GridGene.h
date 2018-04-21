#ifndef GRIDGENE_H
#define GRIDGENE_H

#include "Grid.h"

class GridGene : public Grid
{
public:
	GridGene(int widht, int height);
	GridGene(const GridGene &grid);
	~GridGene();
	virtual void update() override;
private:
};

#endif