#include "Patterns.h"
#include "windows.h"


Patterns::Patterns(sf::RenderWindow* window)
	:grid(sizeGridLevel.first, sizeGridLevel.second-2)
	,window(window),menu(window), patternFigure("",nullptr,0,0)
	,state(MODIFYING), observer(window)
{
	nameRect.setSize(sf::Vector2f(sizeGridLevel.first*sizeBooth, 2 * sizeBooth));
	nameRect.setPosition(0, window->getSize().y-nameRect.getSize().y);
	nameRect.setFillColor(sf::Color(176, 170, 247));
	patternName.setString("");
	patternName.setFillColor(sf::Color(68, 65, 149));
	patternName.setFont(*resources->italic);
	patternName.setCharacterSize(20);
	patternName.setPosition(nameRect.getPosition().x + nameRect.getSize().x / 20
		, nameRect.getPosition().y + nameRect.getSize().y / 10);
}


Patterns::~Patterns()
{
}

void Patterns::play()
{
	sf::Event event;
	figure pattern("", nullptr, 0, 0);
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
			observer.handleEvent(&event, &grid, state);
			try
			{
				pattern = menu.handlEvent(event, state);
			}

			catch (int ex)
			{
				switch (ex)
				{
				case 1:
					return;
				case 2:
					grid.clear();
					patternName.setString("");
					break;
				default:
					break;
				}
			}

			if (pattern.pattern != nullptr)
			{
				patternFigure = pattern;
				std::string name = patternFigure.name;
				std::size_t found = name.find("-\n");
				if (found != std::string::npos)
					name.replace(found, 3, " ");
				found = name.find("\n");
				if (found != std::string::npos)
					name.replace(name.find("\n"), 2, " ");
				patternName.setString(name);
				int posX = sizeGridLevel.first / 2 - pattern.columns / 2;
				int posY = sizeGridLevel.second / 2 - pattern.rows / 2;

				grid.clear();
				for (int i = 0; i < pattern.rows; i++)
				{
					for (int j = 0; j < pattern.columns; j++)
					{
						grid.setBoothAt(*(pattern.pattern + i*pattern.columns + j), posX + j, posY + i);
					}
				}
			}
		}
			if (state == UPDATING)
			{
				try
				{
					grid.update();
				}
				catch (std::exception ex)
				{}
				Sleep(200);
			}
		
		draw();
	}
}

void Patterns::draw()
{
	window->clear();
	window->draw(nameRect);
	window->draw(patternName);
	menu.draw();
	grid.draw(*window);
	window->display();
}