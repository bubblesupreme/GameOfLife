#include "SwichUsers.h"
#include "Textbox.h"
#include "DemonstrateException.h"
#include <iostream>
#include <fstream>


SwichUsers::SwichUsers(sf::RenderWindow* window)
	:window(window)
	, newUser(window, window->getSize().x *0.3, window->getSize().y / 5 * 4, "Add new", TOP, resources->italic, resources->newUser)
	,edit(window, window->getSize().x *0.7- resources->edit->getSize().x, window->getSize().y / 5 * 4, "Edit", TOP, resources->italic, resources->edit)
{
	char name[10];
	int level;

	Size sizeTexture(resources->simpleButton->getSize().x, resources->simpleButton->getSize().y);

	int counter = 0;
	std::ifstream fin(fileName);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> name;
			fin >> level;
			users.push_back(User(name, level));
			usersBut.push_back(ButtonN(window, (counter % 3)* (sizeTexture.first + window->getSize().x / 29) + window->getSize().x / 10
				, counter / 3 * (sizeTexture.second + window->getSize().y / 18) + window->getSize().y / 3, name, CENTR, resources->italic, resources->simpleButton));
			usersBut.back().setCharacterSize(25);
			counter++;
		}
		fin.close();
	}
	else
	{

	}
	
	textureBack= new sf::Texture;
	textureBack->loadFromFile("buttons//switchUsers.jpg");
	background.setTexture(textureBack);
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
}


SwichUsers::~SwichUsers()
{
}

void SwichUsers::demonstrate()
{
	if (user.getName() != "no name")
	{
		for (int i=0;i<users.size();i++)
		{
			if (users[i].getName() == user.getName())
			{
				users[i].setLevel(user.getLevel());
			}
		}
	}
	sf::Event event;
	while (window->isOpen()) {

		while (window->pollEvent(event)) {

			for (int i=0; i<usersBut.size();i++)
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();
					return;
				}
				usersBut[i].handleEvent(event);
				if (usersBut[i].getClicked())
				{
					user = users[i];

					std::ofstream fout(fileName);
					for (auto us : users)
					{
						if (us != user)
						{
							fout << us.getName() << " " << us.getLevel() << "\n";
						}
					}
					fout.close();
					return;
				}
			}
			edit.handleEvent(event);
			if (edit.getClicked())
			{
				editUsers();
			}
			newUser.handleEvent(event);
			if (newUser.getClicked())
			{
				try 
				{
					users.push_back(addUser());
					usersBut.push_back(ButtonN(window, ((users.size()-1) % 3)* (resources->simpleButton->getSize().x
										+ window->getSize().x / 29) + window->getSize().x / 10
						, (users.size()-1) / 3 * (resources->simpleButton->getSize().y 
										+ window->getSize().y / 18) + window->getSize().y / 3
						, users.back().getName(), CENTR, resources->italic, resources->simpleButton));
					usersBut.back().setCharacterSize(25);
				}
				catch (std::exception ex)
				{
					DemonstrateException exDem;
					exDem.demonstrate(ex.what());
				}
			}
		}
		window->clear();
		draw();
		window->display();
	}
}

User SwichUsers::addUser()
{
	if (users.size() < 6)
	{
		sf::RenderWindow addWindow(sf::VideoMode(300, 200), "", sf::Style::None);
		ButtonN ok(&addWindow, addWindow.getSize().x / 2 - resources->ok->getSize().x / 2
			, addWindow.getSize().y / 4 * 2.8, "", LEFT, resources->italic, resources->ok);
		sf::RectangleShape background;
		background.setFillColor(sf::Color(242, 240, 240));
		background.setPosition(10, 10);
		background.setSize(sf::Vector2f(addWindow.getSize().x - 2 * 10, addWindow.getSize().y - 2 * 10));
		background.setOutlineThickness(10);
		background.setOutlineColor(sf::Color(182, 180, 180));
		sf::Text headline;
		headline.setFont(*resources->italic);
		headline.setCharacterSize(25);
		headline.setString("Enter name: ");
		headline.setFillColor(sf::Color(90, 86, 209));
		headline.setPosition(addWindow.getSize().x / 2 - headline.getGlobalBounds().width / 2
			, addWindow.getSize().y*0.05);
		Textbox textBox(&addWindow, addWindow.getSize().x/2-75
			, addWindow.getSize().y/2-15,150,30);
		sf::Event event;
		while (!ok.getClicked()) {
			while (addWindow.pollEvent(event)) {

				ok.handleEvent(event);
				textBox.handleEvent(event);
			}
			addWindow.clear();
			addWindow.draw(background);
			ok.draw();
			textBox.draw();
			addWindow.draw(headline);
			addWindow.display();
		}
		addWindow.close();
		std::string name = textBox.getText();
		for (auto us : users)
		{
			if(us.getName() == name)
			{
				throw std::exception("Already added!");
			}
		}
		return User(name);
	}
		throw std::exception("Too many users!\n Delete users before adding");
}

void SwichUsers::editUsers()
{
	std::vector<ButtonN> delets;
	ButtonN ok(window, window->getSize().x/2 - resources->ok->getSize().x/2, window->getSize().y / 5 * 4, "", TOP, resources->italic, resources->ok);
	for (int i = 0; i<usersBut.size(); i++)
	{
		sf::Rect<int> rect = usersBut[i].getRect();
		delets.push_back(ButtonN(window, (rect.left+rect.width)*1.005, rect.top*0.95, "", TOP, resources->italic, resources->del));
		delets.back().setScale(0.2, 0.2);
	}
	sf::Event event;
	while (window->isOpen()) {
		while (window->pollEvent(event)) {

			for (int i = 0; i<delets.size(); i++)
			{
				delets[i].handleEvent(event);
				if (delets[i].getClicked())
				{
					usersBut.erase(usersBut.begin()+i);
					delets.pop_back();
					users.erase(users.begin() + i);

					Size sizeTexture(resources->simpleButton->getSize().x, resources->simpleButton->getSize().y);
					for (int k = 0; k<delets.size(); k++)
					{
						usersBut[k].setPosisition((k % 3)* (sizeTexture.first + window->getSize().x / 29) + window->getSize().x / 10
							, k / 3 * (sizeTexture.second + window->getSize().y / 18) + window->getSize().y / 3);
					}
					break;
				}
			}
			ok.handleEvent(event);
			if (ok.getClicked())
			{
				return;
			}
		}

		window->clear();
		window->draw(background);
		for (auto button : usersBut)
		{
			button.draw();
		}
		for (auto del : delets)
		{
			del.draw();
		}
		ok.draw();
		window->display();
	}
}

void SwichUsers::draw()
{
	window->draw(background);
	for (auto button : usersBut)
	{
		button.draw();
	}
	newUser.draw();
	edit.draw();
}