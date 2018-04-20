#ifndef PATTERNS_H
#define PATTERNS_H

#include "Constants.h"
#include "GridClassic.h"
#include"ButtonN.h"
#include"MenuPattern.h"
#include "Observer.h"


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