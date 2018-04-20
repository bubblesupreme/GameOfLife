#ifndef Textbox_H
#define Textbox_H

#include "Constants.h"


class Textbox 
{
public:
	Textbox(sf::RenderWindow * window, float x, float y, float width, float height);
	void draw();
	 void handleEvent(const sf::Event& event) ;
	 void Textbox::SetPosition(float x, float y);
	 void SetSize(float width, float height) ;
	 std::string getText();
private:
	sf::RenderWindow * window;
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Font font;
	sf::Text text;
	int fontSize;
	sf::Color fontColor;
	sf::Color areaColor;
	sf::RectangleShape area;
	sf::Vector2f areaSize;
	sf::Vector2f areaPosition;
	bool button;
	sf::RectangleShape cursor;
	bool cursorActive;
	int numChar;
	int cursorLastNum;
};

#endif

