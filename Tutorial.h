#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Grid\GridClassic.h"
#include "Grid\BoothGene.h"
#include "GUI elements\ButtonN.h"

class Tutorial
{
public:
	Tutorial(sf::RenderWindow* window);
	~Tutorial();
	void demonstrate();
private:
	sf::RenderWindow* window;
	void draw();
	sf::Sprite tutorialPicture;
	sf::Texture tutorialTexture;
	int observ;
	ButtonN next;
	ButtonN last;
	ButtonN mainMenu;
};

#endif