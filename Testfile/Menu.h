#pragma once
#include<iostream>
#include"Basic.h"
#include"GraphicUI.h"
#include"Gameplay.h"
using namespace std;
class Menu
{
private:
	bool run;
	bool Show_cursymbol;
	bool rungame;
	GraphicUI Menu_Grp;
	Gameplay G;
public:
	Menu();

	void Menu_screen();

	void Menu_moveleft();

	void Menu_moveright();

	void Menu_moveup();

	void Menu_movedown();

	void Menu_move();

	void Menu_process();

	void Menu_showSymbol();

	void Menu_About();

	void Menu_Interac();

	void Menu_HTplay();

	void Menu_Quit();

	bool Menu_playPVP();
};

