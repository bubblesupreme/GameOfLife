#include "DemonstrateException.h"
#include "ButtonN.h"
#include "Constants.h"


DemonstrateException::DemonstrateException()
{
}


DemonstrateException::~DemonstrateException()
{
}

void DemonstrateException::demonstrate(std::string exStr)
{
	sf::RenderWindow exWindow(sf::VideoMode(300, 200), "", sf::Style::None);
	ButtonN ok(&exWindow, exWindow.getSize().x / 2 - resources->ok->getSize().x / 2, exWindow.getSize().y / 4 * 2.8, "", LEFT, resources->italic, resources->ok);
	sf::RectangleShape background;
	background.setFillColor(sf::Color(242, 240, 240));
	background.setPosition(10, 10);
	background.setSize(sf::Vector2f(exWindow.getSize().x - 2 * 10, exWindow.getSize().y - 2 * 10));
	background.setOutlineThickness(10);
	background.setOutlineColor(sf::Color(182, 180, 180));
	sf::Text headline;
	headline.setFont(*resources->italic);
	headline.setCharacterSize(25);
	headline.setString(exStr);
	headline.setFillColor(sf::Color(90, 86, 209));
	headline.setPosition(exWindow.getSize().x / 2 - headline.getGlobalBounds().width / 2
		, exWindow.getSize().y*0.05);
	sf::Event event;
	while (!ok.getClicked()) {
		while (exWindow.pollEvent(event)) {

			ok.handleEvent(event);
		}
		exWindow.clear();
		exWindow.draw(background);
		ok.draw();
		exWindow.draw(headline);
		exWindow.display();
	}
	if (resources->game->getStatus() == sf::Music::Playing)
	{
		sound.setBuffer(*resources->button);
		sound.play();
	}
	exWindow.close();
}