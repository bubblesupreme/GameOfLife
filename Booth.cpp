#include "Booth.h"



Booth::Booth(int x, int y, bool alive)
{
	this->shape = sf::RectangleShape(sf::Vector2f(sizeBooth, sizeBooth));
	this->shape.setPosition(x, y);
	this->alive = alive;
	this->shape.setFillColor(sf::Color(242, 240, 240));
	if (alive) {
		this->shape.setFillColor(sf::Color(90, 86, 209));
	}
	else {
		this->shape.setFillColor(sf::Color(242, 240, 240));
	}
}

Booth::Booth() {

}

Booth::~Booth()
{
}

bool Booth::isAlive() const
{
	return alive;
}

void Booth::setAlive(const bool alive)
{
	this->alive = alive;
	if (alive) {
		shape.setFillColor(sf::Color(90, 86, 209));
	}
	else {
		shape.setFillColor(sf::Color(242, 240, 240));
	}

}

const sf::RectangleShape * Booth::getShape() const
{
	return &shape;
}

void Booth::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
}

void Booth::choiceColor(const Booth& next)
{
	if (this->isAlive() && next.isAlive())
	{
		this->shape.setFillColor(sf::Color(0, 255, 60));
		return;
	}
	if (!this->isAlive() && next.isAlive())
	{
		this->shape.setFillColor(sf::Color(142, 255, 169));
		return;
	}
	if (this->isAlive() && !next.isAlive())
	{
		this->shape.setFillColor(sf::Color(107, 168, 115));
		return;
	}
	this->shape.setFillColor(sf::Color(242, 240, 240));
}

void Booth::choiceColor()
{
	if (this->isAlive() )
	{
		this->shape.setFillColor(sf::Color(90, 86, 209));
		return;
	}
	this->shape.setFillColor(sf::Color(242, 240, 240));
}