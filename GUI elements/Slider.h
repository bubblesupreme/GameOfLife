#ifndef SLIDER_H
#define SLIDER_H

#include "SFML\Graphics.hpp"
#include "../Global/Global.h"

class Slider
{
public:
	Slider( Position position, int length);
	Slider( int min, int max, Position position, int length);
	~Slider();
	void draw(sf::RenderWindow* window);
	void setPosition(Position position, int length);
	int handleEvent(sf::Event& event);
private:
	sf::RectangleShape band;
	sf::RectangleShape roller;
	sf::Text valuePos;
	const float shift = 10.0;
	float lastPos;
	bool isMousePressed;
	int pos;
	int min;
	int max;
};

#endif