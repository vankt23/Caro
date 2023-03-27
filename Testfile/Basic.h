#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <Random>
#include<vector>
#pragma comment(lib, "Winmm.lib")
class Basic
{
private:
	static HWND consoleWindow;    //Pointer to handle console
	static HANDLE consoleOutput;  //Pointer to handle output console

public:

	Basic() {};//Constructor
	~Basic() {};//Destructor

	void textcolor(int x);

	void SetColor(WORD color);

	static void gotoXY(int, int);	//place the curosr at the (x,y) location
	
	static void ShowCursor(bool);	//Show or hide cursor
	
	static int GetKeyInput();	//Get input from keyboard
	
	static void PlayMusic(int);	//Play background music, game sound

	static void Console_SetAndCenterWindow();	//Place console in the Center and set size

	static void Console_SetColor(int, int);	//Set background and text color

	static void Console_SetTitle();	//Set title for the console

	static void Console_SetFont();	//Set font and size

	static void Console_DisableMaxSize();	//Prevent user maximizing the console window

	static void Console_HideScrollBar();	//Literally to hide the scroll bar

	static void Console_DisableMouse();	//Disable mouse input

	static void Console_ClearScreen();	//Clear screen
	
	static void Console_Setup();	//Set startup console

	
};

