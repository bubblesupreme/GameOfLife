#ifndef SWITCHUSERS_H
#define SWITCHUSERS_H

#include "Global\Global.h"
#include "GUI elements\ButtonN.h"
#include "User.h"


class SwichUsers
{
public:
	SwichUsers(sf::RenderWindow* window);
	~SwichUsers();
	void demonstrate();
	void draw();
private:
	void editUsers();
	User addUser();
	sf::RenderWindow* window;
	std::vector<ButtonN> usersBut;
	ButtonN newUser;
	ButtonN edit;
	std::vector<User> users;
	sf::Texture* textureBack;
	sf::RectangleShape background;
};

#endif