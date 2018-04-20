#ifndef MAINMENU_H
#define MAINMENU_H

#include "SimpleGame.h"
#include "LevelGame.h"
#include "Tutorial.h"
#include "Patterns.h"
#include "SwichUsers.h"

class MainMenu
{
public:
	MainMenu(sf::RenderWindow* window);
	~MainMenu();
	void demonstrate();
private:
	void draw();
	sf::RenderWindow* window;
	SimpleGame simpleGame;
	LevelGame levelGame;
	Tutorial tutorial;
	Patterns patterns;
	SwichUsers swichUsers;
	ButtonN simpleGameButt;
	ButtonN levelGameButt;
	ButtonN tutorialButt;
	ButtonN patternsButt;
	ButtonN switchUsersButt;
	ButtonN sound;
	ButtonN soundRegul;
	sf::Text hello;
	sf::Sprite menuPicture;
	sf::Texture menuTexture;
	sf::Sprite homyakHello;
};

#endif