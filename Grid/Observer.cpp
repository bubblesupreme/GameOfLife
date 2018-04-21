#include "Observer.h"

Observer::Observer(sf::RenderWindow* window)
{
	this->window = window;
}


Observer::~Observer()
{
}


void Observer::handleEvent(sf::Event* event, std::vector<Grid*>& grids, State& state)
{
	if (event->type == sf::Event::KeyPressed) {

		switch (event->key.code) {

		case sf::Keyboard::Escape:
			window->close();
			break;

		case sf::Keyboard::Return:
			switch (state) {

			case UPDATING:
				state = MODIFYING;
				break;

			case MODIFYING:
				state = UPDATING;

			default:
				break;
			}
			break;

		case sf::Keyboard::Right: 
			state = UPDATING;
			break;

		case sf::Keyboard::Left: 
			state = MODIFYING;
			if (grids.size() > 1)
			{
				grids.pop_back();
			}
			break;
		case sf::Keyboard::C:
		{			Grid* back = grids.back();
		grids.clear();
		grids.push_back(back);
		grids.back()->clear();
		break;
		}

		default:
			break;
		}
	}

	if (event->type == sf::Event::KeyReleased) {

		switch (event->key.code) {

		case sf::Keyboard::Right: {
			state = MODIFYING;
			break;
		}
		case sf::Keyboard::Left: {
			state = MODIFYING;
			break;
		}
		default:
			break;
		}
	}




	if (event->type == sf::Event::MouseButtonPressed) {

		if ((event->mouseButton.button == sf::Mouse::Left) && (state == MODIFYING)) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;
			if ((*x >= 0) && (*y >= 0) && (*x < grids.back()->getSize().first) 
					&& (*y < grids.back()->getSize().second)) {
				if (grids.size() > 1)
				{
					grids.pop_back();
					Grid* back =grids.back();
					grids.clear();
					grids.push_back(back);
					(grids.back())->setBoothAt(!grids.back()->isboolAliveAt(*x, *y), *x, *y);
				}
				else
				{
					grids.back()->setBoothAt(!grids.back()->isboolAliveAt(*x, *y), *x, *y);
				}
			}
			delete x;
			delete y;
		}
	}

	if (event->type == sf::Event::MouseMoved) {

		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (state == MODIFYING)) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;

			if ((*x > 0) && (*y > 0) && (*x < grids.back()->getSize().first) && (*y < grids.back()->getSize().second)) {
				if (grids.size() > 1)
				{
					grids.pop_back();
					Grid* back = grids.back();
					grids.clear();
					grids.push_back(back);
					(grids.back())->setBoothAt(!grids.back()->isboolAliveAt(*x, *y), *x, *y);
				}
				else
				{
					grids.back()->setBoothAt(!grids.back()->isboolAliveAt(*x, *y), *x, *y);
				}
			}

			delete x;
			delete y;
		}
	}
}


void Observer::handleEvent(sf::Event* event, Grid* grid, State& state)
{
	if (event->type == sf::Event::KeyPressed) {

		switch (event->key.code) {

		case sf::Keyboard::Escape:
			window->close();
			break;

		case sf::Keyboard::Return:
			switch (state) {

			case UPDATING:
				state = MODIFYING;
				break;

			case MODIFYING:
				state = UPDATING;

			default:
				break;
			}
			break;

		case sf::Keyboard::Right: {
			state = UPDATING;
			break;
		}

		default:
			break;
		}
	}

	if (event->type == sf::Event::KeyReleased) {

		switch (event->key.code) {

		case sf::Keyboard::Right: {
			state = MODIFYING;
			break;
		}
		default:
			break;
		}
	}

	if (event->type == sf::Event::MouseButtonPressed) {

		if ((event->mouseButton.button == sf::Mouse::Left) && (state == MODIFYING)) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;
			if ((*x >= 0) && (*y >= 0) && (*x < grid->getSize().first) && (*y < grid->getSize().second)) {
				grid->setBoothAt(!grid->isboolAliveAt(*x, *y), *x, *y);
			}
			delete x;
			delete y;
		}
	}

	if (event->type == sf::Event::MouseMoved) {

		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (state == MODIFYING)) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;

			if ((*x > 0) && (*y > 0) && (*x < grid->getSize().first) && (*y < grid->getSize().second)) {
				grid->setBoothAt(!grid->isboolAliveAt(*x, *y), *x, *y);
			}

			delete x;
			delete y;
		}
	}
}

void Observer::handleEvent(sf::Event* event, Grid* grid, int limit)
{
	if (event->type == sf::Event::MouseButtonPressed) {

		if (event->mouseButton.button == sf::Mouse::Left) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;
			if ((*x >= 0) && (*y >= 0) && (*x < grid->getSize().first) && (*y < grid->getSize().second)) {
				switch (grid->isboolAliveAt(*x, *y))
				{
		
				case true:
					grid->setBoothAt(false, *x, *y);
					break;
				case false:
					if (limit > 0)
					{
						grid->setBoothAt(true, *x, *y);
					}
					break;
				default:
					break;
				}
				
			}
			delete x;
			delete y;
		}
	}

	if (event->type == sf::Event::MouseMoved) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			int* x = new int;
			int*y = new int;
			*x = sf::Mouse::getPosition(*window).x / sizeBooth;
			*y = sf::Mouse::getPosition(*window).y / sizeBooth;

			if ((*x > 0) && (*y > 0) && (*x < grid->getSize().first) && (*y < grid->getSize().second)) {
				switch (grid->isboolAliveAt(*x, *y))
				{
				case true:
					grid->setBoothAt(false, *x, *y);
					break;
				case false:
					if (limit > 0)
					{
						grid->setBoothAt(true, *x, *y);
					}
					break;
				default:
					break;
				}
			}

			delete x;
			delete y;
		}
	}
}