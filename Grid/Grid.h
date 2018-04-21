#ifndef GRID_H
#define GRID_H

#include "BoothGene.h"

class Grid
{
public:
	Grid(int widht,int height);
	~Grid();
	void setBoothAt(const bool alive, int x, int y);
	bool isboolAliveAt(int x, int y) const;
	virtual void update()=0;
	void draw(sf::RenderWindow &window) const ;
	void draw(sf::RenderWindow &window, Grid* nextGrid) ;
	const int aliveCount() const;
	const bool operator==(const Grid& rhs) const;
	Grid(const Grid &grid);
	void clear();
	const Size getSize() const;
protected:
	int width;
	int height;
	BoothGene** boothes;
};

#endif