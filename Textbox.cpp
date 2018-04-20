#include "Textbox.h"





Textbox::Textbox(sf::RenderWindow * window, float x, float y, float width, float height)
	: window(window), pos(x, y), size(width, height), font(*(resources->italic)),cursorActive(false)
	, cursorLastNum(0), numChar(0), fontColor(sf::Color::Black)
	, areaColor(sf::Color(142, 255, 169)), areaSize(width, height), areaPosition(x, y)
{
	fontSize = areaSize.y / 1.5;
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	area.setFillColor(areaColor);
	area.setPosition(areaPosition);
	area.setSize(areaSize);
	text.setPosition(areaPosition.x*1.01, areaPosition.y+ areaSize.y*1/5);
	cursor.setSize(sf::Vector2f(1, fontSize));
	cursor.setFillColor(fontColor);
}

std::string Textbox::getText()
{
	return text.getString();
}

void Textbox::handleEvent(const sf::Event & event)
{
	sf::String inputString;
	sf::String textString;

	if (numChar > 1)
	{
		textString = text.getString();
		size_t f;
		if ((f=textString.find("_"))!= std::string::npos)
		{
			textString.erase(f);
			text.setString(textString);
		}
	}

	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left 
			&& event.mouseButton.x > areaPosition.x 
			&& event.mouseButton.x < areaPosition.x + areaSize.x 
			&& event.mouseButton.y > areaPosition.y 
			&& event.mouseButton.y < areaPosition.y + areaSize.y)
		{

			button = true;
			if (numChar == 0)
			{

				textString = text.getString();
				textString.insert(0, "_");
				text.setString(textString);

				cursorLastNum = 0;
				numChar++;
				cursorActive = false;
			}
			else
			{
				sf::Vector2f tmpCourse;
				int tmpX_right;
				int tmpX_left;
				int tmpY_top;
				int tmpY_bottom;
				int tmpX_middle;

				int min = 2000;

				for (int i = 0; i < numChar; i++)
				{
					tmpX_right = text.findCharacterPos(i + 1).x;
					tmpX_left = text.findCharacterPos(i).x;
					tmpY_top = text.findCharacterPos(i).y;
					tmpY_bottom = text.findCharacterPos(i).y + fontSize;
					tmpX_middle = tmpX_left + ((tmpX_right - tmpX_left) / 2);

					if (event.mouseButton.y > tmpY_top 
						&& event.mouseButton.y < tmpY_bottom 
						&& event.mouseButton.x > tmpX_left 
						&& event.mouseButton.x < tmpX_right)
					{
						if (abs(event.mouseButton.x - tmpX_middle)<min)
						{
							min = abs(event.mouseButton.x - tmpX_middle);
							cursorLastNum = i;
						}
					}
				}

				tmpX_left = text.getGlobalBounds().left+ text.getGlobalBounds().width;
				tmpY_top = text.findCharacterPos(numChar).y;
				tmpY_bottom = text.findCharacterPos(numChar).y + fontSize;
				if (event.mouseButton.y > tmpY_top
					&& event.mouseButton.y < tmpY_bottom
					&& event.mouseButton.x > tmpX_left)
				{
					if (abs(event.mouseButton.x - tmpX_middle)<min)
					{
						min = abs(event.mouseButton.x - tmpX_middle);
						cursorLastNum = numChar;
					}
				}
			}
			cursorActive = true;
		}
		else
		{
			button = false;
			cursorActive = false;
		}
		break;
	}
	case sf::Event::TextEntered:
	{
		if (button)
		{

			if (event.text.unicode >= 65 && event.text.unicode <= 127)
			{

				if (areaSize.x > text.getGlobalBounds().width+3*fontSize)
				{

					inputString = text.getString();
					inputString.insert(cursorLastNum, (char)event.text.unicode);

					text.setString(inputString);

					numChar++;
					cursorLastNum++;

				}
			}
			

			cursorActive = true;
		}
		break;
	}

	case sf::Event::KeyPressed:
		if (button)
		{

			if (event.key.code==sf::Keyboard::BackSpace)
			{

				if(numChar>0)
				{

					inputString = text.getString();
					inputString.erase(cursorLastNum-1);

					text.setString(inputString);

					numChar--;
					cursorLastNum--;

				}
			}

			if (event.key.code == sf::Keyboard::Right)
			{
				if (cursorLastNum < numChar)
				{
					cursorLastNum++;
				}
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				if (cursorLastNum >0)
				{
					cursorLastNum--;
				}
			}
			cursorActive = true;
		}
		break;

	default:
		break;
	}
	float k = text.findCharacterPos(cursorLastNum).x;
	cursor.setPosition(text.findCharacterPos(cursorLastNum).x, text.findCharacterPos(cursorLastNum).y);
}

void Textbox::SetPosition(float x, float y)
{
	areaPosition.x = x;
	areaPosition.y = y;
}

void Textbox::SetSize(float width, float height)
{
	areaSize = sf::Vector2f(width, height);
}


void Textbox::draw()
{
	
	window->draw(area);
	window->draw(text);
	if (cursorActive)
	{
		window->draw(cursor);
	}
	//printf("--%d %d %d %d\n", area.getPosition().x, area.getPosition().y,area.getSize().x, area.getSize().y);
}