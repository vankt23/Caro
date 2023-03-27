#pragma once
#include"Board.h"
#include"GraphicUI.h"
class Gameplay
{
private:
	Board* Bo;
	GraphicUI Game_grp;
	int changeturn;	// to recognise when to change turn
	int turn;	//1 : player 1, -1 : player 2
	int mode;	// 1: pvp, 2:pvc
	bool finish;
	bool pause;
	bool run;
	bool loop;
	int countP1win;
	int countP2win;
public:
	Gameplay();

	~Gameplay();

	bool Game_getloop();

	void Game_setloop(bool);

	void Game_setup(int);

	void Game_printTurn();

	void Game_Moveleft();

	void Game_Moveright();

	void Game_Moveup();

	void Game_Movedown();

	int Game_procedure();

	void Game_Entermove();

	void Game_P1Win();

	void Game_P2Win();

	void Game_Draw();

	bool Game_playagain();

	void Game_pvp();
};

