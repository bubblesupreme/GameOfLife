#include "MainMenu.h"
#include "../Global/RegulateSound.h"

extern User user;


MainMenu::MainMenu(sf::RenderWindow* window)
	: simpleGame(window), levelGame(window), tutorial(window), window(window), patterns(window)
	, simpleGameButt(window, window->getSize().x*0.25, window->getSize().y / 6*4.2, "",TOP, resources->italic, resources->Play)
	, levelGameButt(window, window->getSize().x / 16, window->getSize().y / 5*2.3, "", TOP, resources->italic, resources->Levels)
	, tutorialButt(window, window->getSize().x / 2*0.9, window->getSize().y / 2*0.6, "", TOP, resources->italic, resources->Tutorial)
	, patternsButt(window, window->getSize().x / 15*11, window->getSize().y / 5 * 2.7, "", TOP, resources->italic, resources->Patterns)
	, switchUsersButt(window, window->getSize().x / 15 * 10.7, window->getSize().y / 5 * 4.3, "", TOP, resources->italic, resources->switchUser)
	, swichUsers(window)
	, sound(window, window->getSize().x / 15 * 13, window->getSize().y / 20, "off", TOP, resources->italic, resources->soundOff)
	, soundRegul(window, window->getSize().x / 15 * 14, window->getSize().y / 20, "volume", TOP, resources->italic, resources->soundRegular)
{
	menuPicture.setTextureRect(sf::Rect<int>(0, 0, int(window->getSize().x), int(window->getSize().y)));
	menuTexture.loadFromFile("resources/buttons/MainMenu.jpg");
	menuPicture.setTexture(menuTexture);
	hello.setString("  Hello, " + user.getName()+"!  Start your game!");
	hello.setFillColor(sf::Color(90, 86, 209));
	hello.setFont(*resources->italic);
	hello.setCharacterSize(20);
	hello.setPosition(window->getSize().x / 2- hello.getGlobalBounds().width/2, window->getSize().y*0.23);
	resources->game->setLoop(true);
	sf::Texture* homyak=new sf::Texture;
	homyak->loadFromFile("resources/buttons/homyakHello.png");
	homyakHello.setTexture(*homyak);
	homyakHello.setScale(0.2, 0.2);
	homyakHello.setPosition(window->getSize().x / 15 * 11, window->getSize().y / 5 * 2.7- homyakHello.getGlobalBounds().height*0.9);
}


MainMenu::~MainMenu()
{
}


void MainMenu::demonstrate()
{

	sf::Event event;
	while (window->isOpen())
	{

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
			simpleGameButt.handleEvent(event);
			levelGameButt.handleEvent(event);
			tutorialButt.handleEvent(event);
			patternsButt.handleEvent(event);
			switchUsersButt.handleEvent(event);
			soundRegul.handleEvent(event);
			sound.handleEvent(event);
			if (simpleGameButt.getClicked())
			{
				simpleGame.play();
			}
			if (levelGameButt.getClicked())
			{
				levelGame.play();
			}
			if (tutorialButt.getClicked())
			{
				tutorial.demonstrate();
			}
			if (patternsButt.getClicked())
			{
				patterns.play();
			}
			if (switchUsersButt.getClicked())
			{
				swichUsers.demonstrate();
			}
			if (sound.getClicked())
			{
				if (sound.getTexture() == resources->soundOff)
				{
					sound.setTexture(resources->soundOn);
					sound.setString("on");
					resources->game->play();
				}
				else
				{
					sound.setTexture(resources->soundOff);
					sound.setString("off");
					resources->game->pause();
				}
			}
			if (soundRegul.getClicked() && sound.getTexture() == resources->soundOn)
			{
				soundRegulate();
			}
		}
		hello.setString("Hello, " + user.getName() + "!  Start your game!");

		if (resources->game->getStatus() == sf::Music::Playing
			&& sound.getTexture() == resources->soundOff)
		{
			sound.setTexture(resources->soundOn);
			sound.setString("On");
		}
		else
			if (resources->game->getStatus() == sf::Music::Paused
				&& sound.getTexture() == resources->soundOn)
			{
				sound.setTexture(resources->soundOff);
				sound.setString("Off");
			}

		draw();
	}
	//tutorial.demonstrate();
}

void MainMenu::draw()
{
	window->clear();
	window->draw(menuPicture);
	window->draw(hello);
	window->draw(homyakHello);
	simpleGameButt.draw();
	levelGameButt.draw();
	tutorialButt.draw();
	patternsButt.draw();
	switchUsersButt.draw();
	sound.draw();
	soundRegul.draw();
	window->display();
}