#pragma once
#include"Basic.h"
#include"Board.h"
#include<iostream>
#include<string>

using std::cout;
using std::cin;
class GraphicUI
{
private:
	int cur_x;
	int cur_y;
	int cur_x_old;
	int cur_y_old;
	int cur_check;
	bool Showcur;
	string name1;
	string name2;
	Basic hndl;
	Board* B;
public:
	GraphicUI();	//Constructor
	
	~GraphicUI();	//Destructor

	void Name1_input();

	void Name2_input();

	string Name1_get();

	string Name2_get();

	bool Grp_checkShowcur();

	void Grp_setShowcur(bool);

	int Grp_getcurX();		//Get cursor position x

	int Grp_getcurY();		//Get cursor position y

	void Grp_setcurX(int);	//Set X position of cursor

	void Grp_setcurY(int);	//Set Y position of cursor

	int Grp_getcheck();		//Check the input from keyboard

	int Grp_getcurX_old();

	int Grp_getcurY_old();

	void Grp_setcurX_old(int);

	void Grp_setcurY_old(int);

	void Grp_Menumove();		//Move cursor on the screen

	void Write(int, int, string, int, int);		//Write letters with color

	void Drawbox(int x, int y, int width, int height, int t_color, int b_color);	//Draw box 
	
	void Drawbox_ver2(int x, int y, int width, int height, int t_color, int b_color);

	void Grp_Logo();

	void Grp_Logo_withAni();

	void Grp_printP1win();

	void Grp_printP2win();

	void Grp_printDraw();


	void Grp_printEnd();

	void GPL_screenSetup_PVP();

	void GPL_screenSetup_PVC();

	void Grp_menuSetup();
	
	void Grp_MenuMainbox();

	void Grp_StartGamebox();

	void Grp_HTplayBox();

	void Grp_Aboutbox();

	void Grp_Quitbox();

	void Grp_Menuclearboard(int);

	void Grp_About();

	void Grp_Howtoplay_page1();

	void Grp_Howtoplay_page2();

	void Grp_Yesbox(bool);

	void Grp_Nobox(bool);

	void Quit_subBox();

	void PlayAgainbox();
};

