#include "Slider.h"



Slider::Slider( Position position, int length)
	:pos(50),min(0),max(100), isMousePressed(false)
{
	
	band.setSize(sf::Vector2f(length, length / 50));
	band.setPosition(position.first, position.second);
	band.setFillColor(sf::Color(176, 170, 247));
	roller.setFillColor(sf::Color(68, 65, 149));
	roller.setSize(sf::Vector2f(length / 50, length / 50*1.5));
	roller.setPosition(band.getPosition().x+band.getSize().x*(float(pos) / 100) -roller.getSize().x/2
						,band.getPosition().y-(roller.getSize().y-band.getSize().y)/2);
	valuePos.setString(std::to_string(pos));
	valuePos.setFont(*resources->italic);
	valuePos.setCharacterSize(10);
	valuePos.setFillColor(sf::Color(68, 65, 149));
	valuePos.setPosition(roller.getPosition().x - 10, roller.getPosition().y - 15);
}

Slider::Slider( int min, int max, Position position, int length)
	: max(max), min(min),pos(50), isMousePressed(false)
{
	band.setSize(sf::Vector2f(length, length / 50));
	band.setPosition(position.first, position.second);
	band.setFillColor(sf::Color(176, 170, 247));
	roller.setFillColor(sf::Color(68, 65, 149));
	roller.setSize(sf::Vector2f(length / 50, length / 50 * 1.5));
	roller.setPosition(band.getPosition().x + band.getSize().x*(float(pos) / 100) - roller.getSize().x / 2
		, band.getPosition().y - (roller.getSize().y - band.getSize().y) / 2);
	valuePos.setString(std::to_string(pos));
	valuePos.setFont(*resources->italic);
	valuePos.setCharacterSize(10);
	valuePos.setFillColor(sf::Color(68, 65, 149));
	valuePos.setPosition(roller.getPosition().x - 10, roller.getPosition().y - 15);
}

Slider::~Slider()
{
}

void Slider::setPosition(Position position, int length)
{
	band.setSize(sf::Vector2f(length, length / 50));
	band.setPosition(position.first, position.second);
	roller.setSize(sf::Vector2f(length / 50, length / 50 * 1.5));
	roller.setPosition(band.getPosition().x + band.getSize().x*(float(pos) / 100) - roller.getSize().x / 2
		, band.getPosition().y - (roller.getSize().y - band.getSize().y) / 2);
}

void Slider::draw(sf::RenderWindow* window)
{
	window->draw(band);
	window->draw(roller);
	window->draw(valuePos);
}

int Slider::handleEvent(sf::Event& event)
{
	float hh = roller.getSize().x / 2;
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			if ((event.mouseButton.x > band.getPosition().x) &&
				(event.mouseButton.x < band.getPosition().x + band.getSize().x + hh) &&
				(event.mouseButton.y > roller.getPosition().y) &&
				(event.mouseButton.y < roller.getPosition().y + roller.getSize().y)) {

				if (event.mouseButton.x < roller.getPosition().x) {

					if (roller.getPosition().x - (shift/100)*band.getSize().x < band.getPosition().x) {
						roller.move(band.getPosition().x - roller.getPosition().x, 0.0f);
					}
					else {
						roller.move( -(shift / 100)*band.getSize().x, 0.0f);
					}
				}
				else {
					if (event.mouseButton.x > roller.getPosition().x + roller.getSize().x) {
						if ((roller.getPosition().x + roller.getSize().x + (shift / 100)*band.getSize().x)
																> (band.getPosition().x + band.getSize().x + hh))
						{
							roller.move(band.getPosition().x + band.getSize().x + hh -
								roller.getPosition().x - roller.getSize().x, 0.0f);
						}
						else {
							roller.move((shift / 100)*band.getSize().x, 0.0f);
						}
					}
					else {
						if (!isMousePressed) {
							isMousePressed = true;
							lastPos = event.mouseButton.x;
						}
					}
				}
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left) {
			isMousePressed = false;
		}
		break;
	case sf::Event::MouseMoved:
		if (isMousePressed) {
			if (roller.getPosition().x + event.mouseMove.x - lastPos < band.getPosition().x)
			{
				roller.move(band.getPosition().x - roller.getPosition().x, 0.0f);
				lastPos = event.mouseMove.x;
			}
			else {
				if (roller.getPosition().x + event.mouseMove.x - lastPos > band.getPosition().x + band.getSize().x + hh - roller.getSize().x) {
					float temp = band.getPosition().x + band.getSize().x + hh - roller.getPosition().x - roller.getSize().x;
					if ((roller.getPosition().x + roller.getSize().x) == (band.getPosition().x + band.getSize().x + hh))
						temp = 0;
					roller.move(temp, 0.0f);
					lastPos = roller.getPosition().x;
				}
				else {
					roller.move(event.mouseMove.x - lastPos, 0.0f);
					lastPos = event.mouseMove.x;
				}
			}
		}
		break;
	default:
		break;
	}
	pos =100*(roller.getPosition().x+ (roller.getSize().x/ 2- band.getPosition().x))/ band.getSize().x;
	valuePos.setString(std::to_string(pos));
	valuePos.setPosition(roller.getPosition().x - 10, roller.getPosition().y - 15);
	return pos;
}