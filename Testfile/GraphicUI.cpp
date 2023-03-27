#include "GraphicUI.h"

GraphicUI::GraphicUI()
{
	cur_x = 0;
	cur_y = 0;
	cur_x_old = 0;
	cur_y_old = 0;
	cur_check = 0;
	name1 = " ";
	name2 = " ";
	B = new Board(14, 25, 2);
	Showcur = false;
	hndl.Console_Setup();

}

GraphicUI::~GraphicUI()
{
	delete B;
	name1.clear();
	name2.clear();
	cur_x = 0;
	cur_y = 0;
	cur_check = 0;

}

bool GraphicUI::Grp_checkShowcur()
{
	return Showcur;
}

void GraphicUI::Grp_setShowcur(bool s)
{
	Showcur = s;
}

void GraphicUI::Name1_input()
{
	getline(cin, name1);
}

void GraphicUI::Name2_input()
{
	getline(cin, name2);
}

string GraphicUI::Name1_get()
{
	return name1;
}

string GraphicUI::Name2_get()
{
	return name2;
}

int GraphicUI::Grp_getcurX()
{
	return cur_x;
}

int GraphicUI::Grp_getcurY()
{
	return cur_y;
}

void GraphicUI::Grp_setcurX(int x)
{
	cur_x = x;
}

void GraphicUI::Grp_setcurY(int y)
{
	cur_y = y;
}

int GraphicUI::Grp_getcurX_old()
{
	return cur_x_old;
}

int GraphicUI::Grp_getcurY_old()
{
	return cur_y_old;
}

void GraphicUI::Grp_setcurX_old(int px)
{
	cur_x_old = px;
}

void GraphicUI::Grp_setcurY_old(int py)
{
	cur_y_old = py;
}

int GraphicUI::Grp_getcheck()
{
	return cur_check;
}

void GraphicUI::Grp_Menumove()
{
	if (_kbhit() == 1)
	{

		int c = hndl.GetKeyInput();
		cur_check = c;
		switch (c)
		{
		case 1: cur_y -= 1; break;
		case 2: cur_x -= 2; break;
		case 3: cur_y += 1; break;
		case 4: cur_x += 2; break;
		}
		if (cur_x <= 0)
		{
			cur_x = 99;
		}
		if (cur_x > 99)
		{
			cur_x = 1;
		}
		if (cur_y <= 0)
		{
			cur_y = 30;
		}
		if (cur_y > 30)
		{
			cur_y = 1;
		}

		hndl.gotoXY(cur_x, cur_y);

	}

}

void GraphicUI::Write(int x, int y, string a, int color, int background)
{
	hndl.gotoXY(x, y);
	hndl.Console_SetColor(background,color);
	cout << a;
	hndl.textcolor(7);
}

void GraphicUI::Drawbox(int x, int y, int width, int height, int t_color, int b_color)
{
	int b_color2 =  b_color * 16 + t_color;
	hndl.textcolor(b_color2);
	for (int iy = y + 1; iy <= y + height - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			hndl.gotoXY(ix, iy); cout << " ";
		}
	}
	
	hndl.Console_SetColor(b_color, t_color);
	if (height <= 1 || width <= 1)
	{
		return;
	}

	for (int i = x; i <= x + width; i++)
	{
		hndl.gotoXY(i, y);
		std::cout << char(196);
		hndl.gotoXY(i, y + height);
		std::cout << char(196);
	}


	for (int i = y; i <= y + height; i++)
	{
		hndl.gotoXY(x, i);
		std::cout << char(179);
		hndl.gotoXY(x + width, i);
		std::cout << char(179);
	}

	hndl.gotoXY(x, y); std::cout << char(218);
	hndl.gotoXY(x + width, y); std::cout << char(191);
	hndl.gotoXY(x, y + height); std::cout << char(192);
	hndl.gotoXY(x + width, y + height); std::cout << char(217);
	
}

void GraphicUI::Drawbox_ver2(int x, int y, int width, int height, int t_color, int b_color)
{
	int b_color2 = b_color * 16 + t_color;
	hndl.textcolor(b_color2);
	for (int iy = y + 1; iy <= y + height - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			hndl.gotoXY(ix, iy); cout << " ";
		}
	}

	hndl.Console_SetColor(b_color, t_color);
	if (height <= 1 || width <= 1)
	{
		return;
	}

	for (int i = x; i <= x + width; i++)
	{
		hndl.gotoXY(i, y);
		std::cout << char(205);
		hndl.gotoXY(i, y + height);
		std::cout << char(205);
	}


	for (int i = y; i <= y + height; i++)
	{
		hndl.gotoXY(x, i);
		std::cout << char(186);
		hndl.gotoXY(x + width, i);
		std::cout << char(186);
	}

	hndl.gotoXY(x, y); std::cout << char(201);
	hndl.gotoXY(x + width, y); std::cout << char(187);
	hndl.gotoXY(x, y + height); std::cout << char(200);
	hndl.gotoXY(x + width, y + height); std::cout << char(188);
}

void GraphicUI::Grp_Logo()
{
	//Letter C
	hndl.Console_SetColor(15, 2);
	hndl.gotoXY(26, 3); putchar(201);
	hndl.gotoXY(27, 3); putchar(220);
	for (int i = 28; i < 34; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}
	hndl.gotoXY(34, 3); putchar(220);

	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(26, i); putchar(219);
	}

	hndl.gotoXY(27, 8); putchar(223);
	for (int i = 28; i < 34; i++)
	{
		hndl.gotoXY(i, 8); putchar(220);
	}
	hndl.gotoXY(34, 8); putchar(223);

	hndl.gotoXY(25, 4); putchar(201);
	hndl.gotoXY(25, 5); putchar(186);
	hndl.gotoXY(25, 6); putchar(186);
	hndl.gotoXY(25, 7); putchar(200);

	hndl.Console_SetColor(15, 11);
	for (int i = 29; i < 36; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}
	for (int i = 29; i < 36; i++)
	{
		hndl.gotoXY(i, 6); putchar(223);
	}


	//Letter A
	hndl.Console_SetColor(15, 4);
	hndl.gotoXY(40, 3); putchar(201);
	hndl.gotoXY(41, 3); putchar(220);

	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}
	hndl.gotoXY(48, 3); putchar(220);
	hndl.gotoXY(49, 3); putchar(187);

	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(40, i); putchar(219);
	}

	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(49, i); putchar(219);
	}

	hndl.gotoXY(41, 8); putchar(220);
	hndl.gotoXY(50, 8); putchar(220);

	hndl.gotoXY(39, 4); putchar(201);
	hndl.gotoXY(39, 5); putchar(186);
	hndl.gotoXY(39, 6); putchar(186);
	hndl.gotoXY(39, 7); putchar(200);

	hndl.Console_SetColor(15, 11);
	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}

	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}

	//Letter R
	hndl.Console_SetColor(15, 5);
	hndl.gotoXY(55, 3); putchar(201);
	hndl.gotoXY(56, 3); putchar(220);

	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}

	hndl.gotoXY(62, 3); putchar(220);
	hndl.gotoXY(63, 3); putchar(187);

	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(55, i); putchar(219);
	}
	hndl.gotoXY(63, 4); putchar(219);
	hndl.gotoXY(63, 5); putchar(219);

	hndl.gotoXY(56, 6); putchar(220);
	hndl.gotoXY(57, 6); putchar(223);
	hndl.gotoXY(58, 6); putchar(219);

	for (int i = 59; i < 63; i++)
	{
		hndl.gotoXY(i, 6); putchar(223);
	}

	hndl.gotoXY(59, 7); putchar(223);
	hndl.gotoXY(60, 7); putchar(220);
	hndl.gotoXY(61, 8); putchar(223);
	hndl.gotoXY(62, 8); putchar(220);

	hndl.gotoXY(56, 8); putchar(220);
	hndl.gotoXY(63, 8); putchar(220);

	hndl.gotoXY(54, 4); putchar(201);
	hndl.gotoXY(54, 5); putchar(186);
	hndl.gotoXY(54, 6); putchar(186);
	hndl.gotoXY(54, 7); putchar(200);

	hndl.Console_SetColor(15, 11);
	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}

	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 5); putchar(223);
	}

	//Letter O
	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(68, 3); putchar(201);
	hndl.gotoXY(69, 3); putchar(220);

	for (int i = 70; i < 76; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}

	hndl.gotoXY(76, 3); putchar(220);
	hndl.gotoXY(77, 3); putchar(187);

	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(68, i); putchar(219);
	}

	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(77, i); putchar(219);
	}

	hndl.gotoXY(68, 8); putchar(200);
	hndl.gotoXY(69, 8); putchar(223);

	for (int i = 70; i < 76; i++)
	{
		hndl.gotoXY(i, 8); putchar(220);
	}

	hndl.gotoXY(76, 8); putchar(223);

	hndl.gotoXY(67, 4); putchar(201);
	hndl.gotoXY(67, 5); putchar(186);
	hndl.gotoXY(67, 6); putchar(186);
	hndl.gotoXY(67, 7); putchar(200);

	hndl.Console_SetColor(15, 11);
	for (int i = 70; i < 77; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}

	for (int i = 70; i < 77; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}

}


void GraphicUI::Grp_Logo_withAni()
{
	//Letter C
	hndl.Console_SetColor(15, 2);

	hndl.gotoXY(26, 3); putchar(201);
	hndl.gotoXY(27, 3); putchar(220);
	for (int i = 28; i < 34; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
		
	}
	hndl.gotoXY(34, 3); putchar(220);

	sleep_for(nanoseconds(100000000));
	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(26, i); putchar(219);
	}
	hndl.gotoXY(25, 4); putchar(201);

	sleep_for(nanoseconds(100000000));
	hndl.gotoXY(25, 5); putchar(186);
	hndl.Console_SetColor(15, 11);
	for (int i = 29; i < 36; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}

	sleep_for(nanoseconds(100000000));
	hndl.Console_SetColor(15, 2);
	hndl.gotoXY(25, 6); putchar(186);
	hndl.Console_SetColor(15, 11);
	for (int i = 29; i < 36; i++)
	{
		hndl.gotoXY(i, 6); putchar(223);
	}

	hndl.Console_SetColor(15, 2);
	sleep_for(nanoseconds(100000000));
	hndl.gotoXY(25, 7); putchar(200);

	sleep_for(nanoseconds(100000000));
	hndl.gotoXY(27, 8); putchar(223);
	for (int i = 28; i < 34; i++)
	{
		hndl.gotoXY(i, 8); putchar(220);
	}
	hndl.gotoXY(34, 8); putchar(223);

	
	//Letter A
	hndl.Console_SetColor(15, 4);

	hndl.gotoXY(39, 5); putchar(186);
	hndl.gotoXY(39, 6); putchar(186);
	hndl.Console_SetColor(15, 11);
	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}
	sleep_for(nanoseconds(200000000));
	hndl.Console_SetColor(15, 4);
	hndl.gotoXY(39, 4); putchar(201);
	hndl.gotoXY(39, 7); putchar(200);
	hndl.Console_SetColor(15, 11);
	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}
	sleep_for(nanoseconds(200000000));

	hndl.Console_SetColor(15, 4);
	hndl.gotoXY(40, 3); putchar(201);
	hndl.gotoXY(41, 3); putchar(220);
	for (int i = 42; i < 48; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}
	hndl.gotoXY(48, 3); putchar(220);
	hndl.gotoXY(49, 3); putchar(187);

	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(40, i); putchar(219);
	}

	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(49, i); putchar(219);
	}
	hndl.gotoXY(41, 8); putchar(220);
	hndl.gotoXY(50, 8); putchar(220);
	sleep_for(nanoseconds(200000000));


	//Letter R
	hndl.Console_SetColor(15, 5);
	hndl.gotoXY(61, 8); putchar(223);
	hndl.gotoXY(62, 8); putchar(220);
	hndl.gotoXY(56, 8); putchar(220);
	hndl.gotoXY(63, 8); putchar(220);
	sleep_for(nanoseconds(100000000));

	hndl.gotoXY(59, 7); putchar(223);
	hndl.gotoXY(60, 7); putchar(220);
	hndl.gotoXY(54, 7); putchar(200);
	sleep_for(nanoseconds(100000000));

	hndl.gotoXY(56, 6); putchar(220);
	hndl.gotoXY(57, 6); putchar(223);
	hndl.gotoXY(58, 6); putchar(219);
	for (int i = 59; i < 63; i++)
	{
		hndl.gotoXY(i, 6); putchar(223);
	}
	hndl.gotoXY(54, 6); putchar(186);
	sleep_for(nanoseconds(100000000));

	hndl.gotoXY(54, 5); putchar(186);
	hndl.gotoXY(63, 5); putchar(219);
	hndl.Console_SetColor(15, 11);
	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 5); putchar(223);
	}
	sleep_for(nanoseconds(100000000));
	hndl.Console_SetColor(15, 5);


	for (int i = 4; i < 9; i++)
	{
		hndl.gotoXY(55, i); putchar(219);
	}
	hndl.gotoXY(63, 4); putchar(219);
	hndl.gotoXY(54, 4); putchar(201);
	hndl.Console_SetColor(15, 11);
	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}
	sleep_for(nanoseconds(100000000));
	hndl.Console_SetColor(15, 5);

	hndl.gotoXY(55, 3); putchar(201);
	hndl.gotoXY(56, 3); putchar(220);
	for (int i = 57; i < 62; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}
	hndl.gotoXY(62, 3); putchar(220);
	hndl.gotoXY(63, 3); putchar(187);
	sleep_for(nanoseconds(100000000));
	

	

	//Letter O
	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(68, 3); putchar(201);
	hndl.gotoXY(69, 3); putchar(220);

	for (int i = 70; i < 76; i++)
	{
		hndl.gotoXY(i, 3); putchar(223);
	}

	hndl.gotoXY(76, 3); putchar(220);
	hndl.gotoXY(77, 3); putchar(187);

	hndl.gotoXY(68, 8); putchar(200);
	hndl.gotoXY(69, 8); putchar(223);

	for (int i = 70; i < 76; i++)
	{
		hndl.gotoXY(i, 8); putchar(220);
	}

	hndl.gotoXY(76, 8); putchar(223);
	sleep_for(nanoseconds(200000000));

	hndl.gotoXY(67, 4); putchar(201);
	hndl.gotoXY(67, 7); putchar(200);

	hndl.Console_SetColor(15, 11);
	for (int i = 70; i < 77; i++)
	{
		hndl.gotoXY(i, 4); putchar(220);
	}
	sleep_for(nanoseconds(200000000));

	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(67, 5); putchar(186);
	hndl.gotoXY(67, 6); putchar(186);

	hndl.Console_SetColor(15, 11);
	for (int i = 70; i < 77; i++)
	{
		hndl.gotoXY(i, 5); putchar(219);
	}
	sleep_for(nanoseconds(200000000));

	hndl.Console_SetColor(15, 0);
	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(68, i); putchar(219);
	}

	for (int i = 4; i < 8; i++)
	{
		hndl.gotoXY(77, i); putchar(219);
	}

}

void GraphicUI::GPL_screenSetup_PVP()
{
	hndl.Console_SetColor(15, 0);
	hndl.Console_ClearScreen();

	cout << "Nhap ten player 1: ";
	Name1_input();
	cout << "Nhap ten player 2: ";
	Name2_input();

	size_t len1 = name1.length();
	hndl.Console_ClearScreen();
	Drawbox(3, 2, 21, 12, 1, 15);
	Write(10, 3, "PLAYER 1", 1, 15);
	Write(4 + (int)((21-len1)/2), 4, Name1_get(), 1, 15);

	size_t len2 = name2.length();
	Drawbox(84, 2, 21, 12, 2, 15);
	Write(91, 3, "PLAYER 2", 2, 15);
	Write(85 + (int)((21-len2)/2), 4, Name2_get(), 2, 15);
	
	hndl.Console_SetColor(15, 0);
	B->Board_draw();
	
}

void GraphicUI::GPL_screenSetup_PVC()
{
	hndl.Console_SetColor(15, 0);
	hndl.Console_ClearScreen();

	cout << "Nhap ten player: ";
	Name1_input();
	name2 = "Computer";

	size_t len1 = name1.length();
	hndl.Console_ClearScreen();
	Drawbox(3, 2, 21, 12, 1, 15);
	Write(10, 3, "PLAYER 1", 1, 15);
	Write(4 + (int)((21 - len1) / 2), 4, Name1_get(), 1, 15);

	size_t len2 = name2.length();
	Drawbox(84, 2, 21, 12, 2, 15);
	Write(91, 3, "PLAYER 2", 2, 15);
	Write(85 + (int)((21 - len2) / 2), 4, Name2_get(), 2, 15);

	hndl.Console_SetColor(15, 0);
	B->Board_draw();
}

void GraphicUI::Grp_printP1win()
{
	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(12, 12);
	cout << "WINNER: "<<name1;

}

void GraphicUI::Grp_printP2win()
{
	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(5, 12);
	cout << "WINNER: " << name2;
}

void GraphicUI::Grp_printDraw()
{
	hndl.Console_SetColor(15, 0);
	hndl.gotoXY(5, 12);
	cout << "DRAW";
}

void GraphicUI::Grp_printEnd()
{
	hndl.Console_SetColor(15, 0);
	hndl.Console_Setup();
	hndl.Console_ClearScreen();
	hndl.gotoXY(5, 12);
	cout << "THE END";
}


void GraphicUI::Grp_menuSetup()
{
	hndl.Console_SetColor(15, 0);
	hndl.Console_Setup();
	hndl.Console_ClearScreen();
	Showcur = false;
	Basic::ShowCursor(false);
	
}

void GraphicUI::Grp_MenuMainbox()
{
	Drawbox(7, 10, 94, 21, 0, 15);
	Drawbox_ver2(12, 12, 24, 4, 0, 15);
	Write(18, 14, "START  GAME", 5, 15);
	Drawbox_ver2(72, 12, 24, 4, 0, 15);
	Write(79, 14, "HOW TO PLAY", 0, 15);
	Drawbox_ver2(12, 25, 24, 4, 0, 15);
	Write(21, 27, "ABOUT ", 2, 15);
	Drawbox_ver2(72, 25, 24, 4, 0, 15);
	Write(82, 27, "QUIT", 4, 15);
	
}

void GraphicUI::Grp_StartGamebox()
{
	if (!((cur_x_old >= 12 && cur_x_old <= 36 && cur_y_old >= 12 && cur_y_old <= 16)))
	{
		if (cur_x >= 12 && cur_x <= 36 && cur_y >= 12 && cur_y <= 16)
		{
			Drawbox_ver2(11, 11, 26, 6, 0, 15);
			hndl.Console_SetColor(15, 13);

			for (int i = 13; i <= 35; i++)
			{
				for (int j = 13; j <= 15; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}

			Write(18, 14, "START  GAME", 15, 13);
		}

	}
	
	if ((cur_x_old >= 12 && cur_x_old <= 36 && cur_y_old >= 12 && cur_y_old <= 16))
	{
		if (!(cur_x >= 12 && cur_x <= 36 && cur_y >= 12 && cur_y <= 16))
		{
			hndl.Console_SetColor(15, 15);
			for (int i = 11; i <= 37; i++)
			{
				for (int j = 11; j <= 17; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}

			Drawbox_ver2(12, 12, 24, 4, 0, 15);
			Write(18, 14, "START  GAME", 5, 15);
		}
	}
	
}

void GraphicUI::Grp_HTplayBox()
{
	if (!((cur_x_old >= 72 && cur_x_old <= 96 && cur_y_old >= 12 && cur_y_old <= 16)))
	{
		if (cur_x >= 72 && cur_x <= 96 && cur_y >= 12 && cur_y <= 16)
		{
			Drawbox_ver2(71, 11, 26, 6, 0, 15);
			hndl.Console_SetColor(15, 8);
			for (int i = 73; i <= 95; i++)
			{
				for (int j = 13; j <= 15; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Write(79, 14, "HOW TO PLAY", 15, 8);
		}
	}
	
	if ((cur_x_old >= 72 && cur_x_old <= 96 && cur_y_old >= 12 && cur_y_old <= 16))
	{
		if (!(cur_x >= 72 && cur_x <= 96 && cur_y >= 12 && cur_y <= 16))
		{
			hndl.Console_SetColor(15, 15);
			for (int i = 71; i <= 97; i++)
			{
				for (int j = 11; j <= 17; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Drawbox_ver2(72, 12, 24, 4, 0, 15);
			Write(79, 14, "HOW TO PLAY", 0, 15);
		}
	}
	

}

void GraphicUI::Grp_Aboutbox()
{
	if (!(cur_x_old >= 12 && cur_x_old <= 36 && cur_y_old >= 25 && cur_y_old <= 29))
	{
		if (cur_x >= 12 && cur_x <= 36 && cur_y >= 25 && cur_y <= 29)
		{
			Drawbox_ver2(11, 24, 26, 6, 0, 15);
			hndl.Console_SetColor(15, 10);
			for (int i = 13; i <= 35; i++)
			{
				for (int j = 26; j <= 28; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Write(21, 27, "ABOUT ", 15, 10);
		}
	}
	
	if ((cur_x_old >= 12 && cur_x_old <= 36 && cur_y_old >= 25 && cur_y_old <= 29))
	{
		if (!(cur_x >= 12 && cur_x <= 36 && cur_y >= 25 && cur_y <= 29))
		{
			hndl.Console_SetColor(15, 15);
			for (int i = 11; i <= 37; i++)
			{
				for (int j = 24; j <= 30; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Drawbox_ver2(12, 25, 24, 4, 0, 15);
			Write(21, 27, "ABOUT ", 2, 15);
		}
	}
	
}

void GraphicUI::Grp_Quitbox()
{
	if (!(cur_x_old >= 72 && cur_x_old <= 96 && cur_y_old >= 25 && cur_y_old <= 29))
	{
		if (cur_x >= 72 && cur_x <= 96 && cur_y >= 25 && cur_y <= 29)
		{
			Drawbox_ver2(71, 24, 26, 6, 0, 15);
			hndl.Console_SetColor(15, 12);
			for (int i = 73; i <= 95; i++)
			{
				for (int j = 26; j <= 28; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Write(82, 27, "QUIT", 15, 12);
		}
	}
	
	if ((cur_x_old >= 72 && cur_x_old <= 96 && cur_y_old >= 25 && cur_y_old <= 29))
	{
		if (!(cur_x >= 72 && cur_x <= 96 && cur_y >= 25 && cur_y <= 29))
		{
			hndl.Console_SetColor(15, 15);
			for (int i = 71; i <= 97; i++)
			{
				for (int j = 24; j <= 30; j++)
				{
					hndl.gotoXY(i, j);
					putchar(219);
				}
			}
			Drawbox_ver2(72, 25, 24, 4, 0, 15);
			Write(82, 27, "QUIT", 4, 15);
		}
	}
}

void GraphicUI::Grp_Menuclearboard(int i)
{
	hndl.Console_SetColor(15, 15);
	if (i == 1)
	{
		for (int i = 8; i <= 100; i++)
		{
			hndl.Console_SetColor(15, 15);
			for (int j = 11; j <= 30; j++)
			{
				hndl.Console_SetColor(15, 15);
				hndl.gotoXY(i, j);
				putchar(219);

				if (i < 95)
				{
					hndl.Console_SetColor(15, 1);
					hndl.gotoXY(i + 4, j);
					putchar(219);
					hndl.gotoXY(i + 3, j);
					putchar(178);
					hndl.gotoXY(i + 2, j);
					putchar(177);
					hndl.gotoXY(i + 1, j);
					putchar(176);
				}
				
			}

			sleep_for(nanoseconds(3500));
		}
	}
	else if (i == 2)
	{
		for (int i = 100; i >= 8; i--)
		{
			for (int j = 11; j <= 30; j++)
			{

				if (i > 14)
				{
					hndl.Console_SetColor(15, 1);
					hndl.gotoXY(i - 4, j);
					putchar(219);
					hndl.gotoXY(i - 3, j);
					putchar(178);
					hndl.gotoXY(i - 2, j);
					putchar(177);
					hndl.gotoXY(i - 1, j);
					putchar(176);
				}

				hndl.Console_SetColor(15, 15);
				hndl.gotoXY(i, j);
				putchar(219);
			}
			sleep_for(nanoseconds(3500));

		}
	}
	else if (i == 3)
	{
		for (int j = 11; j <= 30; j++)
		{
			for (int i = 8; i <= 100; i++)
			{
				hndl.Console_SetColor(15, 15);
				hndl.gotoXY(i, j);
				putchar(219);

				if (j < 25)
				{
					hndl.Console_SetColor(15, 1);
					hndl.gotoXY(i, j + 5);
					putchar(219);
					hndl.gotoXY(i, j + 4);
					putchar(178);
					hndl.gotoXY(i, j + 3);
					putchar(177);
					hndl.gotoXY(i, j + 2);
					putchar(176);
				}
			}
			sleep_for(nanoseconds(50000000));
		}
	}
	else if (i == 4)
	{
		for (int j = 30; j >= 11; j--)
		{
			for (int i = 8; i <= 100; i++)
			{
				if (j > 16)
				{
					hndl.Console_SetColor(15, 1);
					hndl.gotoXY(i, j - 5);
					putchar(219);
					hndl.gotoXY(i, j - 4);
					putchar(178);
					hndl.gotoXY(i, j - 3);
					putchar(177);
					hndl.gotoXY(i, j - 2);
					putchar(176);
				}

				hndl.Console_SetColor(15, 15);
				hndl.gotoXY(i, j);
				putchar(219);
			}
			sleep_for(nanoseconds(50000000));
		}
	}
	else
		for (int i = 8; i <= 100; i++)
		{
			for (int j = 11; j <= 30; j++)
			{
				hndl.gotoXY(i, j);
				putchar(219);
			}

		}
}

void GraphicUI::Grp_About()
{
	

	hndl.Console_SetColor(15, 4);
	for(int i = 12; i <= 96; i++)
	{
		hndl.gotoXY(i, 12);
		putchar(205);
	}

	hndl.Console_SetColor(15, 2);
	hndl.gotoXY(49, 12);
	cout << "ABOUT";

	hndl.Console_SetColor(15, 4);
	Write(12, 14, "_DEVELOPER: ", 4, 15);
	Write(63, 14, "_CONTAC US: ", 4, 15);

	Write(16, 15, "+ MAN PHAM MINH (BUGGY MAN) ", 4, 15);
	Write(67, 15, "+ 22127257@STUDENT.HCMUS.EDU.VN",4,15);

	Write(16, 16, "+ NGUYEN KHANH HOANG", 4, 15);
	Write(67, 16, "+ 22127127@STUDENT.HCMUS.EDU.VN", 4, 15);

	Write(16, 17, "+ NGUYEN VAN XUAN LOC", 4, 15);
	Write(67, 17, "+ 22127237@STUDENT.HCMUS.EDU.VN", 4, 15);

	Write(16, 18, "+ PHAM ANH VAN", 4, 15);
	Write(67, 18, "+ 22127450@STUDENT.HCMUS.EDU.VN", 4, 15);

	Write(12, 20, "_COURSE ADVISOR: ", 4, 15);
	Write(63, 20, "_COURSE NAME: ", 4, 15);

	Write(16, 21, "+ TRUONG TOAN THINH", 4, 15);
	Write(67, 21, "+ PROGRAMMING TECHNIQUE", 4, 15);

	Write(12, 23, "_VERISION: 1.9.01",0,15);

	
	Write(12, 24, "@ COPY RIGHTS 2023 ALL RIGHTS RESERVED",0,15);

	Write(40, 26, "Press any key to continue...", 0, 15);
	
}

void GraphicUI::Grp_Howtoplay_page1()
{
	hndl.Console_SetColor(15, 5);
	for (int i = 12; i <= 96; i++)
	{
		hndl.gotoXY(i, 12);
		putchar(205);
	}

	hndl.gotoXY(47, 12);
	cout << " HOW TO PLAY";

	hndl.Console_SetColor(15, 2);
	Write(12, 14, "_RULE: ", 2, 15);
	Write(16, 15, "1.The game is played on a grid that's 14 squares by 14 squares.", 2, 15);
	Write(16, 17, "2.You are X, your friend (or the computer) is O.",2,15);
	Write(18, 18, " Players take turns putting their marks in empty squares.", 2, 15);

	Write(16, 20, "3.The first player to get 5 of his marks in a row.", 2, 15);
	Write(18, 21, "(up, down, across, or diagonally) is the winner.", 2, 15);


	Write(16, 23, "4.When all 14x14 squares are full, the game is over.", 2, 15);
	Write(18, 24, "If no player has 5 marks in a row, the game ends in a tie.", 2, 15);
	
	Write(48, 30, "1/2 ->", 2, 15);
	
}

void GraphicUI::Grp_Howtoplay_page2()
{
	
	hndl.Console_SetColor(15, 5);
	for (int i = 12; i <= 96; i++)
	{
		hndl.gotoXY(i, 12);
		putchar(205);
	}

	hndl.Console_SetColor(15, 0);
	for (int j = 13; j <= 27; j++)
	{
		hndl.gotoXY(51, j);
		putchar(179);
	}

	Write(26, 14, "_ MOVE", 0, 15);
	Write(67, 14, "+ W,A,S,D, OR ARROW",0,15);

	hndl.Console_SetColor(15, 0);
	for (int i = 20; i <= 88; i++)
	{
		hndl.gotoXY(i, 16);
		putchar(196);
	}

	Write(26, 18, "_ INPUT", 0, 15);
	Write(67, 18, "+ ENTER", 0, 15);
	hndl.Console_SetColor(15, 0);
	for (int i = 20; i <= 88; i++)
	{
		hndl.gotoXY(i, 20);
		putchar(196);
	}

	Write(26, 22, "_ QUIT", 0, 15);
	Write(67, 22, "+ ESC", 0, 15);
	hndl.Console_SetColor(15, 0);
	for (int i = 20; i <= 88; i++)
	{
		hndl.gotoXY(i, 24);
		putchar(196);
	}

	Write(26, 26, "_ MENU", 0, 15);
	Write(67, 26, "+ M", 0, 15);

	Write(48, 30, "<-2/2", 2, 15);
	
}

void GraphicUI::Grp_Yesbox(bool on)
{
	if (on)
	{
		Drawbox_ver2(18, 19, 26, 6, 0, 15);
		hndl.Console_SetColor(15, 12);
		for (int i = 19; i <= 43; i++)
		{
			for (int j = 21; j <= 23; j++)
			{
				hndl.gotoXY(i, j);
				putchar(219);
			}
		}
		Write(30, 22, "YES", 15, 12);
	}
	else
	{
		hndl.Console_SetColor(15, 15);
		for (int i = 18; i <= 44; i++)
		{
			for (int j = 19; j <= 25; j++)
			{
				hndl.gotoXY(i, j);
				putchar(219);
			}
		}
		Drawbox_ver2(19, 20, 24, 4, 0, 15);
		Write(30, 22, "YES", 0, 15);
	}
	
}

void GraphicUI::Grp_Nobox(bool on)
{
	if (on)
	{
		Drawbox_ver2(64, 19, 26, 6, 0, 15);
		hndl.Console_SetColor(15, 10);
		for (int i = 65; i <= 89; i++)
		{
			for (int j = 21; j <= 23; j++)
			{
				hndl.gotoXY(i, j);
				putchar(219);
			}
		}
		Write(76, 22, "NO", 15, 10);
	}
	else
	{

		hndl.Console_SetColor(15, 15);
		for (int i = 64; i <= 90; i++)
		{
			for (int j = 19; j <= 25; j++)
			{
				hndl.gotoXY(i, j);
				putchar(219);
			}
		}
		Drawbox_ver2(65, 20, 24, 4, 0, 15);
		Write(76, 22, "NO", 0, 15);
	}
}

void GraphicUI::Quit_subBox()
{
	Drawbox_ver2(15, 13, 78, 14, 0, 15);
	Write(40, 15, "ARE YOU SURE WANT TO QUIT ?", 0, 15);

	Drawbox_ver2(19, 20, 24, 4, 0, 15);
	Write(30, 22, "YES", 0, 15);

	Drawbox_ver2(65, 20, 24, 4, 0, 15);
	Write(76, 22, "NO", 0, 15);

}


void GraphicUI::PlayAgainbox()
{
	Drawbox_ver2(15, 13, 78, 14, 0, 15);
	Write(40, 15, "DO YOU WANT TO PLAY AGAIN", 0, 15);

	Drawbox_ver2(19, 20, 24, 4, 0, 15);
	Write(30, 22, "YES", 0, 15);

	Drawbox_ver2(65, 20, 24, 4, 0, 15);
	Write(76, 22, "NO", 0, 15);
}