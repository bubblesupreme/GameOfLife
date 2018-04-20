#ifndef MENUPATTERN_H
#define MENUPATTERN_H

#include "ButtonN.h"
#include "Constants.h"
#include "PatternFigures.h"

class MenuPattern
{
public:
	MenuPattern(sf::RenderWindow* window);
	~MenuPattern();
	figure handlEvent(sf::Event& event, State& state);
	void draw();
private:
	int page;
	sf::RenderWindow* window;
	ButtonN play;
	ButtonN mainMenu;
	ButtonN clear;
	ButtonN sound;
	ButtonN soundRegul;
	std::vector<std::vector<ButtonN>> Buttons;
	PutternFigures figures;
	sf::RectangleShape background;
	std::vector<ButtonN> drawButtons;
};

#endif