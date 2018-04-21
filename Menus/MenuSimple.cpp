#include "MenuSimple.h"
#include "../Global/RegulateSound.h"

GUID png = { 0x557cf406, 0x1a04, 0x11d3,{ 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };


MenuSimple::MenuSimple(sf::RenderWindow* window)
	:window(window)
	, isPlay(window, 0, 0,"play",LEFT,resources->italic,resources->start)
	, forward(window, 0, 0, "forward", LEFT, resources->italic, resources->forwardT)
	, backward(window, 0, 0, "backward", LEFT, resources->italic, resources->backwardT)
	, color(window, 0, 0, "color", LEFT, resources->italic, resources->colorTrue)
	, sound(window, 0, 0, "off", LEFT, resources->italic, resources->soundFalse)
	, soundRegul(window, 0, 0, "volume", LEFT, resources->italic, resources->soundRegulT)
	, mainMenu(window, 0, 0, "main menu", LEFT, resources->italic, resources->MainMenu2)
	, screen(window, 0, 0, "screen", LEFT, resources->italic, resources->screenT)
	, clear(window, 0, 0, "clear", LEFT, resources->italic, resources->clear1)
	//, music(resources->game)
	
{
	this->window = window;
	band.setSize(sf::Vector2f(bandWidth, window->getSize().y));
	band.setPosition(sf::Vector2f(window->getSize().x - band.getSize().x, 0));
	band.setFillColor(sf::Color(180, 180, 212));
	
	std::vector<ButtonN*> buttons;
	buttons.push_back(&isPlay);
	buttons.push_back(&forward);
	buttons.push_back(&backward);
	buttons.push_back(&color);
	buttons.push_back(&sound);
	buttons.push_back(&soundRegul);
	buttons.push_back(&clear);
	buttons.push_back(&screen);
	buttons.push_back(&mainMenu);

	std::pair<int, int> pos(band.getPosition().x
		, band.getPosition().y + band.getSize().y / 20);
	int offset(resources->start->getSize().y + band.getSize().y / 40);
	for (auto butt : buttons)
	{
		butt->setPosisition(pos.first, pos.second);
		pos.second += offset;
	}

}


MenuSimple::~MenuSimple()
{
}

bool MenuSimple::handleEvent(sf::Event* event, std::vector<Grid*>& grids, State& state, bool& drawColor)
{
	if (resources->game->getStatus() == sf::Music::Playing 
		&& sound.getTexture()== resources->soundFalse)
	{
		sound.setTexture(resources->soundTrue);
		sound.setString("On");
	}
	else
		if(resources->game->getStatus() == sf::Music::Paused
			&& sound.getTexture() == resources->soundTrue)
		{
			sound.setTexture(resources->soundFalse);
			sound.setString("Off");
		}
		isPlay.handleEvent(*event);
		forward.handleEvent(*event);
		backward.handleEvent(*event);
		color.handleEvent(*event);
		sound.handleEvent(*event);
		soundRegul.handleEvent(*event);
		screen.handleEvent(*event);
		mainMenu.handleEvent(*event);
		clear.handleEvent(*event);

		if (state==MODIFYING)
		{
			isPlay.setTexture(resources->start);
			isPlay.setString("start");
		}

		if (isPlay.getClicked()) {
			switch (state) {

			case UPDATING:
				state = MODIFYING;
				isPlay.setTexture(resources->start);
				isPlay.setString("start");
				break;

			case MODIFYING:
				state = UPDATING;
				isPlay.setTexture(resources->stop);
				isPlay.setString("stop");
				break;
			default:
				break;
			}
		}

		if (!forward.getClicked() && isPlay.getTexture()==resources->start)
		{
			state = MODIFYING;
		}
		if (isPlay.getTexture() == resources->start)
		{

				if (forward.getClicked())
				{
					state = UPDATING;
				}
				if (backward.getClicked())
				{
					state = MODIFYING;
					if (grids.size() > 1)
					{
						grids.pop_back();
					}
				}
				
		}
		if (color.getClicked())
		{
			if (drawColor)
			{
				color.setTexture(resources->colorTrue);
				color.setString("colored");
				drawColor = false;
			}
			else
			{
				color.setTexture(resources->colorFalse);
				color.setString("monochrom");
				drawColor = true;
			}
		}
		if (sound.getClicked())
		{
			if (sound.getTexture() == resources->soundFalse)
			{
				sound.setTexture(resources->soundTrue);
				sound.setString("on");
				resources->game->play();
			}
			else
			{
				sound.setTexture(resources->soundFalse);
				sound.setString("off");
				resources->game->pause();
			}
		}
		if (soundRegul.getClicked() && sound.getTexture() == resources->soundTrue)
		{
			soundRegulate();
		}
		if (clear.getClicked())
		{
			while (grids.size() > 1)
			{
				grids.pop_back();
			}
			grids.back()->clear();
		}
		if (screen.getClicked())
		{
			screenDo();
		}
		if (mainMenu.getClicked())
		{
			state = MODIFYING;
			return false;

		}

		return true;
}

void MenuSimple::draw()
{
	window->draw(band);
	isPlay.draw();
	forward.draw();
	backward.draw();
	color.draw();
	sound.draw();
	soundRegul.draw();
	mainMenu.draw();
	clear.draw();
	screen.draw();
}




HBITMAP* MenuSimple::screenDo() const
{
	using std::min;
	using std::max;


	int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpstrCmdLine, int nCmdShow);
	{
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		HDC scrdc, memdc;
		HBITMAP membit;
		scrdc = GetDC(window->getSystemHandle());
		int Height, Width;
		Height =window->getSize().y;
		Width =window->getSize().x-band.getSize().x;
		memdc = CreateCompatibleDC(scrdc);
		membit = CreateCompatibleBitmap(scrdc, Width, Height);
		SelectObject(memdc, membit);
		// Улыбаемся... Снято!
		BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
		HBITMAP hBitmap;
		hBitmap = (HBITMAP)SelectObject(memdc, membit);
		{
			Gdiplus::Bitmap bitmap(hBitmap, NULL);
			bitmap.Save(L"C:\\Users\\home\\Desktop\\screen.png", &png);
		}
		return &hBitmap;
	}
}


