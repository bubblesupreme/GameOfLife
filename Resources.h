#ifndef RESOURCES_H
#define RESOURCES_H


#include<SFML\Graphics.hpp>
#include "SFML\Audio.hpp"

class Resources
{
public:
	Resources();
	~Resources();

	sf::Font* lobster;
	sf::Font* italic;
	sf::Texture* next;
	sf::Texture* ok;
	sf::Texture* last;
	sf::Texture* Levels;
	sf::Texture* Patterns;
	sf::Texture* Play;
	sf::Texture* Tutorial;
	sf::Texture* MainMenu;
	sf::Texture* MainMenu2;
	sf::Texture* Classic;
	sf::Texture* Gene;
	sf::Texture* simpleButton;
	sf::Texture* switchUser;
	sf::Texture* pause;
	sf::Texture* clear;
	sf::Texture* edit;
	sf::Texture* newUser;
	sf::Texture* del;

	sf::Texture* start;
	sf::Texture* stop;
	sf::Texture* forwardT;
	sf::Texture* backwardT;
	sf::Texture* colorTrue;
	sf::Texture* colorFalse;
	sf::Texture* soundTrue;
	sf::Texture* soundFalse;
	sf::Texture* soundRegulT;
	sf::Texture* screenT;
	sf::Texture* clear1;

	sf::Music* game;
	sf::SoundBuffer * win;
	sf::SoundBuffer * button;
	sf::SoundBuffer * winAll;
	sf::SoundBuffer * loss;
	sf::Texture* soundOn;
	sf::Texture* soundOff;
	sf::Texture* soundRegular;

	std::vector<sf::Texture*> levels;
private:
	sf::Texture* level1;
	sf::Texture* level2;
	sf::Texture* level3;
	sf::Texture* level4;
	sf::Texture* level5;
	sf::Texture* level6;
	sf::Texture* level7;
	sf::Texture* level8;
	sf::Texture* level9;
	sf::Texture* level10;
	sf::Texture* level11;
	sf::Texture* level12;
	sf::Texture* level13;
	sf::Texture* level14;
	sf::Texture* level15;
	sf::Texture* level16;
	sf::Texture* level17;
	sf::Texture* level18;
	sf::Texture* level19;
	sf::Texture* level20;
	sf::Texture* level21;
	sf::Texture* level22;
	sf::Texture* level23;
	sf::Texture* level24;
	sf::Texture* level25;
	sf::Texture* level26;
	sf::Texture* level27;
	sf::Texture* level28;
	sf::Texture* level29;
	sf::Texture* level30;

};

#endif