#include "LevelGame.h"
#include "RegulateSound.h"
#include "windows.h"


LevelGame::LevelGame(sf::RenderWindow* window)
	:window(window), menu(window),start(window,menu.getStarterRect()->getPosition().x+ window->getSize().x/30
		,menu.getStarterRect()->getPosition().y + window->getSize().y/12,"Start",TOP,resources->lobster,resources->Play)
	, mainMenu(window,menu.getGenerationRect()->getPosition().x + window->getSize().x / 13
	, menu.getGenerationRect()->getPosition().y+ menu.getGenerationRect()->getSize().y*1.3,"Return",TOP,resources->italic,resources->last)
	, soundButt(window, window->getSize().x / 15 * 13, window->getSize().y / 20, "off", TOP, resources->italic, resources->soundOff)
	, soundRegul(window, window->getSize().x / 15 * 14, window->getSize().y / 20, "volume", TOP, resources->italic, resources->soundRegular)
{
	levelWins = user.getLevel();
}


LevelGame::~LevelGame()
{
}

void LevelGame::play()
{
	if (resources->game->getStatus() == sf::Music::Playing
		&& soundButt.getTexture() == resources->soundOff)
	{
		soundButt.setTexture(resources->soundOn);
		soundButt.setString("On");
	}
	else
		if (resources->game->getStatus() == sf::Music::Paused
			&& soundButt.getTexture() == resources->soundOn)
		{
			soundButt.setTexture(resources->soundOff);
			soundButt.setString("Off");
		}
	levelWins = user.getLevel();
	sf::Sprite backgrund;
	sf::Texture backgTexture;
	backgTexture.loadFromFile("buttons//Levels.jpg");
	backgrund.setTextureRect(sf::Rect<int>(0, 0, int(window->getSize().x), int(window->getSize().y)));
	backgrund.setTexture(backgTexture);
	Size sizeLevelTexture(resources->levels[0]->getSize().x, resources->levels[0]->getSize().y);
	ButtonN menu(window, window->getSize().x / 2 * 0.9, window->getSize().y / 16 * 15.3, "", TOP, resources->italic, resources->MainMenu);
	int levelCount = 30;

	for (int i = 0; i < levelCount; i++)
	{
		levelButtons.push_back(ButtonN(window,( i % 6 )* (sizeLevelTexture.first + window->getSize().x / 29)+ window->getSize().x / 14
			, i / 6 * (sizeLevelTexture.second + window->getSize().y / 18) + window->getSize().y / 5, "", TOP, resources->italic, resources->levels[i]));
	}

	sf::Event event;
	while (window->isOpen()) {

		while (window->pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
			menu.handleEvent(event);
			soundRegul.handleEvent(event);
			soundButt.handleEvent(event);
			for (int i = 0; i <= levelWins; i++)
			{
				if (i != 30)
				{
					levelButtons[i].handleEvent(event);
				}
			}
			for (int i = 0; i <= levelWins; i++)
			{
				if (i != 30)
				{
					if (levelButtons[i].getClicked())
					{
						level(i + 1);
					}
				}

			}
			if (menu.getClicked())
			{
				user.setLevel(levelWins);
				return;
			}
			if (soundButt.getClicked())
			{
				if (soundButt.getTexture() == resources->soundOff)
				{
					soundButt.setTexture(resources->soundOn);
					soundButt.setString("on");
					resources->game->play();
				}
				else
				{
					soundButt.setTexture(resources->soundOff);
					soundButt.setString("off");
					resources->game->pause();
				}
			}
			if (soundRegul.getClicked() && soundButt.getTexture() == resources->soundOn)
			{

				soundRegulate();
			}
		}


		window->clear();
		window->draw(backgrund);
		soundButt.draw();
		soundRegul.draw();
		menu.draw();
		for (int i = 0; i < levelCount; i++)
		{
			levelButtons[i].draw();
		}
		window->display();
	}
}

void LevelGame::level(int levelNum)
{
	bool** startGrid;

	int rows =0;
	int columns=0;

	startGrid = nullptr;

	switch (levelNum)
	{
	case 1:
		menu.levelNum = 1;
		menu.cells = 19;
		menu.starter = 0;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level1) / sizeof(levelBlanks.level1[0]);
		columns = sizeof(levelBlanks.level1[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level1[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 2:
		menu.levelNum = 2;
		menu.cells = 3;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level2) / sizeof(levelBlanks.level2[0]);
		columns = sizeof(levelBlanks.level2[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level2[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 3:
		menu.levelNum = 3;
		menu.cells = 4;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level3) / sizeof(levelBlanks.level3[0]);
		columns = sizeof(levelBlanks.level3[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level3[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 4:
		menu.levelNum = 4;
		menu.cells =16;
		menu.starter = 4;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level4) / sizeof(levelBlanks.level4[0]);
		columns = sizeof(levelBlanks.level4[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level4[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 5:
		menu.levelNum = 5;
		menu.cells = 3;
		menu.starter = 10;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level5) / sizeof(levelBlanks.level5[0]);
		columns = sizeof(levelBlanks.level5[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level5[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 6:
		menu.levelNum = 6;
		menu.cells = 0;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 5;
		rows = sizeof(levelBlanks.level6) / sizeof(levelBlanks.level6[0]);
		columns = sizeof(levelBlanks.level6[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level6[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 7:
		menu.levelNum = 7;
		menu.cells = 12;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level7) / sizeof(levelBlanks.level7[0]);
		columns = sizeof(levelBlanks.level7[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level7[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 8:
		menu.levelNum = 8;
		menu.cells = 5;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level8) / sizeof(levelBlanks.level8[0]);
		columns = sizeof(levelBlanks.level8[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level8[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 9:
		menu.levelNum = 9;
		menu.cells = 24;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level9) / sizeof(levelBlanks.level9[0]);
		columns = sizeof(levelBlanks.level9[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level9[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 10:
		menu.levelNum = 10;
		menu.cells = 10;
		menu.starter = 3;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 1;
		rows = sizeof(levelBlanks.level10) / sizeof(levelBlanks.level10[0]);
		columns = sizeof(levelBlanks.level10[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level10[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 11:
		menu.levelNum = 11;
		menu.cells = 0;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 80;
		rows = sizeof(levelBlanks.level11) / sizeof(levelBlanks.level11[0]);
		columns = sizeof(levelBlanks.level11[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level11[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 12:
		menu.levelNum = 12;
		menu.cells = 4;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 50;
		rows = sizeof(levelBlanks.level12) / sizeof(levelBlanks.level12[0]);
		columns = sizeof(levelBlanks.level12[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level12[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 13:
		menu.levelNum = 13;
		menu.cells = 8;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 8;
		rows = sizeof(levelBlanks.level13) / sizeof(levelBlanks.level13[0]);
		columns = sizeof(levelBlanks.level13[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level13[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 14:
		menu.levelNum = 14;
		menu.cells = 12;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level14) / sizeof(levelBlanks.level14[0]);
		columns = sizeof(levelBlanks.level14[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level14[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 15:
		menu.levelNum = 15;
		menu.cells = 28;
		menu.starter = 2;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level15) / sizeof(levelBlanks.level15[0]);
		columns = sizeof(levelBlanks.level15[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level15[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 16:
		menu.levelNum = 16;
		menu.cells = 6;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 10;
		rows = sizeof(levelBlanks.level16) / sizeof(levelBlanks.level16[0]);
		columns = sizeof(levelBlanks.level16[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level16[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 17:
		menu.levelNum = 17;
		menu.cells = 6;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 15;
		rows = sizeof(levelBlanks.level17) / sizeof(levelBlanks.level17[0]);
		columns = sizeof(levelBlanks.level17[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level17[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 18:
		menu.levelNum = 18;
		menu.cells = 0;
		menu.starter = 3;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 50;
		rows = sizeof(levelBlanks.level18) / sizeof(levelBlanks.level18[0]);
		columns = sizeof(levelBlanks.level18[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level18[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 19:
		menu.levelNum = 19;
		menu.cells = 0;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level19) / sizeof(levelBlanks.level19[0]);
		columns = sizeof(levelBlanks.level19[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level19[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 20:
		menu.levelNum = 20;
		menu.cells = 6;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level20) / sizeof(levelBlanks.level20[0]);
		columns = sizeof(levelBlanks.level20[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level20[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 21:
		menu.levelNum = 21;
		menu.cells = 25;
		menu.starter = 4;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 1;
		rows = sizeof(levelBlanks.level21) / sizeof(levelBlanks.level21[0]);
		columns = sizeof(levelBlanks.level21[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level21[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 22:
		menu.levelNum = 22;
		menu.cells = 35;
		menu.starter = 3;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 24;
		rows = sizeof(levelBlanks.level22) / sizeof(levelBlanks.level22[0]);
		columns = sizeof(levelBlanks.level22[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level22[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 23:
		menu.levelNum = 23;
		menu.cells = 22;
		menu.starter = 3;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 22;
		rows = sizeof(levelBlanks.level23) / sizeof(levelBlanks.level23[0]);
		columns = sizeof(levelBlanks.level23[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level23[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 24:
		menu.levelNum = 24;
		menu.cells = 0;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 90;
		rows = sizeof(levelBlanks.level24) / sizeof(levelBlanks.level24[0]);
		columns = sizeof(levelBlanks.level24[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level24[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 25:
		menu.levelNum = 25;
		menu.cells = 0;
		menu.starter = 2;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 3;
		rows = sizeof(levelBlanks.level25) / sizeof(levelBlanks.level25[0]);
		columns = sizeof(levelBlanks.level25[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level25[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 26:
		menu.levelNum = 26;
		menu.cells = 20;
		menu.starter = 3;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 3;
		rows = sizeof(levelBlanks.level26) / sizeof(levelBlanks.level26[0]);
		columns = sizeof(levelBlanks.level26[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level26[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 27:
		menu.levelNum = 27;
		menu.cells = 0;
		menu.starter = 8;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 20;
		rows = sizeof(levelBlanks.level27) / sizeof(levelBlanks.level27[0]);
		columns = sizeof(levelBlanks.level27[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level27[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 28:
		menu.levelNum = 28;
		menu.cells = 43;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 51;
		rows = sizeof(levelBlanks.level28) / sizeof(levelBlanks.level28[0]);
		columns = sizeof(levelBlanks.level28[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level28[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 29:
		menu.levelNum = 29;
		menu.cells = 28;
		menu.starter = 2;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 28;
		rows = sizeof(levelBlanks.level29) / sizeof(levelBlanks.level29[0]);
		columns = sizeof(levelBlanks.level29[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level29[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	case 30:
		menu.levelNum = 30;
		menu.cells = 26;
		menu.starter = 1;
		menu.population = 0;
		menu.generation = 0;
		menu.generations = 250;
		rows = sizeof(levelBlanks.level30) / sizeof(levelBlanks.level30[0]);
		columns = sizeof(levelBlanks.level30[0]);
		startGrid = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			startGrid[i] = new bool[columns];
			for (int j = 0; j < columns; j++)
			{
				startGrid[i][j] = levelBlanks.level30[i][j];
				if (startGrid[i][j])
				{
					menu.population++;
				}
			}
		}
		break;
	default:
		break;
	}
	int startCells = menu.population + menu.starter;

	GridClassic grid(sizeGridLevel.first, sizeGridLevel.second);
	Observer observer(window);
	sf::Event event;

	int posX = sizeGridLevel.first / 2 - columns / 2;
	int posY = sizeGridLevel.second / 2 - rows / 2;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			grid.setBoothAt(startGrid[i][j], posX + j, posY + i);
		}
	}
	while (window->isOpen()) {

		while (window->pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				window->close();
				return;
			}
			start.handleEvent(event);
			mainMenu.handleEvent(event);
			observer.handleEvent(&event, &grid,menu.starter);
			soundRegul.handleEvent(event);
			soundButt.handleEvent(event);
			if (start.getClicked())
			{
				while (menu.generation != menu.generations)
				{
					try
					{
						grid.update();
					}
					catch (std::exception ex)
					{
					}
					menu.generation++;
					menu.population = grid.aliveCount();
					window->clear();
					grid.draw(*window);
					menu.draw();
					mainMenu.draw();
					start.draw();
					window->display();
					Sleep(200);
				}
				if (menu.population == menu.cells)
				{
					
					if (levelNum != 30)
					{
						if (levelWins < levelNum)
						{
							levelWins = levelNum;
						}
						win();
						return;
					}
					winAll();
					return;
				}
				else
				{
					loss();
					return;
				}
				return;
			}
			if (soundButt.getClicked())
			{
				if (soundButt.getTexture() == resources->soundOff)
				{
					soundButt.setTexture(resources->soundOn);
					soundButt.setString("on");
					resources->game->play();
				}
				else
				{
					soundButt.setTexture(resources->soundOff);
					soundButt.setString("off");
					resources->game->pause();
				}
			}
			if (soundRegul.getClicked() && soundButt.getTexture() == resources->soundOn)
			{
				soundRegulate();
			}
			if (mainMenu.getClicked())
			{
				return;
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (startGrid[i][j])
					{
						grid.setBoothAt(true,posX + j, posY + i);
					}
				}
			}
			menu.starter = startCells-grid.aliveCount();
			if (menu.starter == 0 && levelNum>1)
			{
				menu.starter = 0;
			}
		}
		window->clear();
		grid.draw(*window);
		menu.draw();
		mainMenu.draw();
		start.draw();
		soundButt.draw();
		soundRegul.draw();
		window->display();
	}
	
}

void LevelGame::win()const
{
	sf::RenderWindow winWin(sf::VideoMode(300, 200), "Result", sf::Style::None);
	sf::RectangleShape background;
	background.setFillColor(sf::Color(242, 240, 240));
	background.setPosition(10, 10);
	background.setSize(sf::Vector2f(winWin.getSize().x - 2 * 10, winWin.getSize().y - 2 * 10));
	background.setOutlineThickness(10);
	background.setOutlineColor(sf::Color(182, 180, 180));

	sf::Sprite homyakWin;
	sf::Texture homyak;
	homyak.loadFromFile("buttons/homyakWin.png");
	homyakWin.setTexture(homyak);
	homyakWin.setScale(0.2, 0.2);
	homyakWin.setPosition(homyakWin.getGlobalBounds().width*0.2, winWin.getSize().y - homyakWin.getGlobalBounds().height);

	sf::Text result;
	result.setString("You win");
	result.setFillColor(sf::Color(83, 3, 189));
	result.setFont(*resources->italic);
	result.setPosition(winWin.getSize().x/2-result.getGlobalBounds().width/2
						, winWin.getSize().y /2*0.5);
	ButtonN ok(&winWin, winWin.getSize().x/2*0.8, winWin.getSize().y/5*3.5,"next level",TOP,resources->italic,resources->next);

	if (resources->game->getStatus() == sf::Music::Playing)
	{
		sound.setBuffer(*resources->win);
		sound.play();
	}

	sf::Event event;
	while (winWin.isOpen()) {
		while (winWin.pollEvent(event))
		{
			ok.handleEvent(event);
			if (ok.getClicked())
			{
				return;
			}
			if (event.type == sf::Event::Closed)
			{
				return;
			}
		}
		winWin.clear(sf::Color::White);
		winWin.draw(background);
		winWin.draw(result);
		winWin.draw(homyakWin);
		ok.draw();
		winWin.display();
	}
}

void LevelGame::loss ()const
{

	sf::RenderWindow winWin(sf::VideoMode(300, 200), "Result", sf::Style::None);
	sf::RectangleShape background;
	background.setFillColor(sf::Color(242, 240, 240));
	background.setPosition(10, 10);
	background.setSize(sf::Vector2f(winWin.getSize().x - 2 * 10, winWin.getSize().y - 2 * 10));
	background.setOutlineThickness(10);
	background.setOutlineColor(sf::Color(182, 180, 180));

	sf::Sprite homyakLoss;
	sf::Texture homyak;
	homyak.loadFromFile("buttons/homyakLoss.png");
	homyakLoss.setTexture(homyak);
	homyakLoss.setScale(0.2, 0.2);
	homyakLoss.setPosition(homyakLoss.getGlobalBounds().width*0.2, winWin.getSize().y - homyakLoss.getGlobalBounds().height);

	sf::Text result;
	result.setString("You loss");
	result.setFillColor(sf::Color(83, 3, 189));
	result.setFont(*resources->italic);
	result.setPosition(winWin.getSize().x / 2 - result.getGlobalBounds().width / 2
		, winWin.getSize().y / 2 * 0.5);
	ButtonN ok(&winWin, winWin.getSize().x / 2 * 0.8, winWin.getSize().y / 5 * 3.5, "", TOP, resources->italic, resources->ok);

	if (resources->game->getStatus() == sf::Music::Playing)
	{
		sound.setVolume(100);
		sound.setBuffer(*resources->loss);
		sound.play();
	}
	sf::Event event;
	while (winWin.isOpen()) {
		while (winWin.pollEvent(event))
		{
			ok.handleEvent(event);
			if (ok.getClicked())
			{
				return;
			}
			if (event.type == sf::Event::Closed)
			{
				return;
			}
		}
		winWin.clear(sf::Color::White);
		winWin.draw(background);
		winWin.draw(result);
		winWin.draw(homyakLoss);
		ok.draw();
		winWin.display();
	}
}

void LevelGame::winAll()const
{
	sf::RenderWindow winWin(sf::VideoMode(300, 200), "Result", sf::Style::None);
	sf::RectangleShape background;
	background.setFillColor(sf::Color(242, 240, 240));
	background.setPosition(10, 10);
	background.setSize(sf::Vector2f(winWin.getSize().x - 2 * 10, winWin.getSize().y - 2 * 10));
	background.setOutlineThickness(10);
	background.setOutlineColor(sf::Color(182, 180, 180));


	sf::Sprite homyakOoo;
	sf::Texture homyak;
	homyak.loadFromFile("buttons/homyakOoo.png");
	homyakOoo.setTexture(homyak);
	homyakOoo.setScale(0.15, 0.15);
	homyakOoo.setPosition(homyakOoo.getGlobalBounds().width*0.23, winWin.getSize().y - homyakOoo.getGlobalBounds().height);
	homyakOoo.setRotation(30);

	sf::Text result;
	result.setString("You have passed \n   all levels!");
	result.setFillColor(sf::Color(83, 3, 189));
	result.setFont(*resources->italic);
	result.setPosition(winWin.getSize().x / 2 - result.getGlobalBounds().width / 2
		, winWin.getSize().y / 2 * 0.15);
	ButtonN ok(&winWin, winWin.getSize().x / 2 * 0.8, winWin.getSize().y / 5 * 3.5, "Excellent!", TOP, resources->italic, resources->ok);

	if (resources->game->getStatus() == sf::Music::Playing)
	{
		sound.setBuffer(*resources->winAll);
		sound.play();
	}

	sf::Event event;
	while (winWin.isOpen()) {
		while (winWin.pollEvent(event))
		{
			ok.handleEvent(event);
			if (ok.getClicked())
			{
				return;
			}
			if (event.type == sf::Event::Closed)
			{
				return;
			}
		}
		winWin.clear(sf::Color::White);
		winWin.draw(background);
		winWin.draw(result);
		winWin.draw(homyakOoo);
		ok.draw();
		winWin.display();
	}
}