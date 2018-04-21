#ifndef PATTERNS_H
#define PATTERNS_H

#include "Global\Global.h"
#include "Grid\GridClassic.h"
#include "GUI elements\ButtonN.h"
#include"Menus\MenuPattern.h"
#include "Grid\Observer.h"


class Patterns
{
public:
	Patterns(sf::RenderWindow* window);
	~Patterns();
	void draw();
	void play();
private:
	GridClassic grid;
	sf::RenderWindow* window;
	State state;
	sf::Text patternName;
	Observer observer;
	//ButtonN start;
	sf::RectangleShape nameRect;
	MenuPattern menu;
	figure patternFigure;
};

#endif