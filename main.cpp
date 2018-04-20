#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "MainMenu.h"
#include "SwichUsers.h"
#include <fstream>

//void start(sf::RenderWindow *window);
extern User user;
int main()
{	
	State state;
	sf::RenderWindow window(sf::VideoMode(858,600,32),"Conways Game Of Life",sf::Style::Close);
	window.setFramerateLimit(10);
	MainMenu mainmenu(&window);
	SwichUsers swichUsers(&window);
	swichUsers.demonstrate();
	mainmenu.demonstrate();
	std::ofstream fout(fileName,std::ios::app);
	fout << user.getName() << " " << user.getLevel();
	fout.close();
	return 0;
}

