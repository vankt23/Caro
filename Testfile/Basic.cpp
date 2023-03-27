#include "Basic.h"
#include<iostream>
using namespace std;
/*
	Color menu:
		0: Black
		1: Blue
		2: Green
		3: Aqua
		4: Red
		5: Purple
		6: Yellow
		7: White
		8: Grey
		9: Light blue
		10: Light Green
		11: Cyan
		12: Light red
		13: Light Purple
		14: Golden
		15: Bright white
*/

HWND Basic::consoleWindow = GetConsoleWindow();
HANDLE Basic::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void Basic:: textcolor(int x)
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, x);
}

void Basic::SetColor(WORD color)
{
	HANDLE consoleOutput;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(consoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(consoleOutput, wAttributes);
}

void Basic::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { (short int) (x - 1),(short int) (y - 1) };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Basic::ShowCursor(bool s)
{
	CONSOLE_CURSOR_INFO info = { 1, s };
	SetConsoleCursorInfo(consoleOutput, &info);
}

int Basic::GetKeyInput()
{
	int c = _getch();
	if (c == 0 || c == 224)
	{
		int c2 = _getch();
		switch (c2)
		{
		case 72: return 1; //up arrow
		case 75: return 2; // left arrow
		case 80: return 3; // down arrow
		case 77: return 4; // right arrow
		default: return 0;
		}
	}
	else
	{
		if (c == 87 || c == 119) return 1; //w or W
		if (c == 65 || c == 97)  return 2; // a or A
		if (c == 83 || c == 115) return 3; // s or S
		if (c == 68 || c == 100) return 4; // d or D
		if (c == 27)             return 5;// Esc
		if (c == 32 || c == 13)  return 6;//space or enter
		if (c == 72 || c == 104) return 7;// h or H
		if (c == 77 || c == 109) return 8; //m or M
		return 0;
	}

}

void Basic::PlayMusic(int i)
{
	//Input music here (wav file only)
	static vector<const wchar_t*> soundFile{ L"DokiDoki.wav",L"win.wav" };
	PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
}

void Basic::Console_SetAndCenterWindow()
{
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1216;
	int height = 784;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}

void Basic::Console_SetColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
	//background*16 + text: the formula give the correct combination of background and text

}

void Basic::Console_SetTitle()
{
	//input console title here
	SetConsoleTitleA("TIC TAC TOE");
}

void Basic::Console_SetFont()
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;//input width here
	info.dwFontSize.Y = 24;//input height here
	wcscpy_s(info.FaceName, L"Consolas");//input font here
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);

	//Font: Consolas, Size: 24
}

void Basic::Console_DisableMaxSize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void Basic::Console_HideScrollBar()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void Basic::Console_ClearScreen()
{
	system("cls");
}

void Basic::Console_DisableMouse()
{

	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void Basic::Console_Setup()
{
	Console_SetFont();
	Console_SetAndCenterWindow();
	Console_SetTitle();
	Console_HideScrollBar();
	ShowCursor(true);
	//Console_DisableMouse();
	Console_DisableMaxSize();
}

