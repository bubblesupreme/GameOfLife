#ifndef LEVELGAME_H
#define LEVELGAME_H

#include "GridClassic.h"
#include"Observer.h"
#include "MenuLevel.h"
#include "ButtonN.h"

class LevelGame
{
public:
	LevelGame(sf::RenderWindow* window);
	~LevelGame();
	void play();
private:
	void level(int levelNum);
	void win() const;
	void winAll() const;
	void loss() const;
	sf::RenderWindow* window;
	State state;
	int levelWins;
	MenuLevel menu;
	ButtonN start;
	ButtonN mainMenu;
	ButtonN soundButt;
	ButtonN soundRegul;
	std::vector<ButtonN> levelButtons;
};

#endif