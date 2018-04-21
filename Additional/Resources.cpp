#include "Resources.h"
//#include "resources/"
#include <iostream>


Resources::Resources()
{
	lobster = new sf::Font;
	italic = new sf::Font;
	Levels = new sf::Texture;
	Patterns=new sf::Texture;
	Play= new sf::Texture;
	Tutorial= new sf::Texture;
	italic->loadFromFile("resources/fonts//italic.ttf");
	lobster->loadFromFile("resources/fonts//lobster.ttf");
	Levels->loadFromFile("resources/buttons/Levels.png");
	Patterns->loadFromFile("resources/buttons//Patterns.png");
	Play->loadFromFile("resources/buttons//Play.png");
	Tutorial->loadFromFile("resources/buttons//Tutorial.png");


	simpleButton = new sf::Texture;
	Gene= new sf::Texture;
	Classic = new sf::Texture;
	next = new sf::Texture;
	last = new sf::Texture;
	MainMenu = new sf::Texture;
	MainMenu2= new sf::Texture;
	pause= new sf::Texture;
	ok= new sf::Texture;
	clear= new sf::Texture;
	edit= new sf::Texture;
	newUser= new sf::Texture;
	switchUser= new sf::Texture;
	del = new sf::Texture;
	simpleButton->loadFromFile("resources/buttons//Button.png");
	Gene->loadFromFile("resources/buttons//Gene.png");
	MainMenu->loadFromFile("resources/buttons/Menu.png");
	MainMenu2->loadFromFile("resources/buttons//Menu2.png");
	Classic->loadFromFile("resources/buttons//Classic.png");
	next->loadFromFile("resources/buttons//Next.png");
	last->loadFromFile("resources/buttons//Last.png");
	ok->loadFromFile("resources/buttons//ok.png");
	pause->loadFromFile("resources/buttons//pause.png");
	clear->loadFromFile("resources/buttons//Clear.png");
	edit->loadFromFile("resources/buttons//Edit.png");
	newUser->loadFromFile("resources/buttons//New.png");
	switchUser->loadFromFile("resources/buttons//switchUser.png");
	del->loadFromFile("resources/buttons//delete.png");

	start = new sf::Texture;
	stop = new sf::Texture;
	forwardT = new sf::Texture;
	backwardT = new sf::Texture;
	colorTrue = new sf::Texture;
	colorFalse = new sf::Texture;
	soundTrue = new sf::Texture;
	soundFalse = new sf::Texture;
	soundRegulT = new sf::Texture;
	screenT = new sf::Texture;
	clear1 = new sf::Texture;

	start->loadFromFile("resources/buttons//start.png");
	stop->loadFromFile("resources/buttons//stop.png");
	forwardT->loadFromFile("resources/buttons//forwardT.png");
	backwardT->loadFromFile("resources/buttons//backwardT.png");
	colorTrue->loadFromFile("resources/buttons//colorTrue.png");
	colorFalse->loadFromFile("resources/buttons//colorFalse.png");
	soundTrue->loadFromFile("resources/buttons//soundTrue.png");
	soundFalse->loadFromFile("resources/buttons//soundFalse.png");
	soundRegulT->loadFromFile("resources/buttons//soundRegulT.png");
	screenT->loadFromFile("resources/buttons//screenT.png");
	clear1->loadFromFile("resources/buttons//Clear1.png");

	soundOn = new sf::Texture;
	soundOff = new sf::Texture;
	soundRegular = new sf::Texture;
	soundOn->loadFromFile("resources/buttons//soundOn.png");
	soundOff->loadFromFile("resources/buttons//soundOff.png");
	soundRegular->loadFromFile("resources/buttons//soundRegular.png");

	game = new sf::Music;
	game->openFromFile("resources/musics//game.wav");
	win = new sf::SoundBuffer;
	win->loadFromFile("resources/musics//win.wav");
	button = new sf::SoundBuffer;
	button->loadFromFile("resources/musics//button.wav");
	winAll = new sf::SoundBuffer;
	winAll->loadFromFile("resources/musics//winAll.wav");
	loss = new sf::SoundBuffer;
	loss->loadFromFile("resources/musics//loss.wav");

	level1 = new sf::Texture;
	level2= new sf::Texture;
	level3= new sf::Texture;
	level4= new sf::Texture;
	level5= new sf::Texture;
	level6= new sf::Texture;
	level7= new sf::Texture;
	level8= new sf::Texture;
	level9= new sf::Texture;
	level10= new sf::Texture;
	level11= new sf::Texture;
	level12= new sf::Texture;
	level13= new sf::Texture;
	level14= new sf::Texture;
	level15= new sf::Texture;
	level16= new sf::Texture;
	level17= new sf::Texture;
	level18= new sf::Texture;
	level19= new sf::Texture;
	level20= new sf::Texture;
	level21= new sf::Texture;
	level22= new sf::Texture;
	level23= new sf::Texture;
	level24= new sf::Texture;
	level25= new sf::Texture;
	level26= new sf::Texture;
	level27= new sf::Texture;
	level28= new sf::Texture;
	level29= new sf::Texture;
	level30= new sf::Texture;

	level1->loadFromFile("resources/buttons//level1.png");
	levels.push_back(level1);
	level2->loadFromFile("resources/buttons//level2.png");
	levels.push_back(level2);
	level3->loadFromFile("resources/buttons//level3.png");
	levels.push_back(level3);
	level4->loadFromFile("resources/buttons//level4.png");
	levels.push_back(level4);
	level5->loadFromFile("resources/buttons//level5.png");
	levels.push_back(level5);
	level6->loadFromFile("resources/buttons//level6.png");
	levels.push_back(level6);
	level7->loadFromFile("resources/buttons//level7.png");
	levels.push_back(level7);
	level8->loadFromFile("resources/buttons//level8.png");
	levels.push_back(level8);
	level9->loadFromFile("resources/buttons//level9.png");
	levels.push_back(level9);
	level10->loadFromFile("resources/buttons//level10.png");
	levels.push_back(level10);
	level11->loadFromFile("resources/buttons//level11.png");
	levels.push_back(level11);
	level12->loadFromFile("resources/buttons//level12.png");
	levels.push_back(level12);
	level13->loadFromFile("resources/buttons//level13.png");
	levels.push_back(level13);
	level14->loadFromFile("resources/buttons//level14.png");
	levels.push_back(level14);
	level15->loadFromFile("resources/buttons//level15.png");
	levels.push_back(level15);
	level16->loadFromFile("resources/buttons//level16.png");
	levels.push_back(level16);
	level17->loadFromFile("resources/buttons//level17.png");
	levels.push_back(level17);
	level18->loadFromFile("resources/buttons//level18.png");
	levels.push_back(level18);
	level19->loadFromFile("resources/buttons//level19.png");
	levels.push_back(level19);
	level20->loadFromFile("resources/buttons//level20.png");
	levels.push_back(level20);
	level21->loadFromFile("resources/buttons//level21.png");
	levels.push_back(level21);
	level22->loadFromFile("resources/buttons//level22.png");
	levels.push_back(level22);
	level23->loadFromFile("resources/buttons//level23.png");
	levels.push_back(level23);
	level24->loadFromFile("resources/buttons//level24.png");
	levels.push_back(level24);
	level25->loadFromFile("resources/buttons//level25.png");
	levels.push_back(level25);
	level26->loadFromFile("resources/buttons//level26.png");
	levels.push_back(level26);
	level27->loadFromFile("resources/buttons//level27.png");
	levels.push_back(level27);
	level28->loadFromFile("resources/buttons//level28.png");
	levels.push_back(level28);
	level29->loadFromFile("resources/buttons//level29.png");
	levels.push_back(level29);
	level30->loadFromFile("resources/buttons//level30.png");
	levels.push_back(level30);

	
}


Resources::~Resources()
{
}
