#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include "Observer.h"
#include "MenuSimple.h"
#include "GridClassic.h"
#include "GridGene.h"
#include "ButtonN.h"
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