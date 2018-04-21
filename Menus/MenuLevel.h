#ifndef MENULEVEL_H
#define MENULEVEL_H

#include "../Global/Global.h"

class MenuLevel
{
public:
	MenuLevel(sf::RenderWindow* window);
	~MenuLevel();
	int levelNum;
	int cells;
	int starter;
	int population;
	int generation;
	int generations;
	void draw();
	sf::RectangleShape* getStarterRect();
	sf::RectangleShape* getGoalRect();
	sf::RectangleShape* getGenerationRect();
private:
	sf::RenderWindow* window;
	sf::Text levelNumT;
	sf::Text goalT;
	sf::Text starterT;
	sf::Text generationT;
	sf::Font font;
	sf::RectangleShape goalRect;
	sf::RectangleShape starterRect;
	sf::RectangleShape generationRect;
	sf::RectangleShape background;
};

#endif