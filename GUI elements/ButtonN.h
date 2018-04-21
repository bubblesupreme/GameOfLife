#ifndef BUTTONN_H
#define BUTTONN_H

#include "../Global/StateEnum.h"
#include<SFML\Graphics.hpp>


class ButtonN
{
public:
	ButtonN(sf::RenderWindow* window, float posX, float posY, const std::string& text
		, textSide side, sf::Font *font, sf::Texture* texture);
	~ButtonN();
	bool getClicked() const;
	void handleEvent(const sf::Event& event);
	void draw();
	void setTexture(sf::Texture* texture);
	const sf::Rect<int>& getRect() const;
	const sf::Texture* getTexture() const;
	void setString(const std::string& text);
	void setRect(const sf::Rect<int> rect);
	void setPosisition(const int x, const int y);
	void setCharacterSize(const int size);
	void setScale(const float percentX, const float percentY);
private :
	void textPos();
	sf::Vector2f scale;
	bool clicked;
	bool textActiv;
	sf::Rect<int> rect;
	sf::RenderWindow* window;
	sf::Text text;
	sf::Font *font;
	sf::Texture* texture;
	sf::Sprite button;
	textSide side;
};

#endif