#include "ButtonN.h"
#include "../Global/Global.h"


ButtonN::ButtonN(sf::RenderWindow* window, float posX, float posY, const std::string& text
	, textSide side,  sf::Font *font, sf::Texture* texture)
	:window(window), font(font), texture(texture),side(side), scale(1,1)
	,rect(posX, posY,texture->getSize().x, texture->getSize().y)
{
	this->text.setString(text);
	this->text.setFont(*font);
	this->text.setFillColor(sf::Color::Black);
	button.setPosition(rect.left,rect.top);
	button.setTexture(*texture);
	this->text.setCharacterSize(15);
	textPos();
	
}



ButtonN::~ButtonN()
{
}

bool ButtonN::getClicked() const
{
	return clicked;
}

void ButtonN::handleEvent(const sf::Event& event)
{
	button.setScale(scale);
	if (side != CENTR)
	{
		textActiv = false;
	}
	else
	{
		textActiv = true;
	}
	clicked = false;
	int* x = new int;
	int*y = new int;
	*x = sf::Mouse::getPosition(*window).x;
	*y = sf::Mouse::getPosition(*window).y;
	if ((*x >= rect.left) && (*y >= rect.top) &&
		(*x <= rect.left+rect.width) &&
		*y <= rect.top+rect.height) 
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:

			if (event.mouseButton.button == sf::Mouse::Left) {
				if (resources->game->getStatus() == sf::Music::Playing)
				{
					sound.setBuffer(*resources->button);
					sound.play();
				}
				clicked = true;
				}

			break;

		case sf::Event::MouseButtonReleased:
			
			break;

		case sf::Event::MouseMoved:
			textActiv = true;
			button.setScale(scale.x*1.1, scale.y*1.1);
			break;
		default:
			break;
		}
	}
	delete x;
	delete y;
}

void ButtonN::draw()
{
	window->draw(button);
	if (textActiv)
	{
		window->draw(text);
	}
}

void ButtonN::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	button.setTexture(*this->texture);

}

const sf::Texture* ButtonN::getTexture() const
{
	return texture;
}

void ButtonN::setString(const std::string& text)
{
	this->text.setString(text);
}

void ButtonN::setScale(const float percentX, const float percentY)
{
	scale = (sf::Vector2f(percentX, percentY));
	button.setScale(scale);
	rect.width = rect.width*percentX;
	rect.height = rect.height*percentY;
	textPos();
}

void ButtonN::setRect(const sf::Rect<int> rect)
{
	this->rect = rect;
	button.setTextureRect(rect);
	button.setPosition(rect.left, rect.top);
	textPos();
}

void ButtonN::setPosisition(int x, int y)
{
	rect.left = x;
	rect.top = y;
	button.setPosition(rect.left, rect.top);
	textPos();
}

void ButtonN::textPos()
{
	textActiv = false;
	switch (side)
	{
	case LEFT:
		this->text.setPosition(rect.left - this->text.getGlobalBounds().width - 5
			, rect.top + rect.height / 2 - 10);
		break;

	case RIGHT:
		this->text.setPosition(rect.left + rect.width + 5
			, rect.top + rect.height / 2 - 10);
		break;

	case TOP:
		this->text.setPosition(rect.left + rect.width / 2 - this->text.getGlobalBounds().width / 2
			, rect.top - 15);
		break;
	case BOTTOM:

		this->text.setPosition(rect.left + rect.width / 2 - this->text.getGlobalBounds().width / 2
			, rect.top + rect.height + 10);
		break;
	case CENTR:
		this->text.setPosition(rect.left + rect.width / 2 - this->text.getGlobalBounds().width / 2
			, rect.top + rect.height / 4);
		textActiv = true;
		break;
	}
}

void ButtonN::setCharacterSize(const int size)
{
	text.setCharacterSize(size);
}

const sf::Rect<int>& ButtonN::getRect() const
{
	return rect;
}