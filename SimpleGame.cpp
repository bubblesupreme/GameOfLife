#define  _CRT_SECURE_NO_WARNINGS

#include "SimpleGame.h"
#include "DemonstrateException.h"
#include <cstring>


SimpleGame::SimpleGame(sf::RenderWindow* window)
	:window(window), state(MODIFYING), menu(MenuSimple(window)), observer(Observer(window))
	, drawColor(false)
{}


SimpleGame::~SimpleGame()
{
}

void SimpleGame::play()
{
	bool exceptionActiv=false;
	std::exception exception;
	sf::Event event;
	if (!start())
	{
		grids.push_back(new GridClassic(sizeGrid.first, sizeGrid.second));
	}
	else
	{
		grids.push_back(new GridGene(sizeGrid.first, sizeGrid.second));
	}
	while (window->isOpen()) {

		while (window->pollEvent(event)) {

			observer.handleEvent(&event, grids, state);
			if (!menu.handleEvent(&event, grids, state, drawColor))
			{
				return;
			}
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
		}
		if (state == UPDATING) {
			grids.push_back(new GridClassic(*grids.back()));
			try
			{
				grids.back()->update();
				exceptionActiv = false;
			}
			catch (std::exception ex)
			{
				try
				{
					(grids.at(grids.size()-2))->update();
				}
				catch (std::exception ex)
				{}
				exceptionActiv = true;
				exception = ex;
				state = MODIFYING;
			}
		}
		window->clear();
		auto gridDraw = grids.end();
		gridDraw--;
		if (grids.size() > 1)
		{
			gridDraw--;
		}
		if (!drawColor)
		{
			(*gridDraw)->draw(*window);
		}
		else
		{
			if (grids.size() > 1)
			{
				auto gridDrawNext = gridDraw++;
				(*gridDraw)->draw(*window, *(gridDrawNext));
			}
			else
			{
				(*gridDraw)->draw(*window, *(gridDraw));
			}
		}
		menu.draw();
		window->display();

		if (grids.size() > 3)
		{
			for (int i = 0; i < grids.size() - 2; i++)
			{
				if (*grids.at(grids.size() - 2) == *grids[i])
				{
					exceptionActiv = true;
					std::string strEx= "Periodic figure\n";
					strEx += std::to_string(grids.size() - 2 - i)+" period";

					exception = std::exception(strEx.c_str());
				}
			}
		}
		if (exceptionActiv)
		{
			DemonstrateException exDem;
			exDem.demonstrate(exception.what());
			state = MODIFYING;
			exceptionActiv = false;
		}
	}
}

bool SimpleGame::start()
{
	sf::Sprite backgrund;
	sf::Texture backgTexture;
	backgTexture.loadFromFile("buttons//choice.jpg");
	backgrund.setTextureRect(sf::Rect<int>(0, 0, int(window->getSize().x), int(window->getSize().y)));
	backgrund.setTexture(backgTexture);
	ButtonN ClassicGameButt(window, window->getSize().x / 2 * 1.3, window->getSize().y / 6 * 3.2, "", TOP, resources->italic, resources->Classic);
	ButtonN GeneGameButt(window, window->getSize().x / 16, window->getSize().y / 5 * 1.5, "", TOP, resources->italic, resources->Gene);
	sf::Event event;
	while (1)
	{
		while (window->pollEvent(event))
		{
			ClassicGameButt.handleEvent(event);
			GeneGameButt.handleEvent(event);
			if (ClassicGameButt.getClicked())
			{
				return false;
			}
			if (GeneGameButt.getClicked())
			{
				return true;
			}
			window->clear();
			window->draw(backgrund);
			ClassicGameButt.draw();
			GeneGameButt.draw();
			window->display();
		}
	}
}
