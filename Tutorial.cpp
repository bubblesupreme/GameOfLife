#include "Tutorial.h"



Tutorial::Tutorial(sf::RenderWindow* window)
	:window(window),observ(1)
	,next(window,window->getSize().x/16*14, window->getSize().y/12*11,"Next",TOP, resources->italic, resources->next)
	, mainMenu(window, window->getSize().x/2*0.9, window->getSize().y/16*15.3 , "", TOP, resources->italic, resources->MainMenu)
	, last(window, window->getSize().x / 16, window->getSize().y/12*11, "Last", TOP, resources->italic, resources->last)
{
	tutorialPicture.setTextureRect(sf::Rect<int>(0,0,int(window->getSize().x),int( window->getSize().y)));	

}


Tutorial::~Tutorial()
{
}

void Tutorial::demonstrate()
{
	sf::Event event;
	observ = 1;
	int observAnimation = 1;;
	tutorialTexture.loadFromFile("resources\\buttons\\tutorial1.jpg");
	tutorialPicture.setTexture(tutorialTexture);
	while (window->isOpen()) 
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
			next.handleEvent(event);
			last.handleEvent(event);
			mainMenu.handleEvent(event);
			if (next.getClicked())
			{
				observ++;
				if (observ > 10)
				{
					observ = 10;
				}
				observAnimation = 1;
			}
			if (last.getClicked())
			{
				observ--;
				if (observ < 1)
				{
					observ = 1;
				}
				observAnimation = 1;
			}
			if (mainMenu.getClicked())
			{
				return;
			}
			
		}
		switch (observ)
		{
		case 1:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial1.jpg");
			break;
		case 2:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial2.jpg");
			break;
		case 3:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial3.jpg");
			break;
		case 4:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial4.jpg");
			break;
		case 5:
			observAnimation++;
			switch (observAnimation)
			{
			case 5:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial51.jpg");
				break;
			case 10:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial52.jpg");
				break;
			case 15:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial53.jpg");
				break;
			case 20:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial54.jpg");
				break;
			default:
				break;
			}

			break;
		case 6:
			observAnimation++;
			switch (observAnimation)
			{
			case 3:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial61.jpg");
				break;
			case 6:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial62.jpg");
				break;
			case 9:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial63.jpg");
				break;
			case 12:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial64.jpg");
				break;
			case 15:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial65.jpg");
				break;
			case 18:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial66.jpg");
				break;
			case 21:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial67.jpg");
				break;
			case 24:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial68.jpg");
				break;
			case 27:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial69.jpg");
				break;
			case 30:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial610.jpg");
				break;
			case 33:
				tutorialTexture.loadFromFile("resources\\buttons\\tutorial611.jpg");
				observAnimation = 1;
				break;
			default:
				break;
			}
			break;
		case 7:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial4.jpg");
			break;
		case 8:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial8.jpg");
			break;
		case 9:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial9.jpg");
			break;
		case 10:
			tutorialTexture.loadFromFile("resources\\buttons\\tutorial10.jpg");
			break;
		default:
			break;
		}
		tutorialPicture.setTexture(tutorialTexture);
		draw();
	}
}

void Tutorial::draw()
{
	window->clear();
	window->draw(tutorialPicture);
	next.draw();
	last.draw();
	mainMenu.draw();
	window->display();
}
