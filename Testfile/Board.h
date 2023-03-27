#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <random>
#include "Basic.h"
#include "Point.h"
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;
class Board
{
private:
	int size;
	int left, top;
	int countX, countO;
	Point* win;
	Point** point_arr;	//The game board is a matrix of object Points

public:
	Board();	//Constructor

	Board(int, int, int);	//Constructor

	~Board();	//Destructor

	int Board_getsize();	//Get board size

	int Board_getleft();	//Get x value of board in coordinate

	int Board_gettop();		//Get y value of board in coordinate

	int Board_getcountX();	//Number of X on the board

	int Board_getcountO();	//Number of Y on the board

	int Board_getposX(int, int);	//Get value of x of A[i][j] point

	int Board_getposY(int, int);	//Get value of y of A[i][j] point

	void Board_reset();		//Reset game board

	void Board_draw();	//Draw game board

	int Board_setMove(int,int,int);		//Process set a move into a point

	int Board_getFlag(int, int);		//Get value of flag on (x,y) coordinate

	bool Board_Wincol_check(int , int , int);

	bool Board_Winrow_check(int , int , int);

	bool Board_WinmainDiag_check(int , int , int);
	
	bool Board_WinextraDiag_check(int, int, int);

	int Board_Win_check(int , int );

	
};

