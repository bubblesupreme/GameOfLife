#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "Grid\Observer.h"
#include "Menus\MenuSimple.h"
#include "Grid\GridClassic.h"
#include "Grid\GridGene.h"
#include "GUI elements\ButtonN.h"
#include<iostream>

class SimpleGame
{
public:
	SimpleGame(sf::RenderWindow* window);
	~SimpleGame();
	void play();
private:
	sf::RenderWindow* window;
	State state;
	bool drawColor;
	std::vector<Grid*> grids;
	MenuSimple menu;
	Observer observer;
	bool start();
};

#endif