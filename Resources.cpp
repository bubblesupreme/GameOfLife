#include "Resources.h"
#include <iostream>


Resources::Resources()
{
	lobster = new sf::Font;
	italic = new sf::Font;
	Levels = new sf::Texture;
	Patterns=new sf::Texture;
	Play= new sf::Texture;
	Tutorial= new sf::Texture;
	italic->loadFromFile("fonts//italic.ttf");
	lobster->loadFromFile("fonts//lobster.ttf");
	Levels->loadFromFile("buttons//Levels.png");
	Patterns->loadFromFile("buttons//Patterns.png");
	Play->loadFromFile("buttons//Play.png");
	Tutorial->loadFromFile("buttons//Tutorial.png");


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
	simpleButton->loadFromFile("buttons//Button.png");
	Gene->loadFromFile("buttons//Gene.png");
	MainMenu->loadFromFile("buttons//Menu.png");
	MainMenu2->loadFromFile("buttons//Menu2.png");
	Classic->loadFromFile("buttons//Classic.png");
	next->loadFromFile("buttons//Next.png");
	last->loadFromFile("buttons//Last.png");
	ok->loadFromFile("buttons//ok.png");
	pause->loadFromFile("buttons//pause.png");
	clear->loadFromFile("buttons//Clear.png");
	edit->loadFromFile("buttons//Edit.png");
	newUser->loadFromFile("buttons//New.png");
	switchUser->loadFromFile("buttons//switchUser.png");
	del->loadFromFile("buttons//delete.png");

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

	start->loadFromFile("buttons//start.png");
	stop->loadFromFile("buttons//stop.png");
	forwardT->loadFromFile("buttons//forwardT.png");
	backwardT->loadFromFile("buttons//backwardT.png");
	colorTrue->loadFromFile("buttons//colorTrue.png");
	colorFalse->loadFromFile("buttons//colorFalse.png");
	soundTrue->loadFromFile("buttons//soundTrue.png");
	soundFalse->loadFromFile("buttons//soundFalse.png");
	soundRegulT->loadFromFile("buttons//soundRegulT.png");
	screenT->loadFromFile("buttons//screenT.png");
	clear1->loadFromFile("buttons//Clear1.png");

	soundOn = new sf::Texture;
	soundOff = new sf::Texture;
	soundRegular = new sf::Texture;
	soundOn->loadFromFile("buttons//soundOn.png");
	soundOff->loadFromFile("buttons//soundOff.png");
	soundRegular->loadFromFile("buttons//soundRegular.png");

	game = new sf::Music;
	game->openFromFile("musics//game.wav");
	win = new sf::SoundBuffer;
	win->loadFromFile("musics//win.wav");
	button = new sf::SoundBuffer;
	button->loadFromFile("musics//button.wav");
	winAll = new sf::SoundBuffer;
	winAll->loadFromFile("musics//winAll.wav");
	loss = new sf::SoundBuffer;
	loss->loadFromFile("musics//loss.wav");

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

	level1->loadFromFile("buttons//level1.png");
	levels.push_back(level1);
	level2->loadFromFile("buttons//level2.png");
	levels.push_back(level2);
	level3->loadFromFile("buttons//level3.png");
	levels.push_back(level3);
	level4->loadFromFile("buttons//level4.png");
	levels.push_back(level4);
	level5->loadFromFile("buttons//level5.png");
	levels.push_back(level5);
	level6->loadFromFile("buttons//level6.png");
	levels.push_back(level6);
	level7->loadFromFile("buttons//level7.png");
	levels.push_back(level7);
	level8->loadFromFile("buttons//level8.png");
	levels.push_back(level8);
	level9->loadFromFile("buttons//level9.png");
	levels.push_back(level9);
	level10->loadFromFile("buttons//level10.png");
	levels.push_back(level10);
	level11->loadFromFile("buttons//level11.png");
	levels.push_back(level11);
	level12->loadFromFile("buttons//level12.png");
	levels.push_back(level12);
	level13->loadFromFile("buttons//level13.png");
	levels.push_back(level13);
	level14->loadFromFile("buttons//level14.png");
	levels.push_back(level14);
	level15->loadFromFile("buttons//level15.png");
	levels.push_back(level15);
	level16->loadFromFile("buttons//level16.png");
	levels.push_back(level16);
	level17->loadFromFile("buttons//level17.png");
	levels.push_back(level17);
	level18->loadFromFile("buttons//level18.png");
	levels.push_back(level18);
	level19->loadFromFile("buttons//level19.png");
	levels.push_back(level19);
	level20->loadFromFile("buttons//level20.png");
	levels.push_back(level20);
	level21->loadFromFile("buttons//level21.png");
	levels.push_back(level21);
	level22->loadFromFile("buttons//level22.png");
	levels.push_back(level22);
	level23->loadFromFile("buttons//level23.png");
	levels.push_back(level23);
	level24->loadFromFile("buttons//level24.png");
	levels.push_back(level24);
	level25->loadFromFile("buttons//level25.png");
	levels.push_back(level25);
	level26->loadFromFile("buttons//level26.png");
	levels.push_back(level26);
	level27->loadFromFile("buttons//level27.png");
	levels.push_back(level27);
	level28->loadFromFile("buttons//level28.png");
	levels.push_back(level28);
	level29->loadFromFile("buttons//level29.png");
	levels.push_back(level29);
	level30->loadFromFile("buttons//level30.png");
	levels.push_back(level30);

	
}


Resources::~Resources()
{
}
