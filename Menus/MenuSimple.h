#ifndef MENUSIMPLE_H
#define MENUSIMPLE_H

#include "../Grid/Grid.h"
#include "../Global/Global.h"
#include "../GUI elements/ButtonN.h"
//#include "../GUI elements/Textbox.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm>
using std::min;
using std::max;
#include <gdiplus.h>
#pragma comment(lib, "GdiPlus.lib") 

class MenuSimple
{
public:
	MenuSimple(sf::RenderWindow* window);
	~MenuSimple();
	bool handleEvent(sf::Event* event, std::vector<Grid*>& grids, State& state, bool &drawColor);
	void draw();
private:
	HBITMAP* screenDo() const;
	sf::RenderWindow* window;
	sf::RectangleShape band;
	ButtonN isPlay;
	ButtonN forward;
	ButtonN backward;
	ButtonN color;
	ButtonN sound;
	ButtonN soundRegul;
	ButtonN mainMenu;
	ButtonN screen;
	ButtonN clear;
	//sf::Music* music;
};

#endif