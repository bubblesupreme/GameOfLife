#include "MenuLevel.h"



MenuLevel::MenuLevel(sf::RenderWindow* window)
	:levelNum(0),window(window)
{
	background.setFillColor(sf::Color(176,170,247));
	background.setSize(sf::Vector2f(window->getSize().x - sizeGridLevel.first*sizeBooth, window->getSize().y));
	background.setPosition(sizeGridLevel.first*sizeBooth,0);
	font = *resources->lobster;
	levelNumT.setFont(font);
	goalT.setFont(font);
	starterT.setFont(font);
	generationT.setFont(font);
	levelNumT.setCharacterSize(35);
	goalT.setCharacterSize(18);
	starterT.setCharacterSize(18);
	generationT.setCharacterSize(18);

	float sizeBackgroundX= background.getSize().x;
	float sizeBackgroundY = background.getSize().y;
	goalRect.setSize(sf::Vector2f(sizeBackgroundX*0.8, sizeBackgroundY/6));
	starterRect.setSize(sf::Vector2f(sizeBackgroundX*0.8, sizeBackgroundY / 4));
	generationRect.setSize(sf::Vector2f(sizeBackgroundX*0.8, sizeBackgroundY / 9));

	float posBackgroundX = background.getPosition().x;
	float posBackgroundY = background.getPosition().y;
	goalRect.setPosition(posBackgroundX+ sizeBackgroundX*0.1, (sizeBackgroundY / 6)*1.3);
	starterRect.setPosition(posBackgroundX + sizeBackgroundX*0.1, (sizeBackgroundY / 5)*2.1);
	generationRect.setPosition(posBackgroundX + sizeBackgroundX*0.1, (sizeBackgroundY / 6)*4.2);

	goalRect.setOutlineThickness(2);
	goalRect.setFillColor(sf::Color::Transparent);
	goalRect.setOutlineColor(sf::Color(0, 0, 0));
	starterRect.setOutlineThickness(2);
	starterRect.setFillColor(sf::Color::Transparent);
	starterRect.setOutlineColor(sf::Color(0, 0, 0));
	generationRect.setOutlineThickness(2);
	generationRect.setFillColor(sf::Color::Transparent);
	generationRect.setOutlineColor(sf::Color(0, 0, 0));

	levelNumT.setPosition(posBackgroundX+ sizeBackgroundX*0.25,goalRect.getPosition().y/2);
	goalT.setPosition(posBackgroundX + sizeBackgroundX*0.2, goalRect.getPosition().y+10);
	starterT.setPosition(posBackgroundX + sizeBackgroundX*0.2, starterRect.getPosition().y+10);
	generationT.setPosition(posBackgroundX + sizeBackgroundX*0.2, generationRect.getPosition().y+10);

	levelNumT.setFillColor(sf::Color(83, 3, 189));
	goalT.setFillColor(sf::Color(83, 3, 189));
	starterT.setFillColor(sf::Color(83, 3, 189));
	generationT.setFillColor(sf::Color(83, 3, 189));
}

sf::RectangleShape* MenuLevel::getStarterRect()
{
	return &starterRect;
}

sf::RectangleShape* MenuLevel::getGoalRect()
{
	return &goalRect;
}

sf::RectangleShape* MenuLevel::getGenerationRect()
{
	return &generationRect;
}

MenuLevel::~MenuLevel()
{}

void MenuLevel::draw()
{
	levelNumT.setString("Level " + std::to_string(levelNum));
	goalT.setString("Goal: Have at least " + std::to_string(cells) + " \ncells alive by the \nend of " + std::to_string(generations) + " generations");
	starterT.setString("Starter cells: " + std::to_string(starter));
	generationT.setString("Generation: " + std::to_string(generation) + "\nPopulation: " + std::to_string(population));

	window->draw(background);
	window->draw(goalRect);
	window->draw(starterRect);
	window->draw(generationRect);
	window->draw(levelNumT);
	window->draw(goalT);
	window->draw(starterT);
	window->draw(generationT);
}