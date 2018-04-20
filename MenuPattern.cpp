#include "MenuPattern.h"
#include "RegulateSound.h"


MenuPattern::MenuPattern(sf::RenderWindow* window)
	:window(window)
	,play(window, 0,0, "Play", TOP, resources->lobster, resources->Play)
	, mainMenu(window, 0,0, "Return", TOP, resources->italic, resources->MainMenu)
	, clear(window, 0,0, "Clear", TOP, resources->italic, resources->clear)
	, figures(), page(0)
	, sound(window, window->getSize().x *0.55, window->getSize().y *0.93, "off", LEFT, resources->italic, resources->soundOff)
	, soundRegul(window, window->getSize().x *0.63, window->getSize().y*0.93, "volume", RIGHT, resources->italic, resources->soundRegular)
{
	background.setFillColor(sf::Color(176, 170, 247));
	background.setSize(sf::Vector2f(window->getSize().x - sizeGridLevel.first*sizeBooth, window->getSize().y));
	background.setPosition(sizeGridLevel.first*sizeBooth, 0);
	float offset = background.getPosition().x+background.getSize().x/2;
	play.setPosisition(offset -play.getTexture()->getSize().x/2
		, background.getPosition().y + background.getSize().y / 20*15);
	play.setScale(1, 0.8);
	clear.setPosisition(offset - play.getTexture()->getSize().x / 2
		, background.getPosition().y + background.getSize().y / 20 * 17);
	clear.setScale(1, 0.8);
	mainMenu.setPosisition(offset - mainMenu.getTexture()->getSize().x / 2
		, background.getPosition().y + background.getSize().y / 20 * 19);
	//returnButt.setPosisition(offset - returnButt.getTexture()->getSize().x / 2
	//	, background.getPosition().y + background.getSize().y / 20 * 17.5);
	

	std::vector<ButtonN> main;
	std::vector<ButtonN> stableButt;
	std::vector<ButtonN> centenariansButt;
	std::vector<ButtonN> oscillators2Butt;
	std::vector<ButtonN> oscillators345Butt;
	std::vector<ButtonN> oscillators678Butt;
	std::vector<ButtonN> oscillatorsLongButt;
	std::vector<ButtonN> spaceshipsButt;
	std::vector<ButtonN> reflectorsButt;
	std::vector<ButtonN> eatersButt;

	sf::Texture* buttTexture = resources->simpleButton;
	Size sizeButt(buttTexture->getSize().x*0.5, buttTexture->getSize().y*0.7);

	std::vector<figure> figuresTemp;
	figuresTemp = figures.getStable();
	for (int i=0;i<figuresTemp.size();i++)
	{
		stableButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x /45 ) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		stableButt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getCentenarians();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		centenariansButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		centenariansButt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getOscillators2();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		oscillators2Butt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		oscillators2Butt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getOscillators345();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		oscillators345Butt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		oscillators345Butt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getOscillators678();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		oscillators678Butt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		oscillators678Butt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getOscillatorsLong();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		oscillatorsLongButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		oscillatorsLongButt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getSpaceships();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		spaceshipsButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		spaceshipsButt.back().setScale(0.5, 0.7);

	}

	figuresTemp = figures.getReflectors();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		reflectorsButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		reflectorsButt.back().setScale(0.5, 0.7);
	}

	figuresTemp = figures.getEaters();
	for (int i = 0; i<figuresTemp.size(); i++)
	{
		eatersButt.push_back(ButtonN(window, (i % 3)* (sizeButt.first + background.getSize().x / 45) + background.getPosition().x *1.005
			, i / 3 * (sizeButt.second + background.getSize().y / 60) + background.getSize().y / 25
			, figuresTemp[i].name, CENTR, resources->italic, buttTexture));
		eatersButt.back().setScale(0.5, 0.7);
	}

	int i = 0;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Stable", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Oscillators\n2 period", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Oscillators\n3-5 period", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Oscillators\n6-8 period", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Oscillators\nlong period", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Spaceships", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Reflectors", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);
	i++;
	main.push_back(ButtonN(window, (i % 2)* (sizeButt.first + background.getSize().x / 6) + background.getPosition().x *1.01
		, i / 2 * (sizeButt.second + background.getSize().y / 25) + background.getSize().y / 25
		, "Eaters", CENTR, resources->italic, buttTexture));
	main.back().setScale(0.75, 1);

	Buttons.push_back(main);
	Buttons.push_back(stableButt);
	Buttons.push_back(centenariansButt);
	Buttons.push_back(oscillators2Butt);
	Buttons.push_back(oscillators345Butt);
	Buttons.push_back(oscillators678Butt);
	Buttons.push_back(oscillatorsLongButt);
	Buttons.push_back(spaceshipsButt);
	Buttons.push_back(reflectorsButt);
	Buttons.push_back(eatersButt);

	drawButtons = Buttons[0];
}


MenuPattern::~MenuPattern()
{
}

figure MenuPattern::handlEvent(sf::Event& event, State& state)
{
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
	play.handleEvent(event);
	mainMenu.handleEvent(event);
	clear.handleEvent(event);
	soundRegul.handleEvent(event);
	sound.handleEvent(event);
	for (int i=0;i< drawButtons.size();i++)
	{
		drawButtons[i].handleEvent(event);
		if (drawButtons[i].getClicked())
		{
			switch (page)
			{
			case 1:
				return figures.getStable()[i];
			case 2:
				return figures.getCentenarians()[i];
			case 3:
				return figures.getOscillators2()[i];
			case 4:
				return figures.getOscillators345()[i];
			case 5:
				return figures.getOscillators678()[i];
			case 6:
				return figures.getOscillatorsLong()[i];
			case 7:
				return figures.getSpaceships()[i];
			case 8:
				return figures.getReflectors()[i];
			case 9:
				return figures.getEaters()[i];
			case 0:
				page = i+1;
				drawButtons = Buttons[i + 1];
				mainMenu.setTexture(resources->last);
				break;
			}
		}
	}
	if (play.getClicked())
	{
		if (play.getTexture() == resources->Play)
		{
			state = UPDATING;
			play.setTexture(resources->pause);
		}
		else
		{
			state = MODIFYING;
			play.setTexture(resources->Play);
		}
	}
	if (mainMenu.getClicked())
	{
		page = 0;
		if (mainMenu.getTexture() == resources->last)
		{
			mainMenu.setTexture(resources->MainMenu);
			drawButtons = Buttons[0];
		}
		else
		{
			throw 1;
		}
	}
	if (clear.getClicked())
	{
		throw 2;
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
	return figure("",nullptr,0,0);
}

void MenuPattern::draw()
{
	window->draw(background);
	for (int i = 0; i<drawButtons.size(); i++)
	{
		drawButtons[i].draw();
	}
	play.draw();
	clear.draw();
	mainMenu.draw();
	sound.draw();
	soundRegul.draw();
	//returnButt.draw();
}