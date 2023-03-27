#include "Menu.h"
using namespace std;

Menu::Menu()
{
	run = true;
	Show_cursymbol = true;
	rungame = false;
}

void Menu::Menu_screen()
{
	Basic::PlayMusic(0);
	Menu_Grp.Grp_menuSetup();
	Menu_Grp.Grp_Logo();

	Menu_Grp.Grp_setcurX(50);
	Menu_Grp.Grp_setcurY(15);
	Basic::gotoXY(Menu_Grp.Grp_getcurX(), Menu_Grp.Grp_getcurY());
	Show_cursymbol = true;
	Menu_showSymbol();

	Menu_Grp.Grp_MenuMainbox();
	while (run)
	{
		Menu_move();
	}
	Basic::Console_SetColor(15, 15);
	Basic::Console_ClearScreen();
	Basic::Console_SetColor(15, 0);
	cout << "THE END\n";
}

void Menu::Menu_moveleft()
{
	int curx = Menu_Grp.Grp_getcurX();
	int cury = Menu_Grp.Grp_getcurY();

	Menu_Grp.Grp_setcurX_old(curx);
	Menu_Grp.Grp_setcurY_old(cury);


	curx -= 4;
	if (curx <= 8)
	{
		curx = 100;
	}

	Menu_Grp.Grp_setcurX(curx);
	Menu_Grp.Grp_setcurY(cury);
	Menu_process();
	Basic::gotoXY(curx, cury);
	
	
}

void Menu::Menu_moveright()
{
	int curx = Menu_Grp.Grp_getcurX();
	int cury = Menu_Grp.Grp_getcurY();

	Menu_Grp.Grp_setcurX_old(curx);
	Menu_Grp.Grp_setcurY_old(cury);

	curx += 4;
	if (curx >= 100)
	{
		curx = 8;
	}

	Menu_Grp.Grp_setcurX(curx);
	Menu_Grp.Grp_setcurY(cury);
	Menu_process();

	Basic::gotoXY(curx, cury);
	
}

void Menu::Menu_moveup()
{
	int curx = Menu_Grp.Grp_getcurX();
	int cury = Menu_Grp.Grp_getcurY();

	Menu_Grp.Grp_setcurX_old(curx);
	Menu_Grp.Grp_setcurY_old(cury);

	cury -= 2;
	if (cury <= 10)
	{
		cury = 30;
	}

	Menu_Grp.Grp_setcurX(curx);
	Menu_Grp.Grp_setcurY(cury);
	Menu_process();

	Basic::gotoXY(curx, cury);
}

void Menu::Menu_movedown()
{
	int curx = Menu_Grp.Grp_getcurX();
	int cury = Menu_Grp.Grp_getcurY();

	Menu_Grp.Grp_setcurX_old(curx);
	Menu_Grp.Grp_setcurY_old(cury);

	cury += 2;
	if (cury >= 30)
	{
		cury = 11;
	}

	Menu_Grp.Grp_setcurX(curx);
	Menu_Grp.Grp_setcurY(cury);
	Menu_process();

	Basic::gotoXY(curx, cury);
}

void Menu::Menu_move()
{
	int c = Basic::GetKeyInput();
	switch (c)
	{
		case 1:
			Menu_moveup();
			break;
		case 2:
			Menu_moveleft();
			break;
		case 3:
			Menu_movedown();
			break;
		case 4:
			Menu_moveright();
			break;
		case 6:
			Menu_Interac();
			break;
		case 5:
			Menu_Quit();
			break;
	}
}

void Menu::Menu_showSymbol()
{
	if (Show_cursymbol)
	{
		if (Menu_Grp.Grp_checkShowcur() == true)
		{
			bool showcur = false;
			Menu_Grp.Grp_setShowcur(showcur);
			Basic::ShowCursor(false);
		}

		Basic::gotoXY(Menu_Grp.Grp_getcurX_old(), Menu_Grp.Grp_getcurY_old());
		Basic::Console_SetColor(15, 15);
		putchar(219);

		Basic::gotoXY(Menu_Grp.Grp_getcurX(), Menu_Grp.Grp_getcurY());
		Basic::Console_SetColor(15, 3);
		putchar(88);
	}
	else
	{
		if (Menu_Grp.Grp_checkShowcur() == true)
		{
			bool showcur = false;
			Menu_Grp.Grp_setShowcur(showcur);
			Basic::ShowCursor(false);
		}
		
		int curx_old = Menu_Grp.Grp_getcurX_old();
		int cury_old = Menu_Grp.Grp_getcurY_old();

		if (!(curx_old >= 12 && curx_old <= 36 && cury_old >= 12 && cury_old <= 16) && !(curx_old >= 72 && curx_old <= 96 && cury_old >= 12 && cury_old <= 16) && !(curx_old >= 12 && curx_old <= 36 && cury_old >= 25 && cury_old <= 29) && !(curx_old >= 72 && curx_old <= 96 && cury_old >= 25 && cury_old <= 29))
		{
			Basic::gotoXY(curx_old, cury_old);
			Basic::Console_SetColor(15, 15);
			putchar(219);
		}
		
		
	}
}

void Menu::Menu_process()
{
	int cur_x = Menu_Grp.Grp_getcurX();
	int cur_y = Menu_Grp.Grp_getcurY();

	if (!(cur_x >= 12 && cur_x <= 36 && cur_y >= 12 && cur_y <= 16) && !(cur_x >= 72 && cur_x <= 96 && cur_y >= 12 && cur_y <= 16) && !(cur_x >= 12 && cur_x <= 36 && cur_y >= 25 && cur_y <= 29) && !(cur_x >= 72 && cur_x <= 96 && cur_y >= 25 && cur_y <= 29))
	{
		Show_cursymbol = true;
	}
	else
	{
		Show_cursymbol = false;
	}
	
	Menu_showSymbol();

	Menu_Grp.Grp_StartGamebox();
	Menu_Grp.Grp_HTplayBox();
	Menu_Grp.Grp_Aboutbox();
	Menu_Grp.Grp_Quitbox();

}

void Menu::Menu_About()
{
	Menu_Grp.Grp_Menuclearboard(1);
	

	Menu_Grp.Grp_About();
	
	if (Basic::GetKeyInput() != -1)
	{
		Menu_Grp.Grp_Menuclearboard(2);
		Menu_Grp.Grp_MenuMainbox();
	}

	Menu_Grp.Grp_setcurX(50);
	Menu_Grp.Grp_setcurY(15);

	Basic::gotoXY(50, 15);
	Menu_showSymbol();
}

void Menu::Menu_Interac()
{
	int curx = Menu_Grp.Grp_getcurX();
	int cury = Menu_Grp.Grp_getcurY();

	if (curx >= 12 && curx <= 36 && cury >= 25 && cury <= 29)
	{
		Menu_About();
	}
	
	if (curx >= 72 && curx <= 96 && cury >= 12 && cury <= 16)
	{
		Menu_HTplay();
	}
	
	if ((curx >= 72 && curx <= 96 && cury >= 25 && cury <= 29))
	{
		Menu_Quit();
	}
	
	if (curx >= 12 && curx <= 36 && cury >= 12 && cury <= 16)
	{
		rungame = true;
		run = false;
		G.Game_setloop(true);
		if (Menu_playPVP() == false)
		{
			rungame = false;
			run = true;
			Menu_screen();
		}
	}
}

void Menu::Menu_HTplay()
{
	Menu_Grp.Grp_Menuclearboard(3);
	Menu_Grp.Grp_Howtoplay_page1();

	int page = 1;
	bool in = true;
	while (in)
	{
		switch (Basic::GetKeyInput())
		{
			case 4:
				if (page == 1)
				{
					page = 2;
					Menu_Grp.Grp_Menuclearboard(0);
					Menu_Grp.Grp_Howtoplay_page2();
				}
				break;
			case 2:
				if (page == 2)
				{
					page = 1;
					Menu_Grp.Grp_Menuclearboard(0);
					Menu_Grp.Grp_Howtoplay_page1();
				}
				break;
			case 5:
				in = false;
				break;
			case 8:
				in = false;
				break;
		}
	}

	Menu_Grp.Grp_Menuclearboard(4);
	Menu_Grp.Grp_MenuMainbox();
	Menu_Grp.Grp_setcurX(50);
	Menu_Grp.Grp_setcurY(15);
	Basic::gotoXY(50, 15);
	Menu_showSymbol();
	
}

void Menu::Menu_Quit()
{
	
	Menu_Grp.Quit_subBox();
	Menu_Grp.Grp_Yesbox(1);
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
					Menu_Grp.Grp_Yesbox(false);
					Menu_Grp.Grp_Nobox(true);
				}
				else
				{
					choice = true;
					Menu_Grp.Grp_Yesbox(true);
					Menu_Grp.Grp_Nobox(false);
				}
				break;
			case 2:
				if (choice == false)
				{
					choice = true;
					Menu_Grp.Grp_Yesbox(true);
					Menu_Grp.Grp_Nobox(false);
				}
				else
				{
					choice = false;
					Menu_Grp.Grp_Yesbox(false);
					Menu_Grp.Grp_Nobox(true);
				}
				break;
			case 5:
				run = false;
				in = false;
				break;
			case 6:
				if (choice == true)
				{
					run = false;
					in = false;
					break;
				}
				else
				{
					in = false;
					break;
				}
			case 8:
				in = false;
				break;
		}
	}

	Menu_Grp.Grp_Menuclearboard(0);
	Menu_Grp.Grp_MenuMainbox();
	Menu_Grp.Grp_setcurX(50);
	Menu_Grp.Grp_setcurY(15);
	Basic::gotoXY(50, 15);
	Menu_showSymbol();
}

bool Menu::Menu_playPVP()
{
	G.Game_pvp();
	return G.Game_getloop();
}