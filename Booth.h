#ifndef BOOTH_H
#define BOOTH_H

#include<SFML\Graphics.hpp>
#include "Constants.h"

class Booth
{
public:
	Booth(int x, int y, bool alive);
	Booth();
	~Booth();
	bool isAlive() const;
	void setAlive(const bool alive);
	const sf::RectangleShape * getShape() const;
	void draw(sf::RenderWindow& window) const;
	void choiceColor(const Booth& next);
	void choiceColor();
protected:
	bool alive;
	sf::RectangleShape shape;
};

#endif