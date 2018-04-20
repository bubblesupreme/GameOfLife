#include "RegulateSound.h"
#include "ButtonN.h"

Slider slider(0, 100, Position(0, 0), 0);


void soundRegulate()
{
	sf::RenderWindow soundWindow(sf::VideoMode(300, 200), "", sf::Style::None);
	ButtonN ok(&soundWindow, soundWindow.getSize().x / 2 - resources->ok->getSize().x / 2
		, soundWindow.getSize().y / 4 * 2.8, "", LEFT, resources->italic, resources->ok);
	slider.setPosition(Position(soundWindow.getSize().x*0.1
		, soundWindow.getSize().y*0.5), soundWindow.getSize().x*0.8);
	sf::RectangleShape background;
	background.setFillColor(sf::Color(242, 240, 240));
	background.setPosition(10, 10);
	background.setSize(sf::Vector2f(soundWindow.getSize().x - 2 * 10, soundWindow.getSize().y - 2 * 10));
	background.setOutlineThickness(10);
	background.setOutlineColor(sf::Color(182, 180, 180));
	sf::Text headline;
	headline.setFont(*resources->italic);
	headline.setCharacterSize(25);
	headline.setString("Choose volume");
	headline.setFillColor(sf::Color(90, 86, 209));
	headline.setPosition(soundWindow.getSize().x / 2 - headline.getGlobalBounds().width / 2
		, soundWindow.getSize().y*0.05);
	sf::Event event;
	while (!ok.getClicked()) {
		while (soundWindow.pollEvent(event)) {

			ok.handleEvent(event);
			resources->game->setVolume(slider.handleEvent(event));
		}
		soundWindow.clear();
		soundWindow.draw(background);
		slider.draw(&soundWindow);
		ok.draw();
		soundWindow.draw(headline);
		soundWindow.display();
	}
	soundWindow.close();
}
