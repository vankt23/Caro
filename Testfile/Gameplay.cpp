#include "Gameplay.h"
Gameplay::Gameplay()
{
	Bo = new Board(14, 25, 2);
	mode = 0;
	turn = 1;
	changeturn = 1;
	finish = false;
	pause = false;
	run = true;
	loop = true;
	countP1win = 0;
	countP2win = 0;
}

Gameplay::~Gameplay()
{
	delete Bo;
	mode = 0;
}


bool Gameplay::Game_getloop()
{
	return loop;
}

void Gameplay::Game_setup(int gmode)
{
	if (gmode == 1)
	{
		run = true;
		finish = false;
		mode = gmode;
		Game_grp.GPL_screenSetup_PVP();
		Bo->Board_reset();
	}

	if (gmode == 2)
	{
		mode = gmode;
		Game_grp.GPL_screenSetup_PVC();
		Bo->Board_reset();
	}

	if (gmode == 0)
	{
		run = false;
		finish = true;
	}
}

void Gameplay::Game_printTurn()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	bool Showcursor = Game_grp.Grp_checkShowcur();
	if (Bo->Board_getFlag(curx, cury) == 1 || Bo->Board_getFlag(curx, cury) == -1)
	{
		if (Showcursor == false)
		{
			Showcursor = true;
			Basic::ShowCursor(Showcursor);
			Game_grp.Grp_setShowcur(Showcursor);
		}
	}
	else
	{
		if (Showcursor == true)
		{
			Showcursor = false;
			Basic::ShowCursor(Showcursor);
			Game_grp.Grp_setShowcur(Showcursor);
		}
		
		if (changeturn == 1)
		{
			changeturn = 0;
			
		}

		if (turn == 1)
		{
			Basic::Console_SetColor(15, 1);
			putchar(120);
		}
		
		if(turn == -1)
		{
			Basic::Console_SetColor(15, 2);
			putchar(111);
		}

		Basic::gotoXY(curx, cury);
	}
	
}

void Gameplay::Game_Moveleft()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int size = Bo->Board_getsize();

	if (curx <= Bo->Board_getposX(0,0))
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		curx = Bo->Board_getposX(1, size - 1);

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}
	else
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		curx -= 4;

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}

	
}

void Gameplay::Game_Moveright()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int size = Bo->Board_getsize();

	if (curx >= Bo->Board_getposX(1, size - 1))
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		curx = Bo->Board_getposX(0, 0);

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}
	else
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		curx += 4;

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}

	
}

void Gameplay::Game_Moveup()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int size = Bo->Board_getsize();

	if (cury <= Bo->Board_getposY(0, 0))
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		cury = Bo->Board_getposY(size - 1, 1);

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}
	else
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		cury -= 2;

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}

	
}

void Gameplay::Game_Movedown()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int size = Bo->Board_getsize();

	if (cury >= Bo->Board_getposY(size - 1, 1))
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		cury = Bo->Board_getposY(0, 0);

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}
	else
	{
		if (Bo->Board_getFlag(curx, cury) == 0)
		{
			putchar(32);
		}
		cury += 2;

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		Basic::gotoXY(curx, cury);
		Game_printTurn();
	}

	
}

int Gameplay::Game_procedure()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int ret = Bo->Board_Win_check(curx, cury);

	switch (ret)
	{
		case 0:
			{
				finish = true;
				Game_Draw();
				break;
			}
		case 1:
			{
				finish = true;
				countP1win += 1;
				Game_P1Win();
				break;
			}
		case -1:
			{
				finish = true;
				countP2win += 1;
				Game_P2Win();
				break;
			}
		case 2:
			{
				turn = -turn;
				changeturn = 1;
				break;
			}

	}

	return ret;
}

void Gameplay::Game_Entermove()
{
	int curx = Game_grp.Grp_getcurX();
	int cury = Game_grp.Grp_getcurY();
	int c = Bo->Board_setMove(curx, cury, turn);

	if (c == 0)
	{
		//Play Music
	}
	else
	{
		if (c == 1)
		{

			Basic::gotoXY(curx, cury);
			Basic::Console_SetColor(15, 1);
			putchar(88);
			//cout Bo->getcountX under the name 
		}

		if (c == -1)
		{
			Basic::gotoXY(curx, cury);
			Basic::Console_SetColor(15, 2);
			putchar(79);
			//cout Bo->getcountX under the name 
		}
		Game_procedure();
	}

	
}


void Gameplay::Game_pvp()
{
	if (loop)
	{
		run = 1;
		Game_grp.GPL_screenSetup_PVP();
		Bo->Board_reset();

		Game_grp.Grp_setShowcur(false);
		Basic::ShowCursor(Game_grp.Grp_checkShowcur());

		int curx = Bo->Board_getposX(7, 7);
		int cury = Bo->Board_getposY(7, 7);

		Game_grp.Grp_setcurX(curx);
		Game_grp.Grp_setcurY(cury);

		turn = 1;
		changeturn = 1;
		Basic::gotoXY(Game_grp.Grp_getcurX(), Game_grp.Grp_getcurY());
		Game_printTurn();

		while (run)
		{
			int C = Basic::GetKeyInput();
			switch (C)
			{
				case 1:
				{
					Game_Moveup();
					break;
				}
				case 2:
				{
					Game_Moveleft();
					break;
				}
				case 3:
				{
					Game_Movedown();
					break;
				}
				case 4:
				{
					Game_Moveright();
					break;
				}
				case 5:
				{
					run = false;
					loop = false;
					break;
				}
				case 6:
				{
					Game_Entermove();
					break;
				}

			}
		}
	}
	
}

bool Gameplay::Game_playagain()
{
	Game_grp.PlayAgainbox();
	Game_grp.Grp_Yesbox(true);

	bool choice = true;
	bool in = true;
	while (in)
	{
		switch (Basic::GetKeyInput())
		{
		case 4:
			if (choice == true)
			{
				choice = false;
				Game_grp.Grp_Yesbox(false);
				Game_grp.Grp_Nobox(true);
			}
			else
			{
				choice = true;
				Game_grp.Grp_Yesbox(true);
				Game_grp.Grp_Nobox(false);
			}
			break;
		case 2:
			if (choice == false)
			{
				choice = true;
				Game_grp.Grp_Yesbox(true);
				Game_grp.Grp_Nobox(false);
			}
			else
			{
				choice = false;
				Game_grp.Grp_Yesbox(false);
				Game_grp.Grp_Nobox(true);
			}
			break;
		case 5:
			finish = true;
			run = false;
			loop = false;
			in = false;
			return false;
			break;
		case 8:
			finish = true;
			run = false;
			loop = false;
			in = false;
			return false;
			break;
		case 6:
			if (choice == true)
			{
				finish = false;
				run = true;
				loop = true;
				in = false;
				return true;
				break;
			}
			else
			{
				finish = true;
				run = false;
				loop = false;
				in = false;
				return false;
				break;
			}
		}
	}

}

void Gameplay::Game_P1Win()
{
	Game_grp.Drawbox(7, 10, 94, 21, 0, 15);
	Game_grp.Grp_printP1win();
	if (Game_playagain())
	{
		Game_pvp();
	}
}

void Gameplay::Game_P2Win()
{
	Game_grp.Drawbox(7, 10, 94, 21, 0, 15);
	Game_grp.Grp_printP2win();
	if (Game_playagain())
	{
		Game_pvp();
	}
}

void Gameplay::Game_Draw()
{
	Game_grp.Drawbox(7, 10, 94, 21, 0, 15);
	Game_grp.Grp_printDraw();
	if (Game_playagain())
	{
		Game_pvp();
	}
}

void Gameplay::Game_setloop(bool l)
{
	loop = l;
}