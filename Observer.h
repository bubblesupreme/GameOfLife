#ifndef OBSERVER_H
#define OBSERVER_H

#include "Grid.h"
#include "Constants.h"
#include <vector>

class Observer
{
public:
	Observer(sf::RenderWindow* window);
	~Observer();
	void handleEvent(sf::Event* event, std::vector<Grid*>& grids, State& state);
	void handleEvent(sf::Event* event, Grid* grid, State& state);
	void handleEvent(sf::Event* event, Grid* grid, int limit);
private:
	sf::RenderWindow* window;
};

#endif