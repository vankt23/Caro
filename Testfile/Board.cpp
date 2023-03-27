#include "Board.h"

Board::Board(int psize, int pX, int pY) 
{
	size = psize;
	left = pX;
	top = pY;
	point_arr = new Point * [psize];
	for (int i = 0; i < psize; i++)
	{
		point_arr[i] = new Point[psize];
	}
	countX = countO = 0;
	win = NULL;
}

Board::~Board()
{
	for (int i = 0; i < size; i++)
	{
		delete[]point_arr[i];
	}
	delete point_arr;
	point_arr = NULL;
	win = NULL;
}

int Board:: Board_getsize()
{
	return size;
}

int Board::Board_getleft()
{
	return left;
}

int Board::Board_gettop()
{
	return top;
}

int Board::Board_getcountX()
{
	return countX;
}

int Board::Board_getcountO()
{
	return countO;
}

int Board::Board_getposX(int i, int j)
{
	return point_arr[i][j].Point_getX();
}

int Board::Board_getposY(int i, int j)
{
	return point_arr[i][j].Point_getY();
}

void Board::Board_reset()
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			point_arr[i][j].Point_setX(4 * j + left + 3);
			point_arr[i][j].Point_setY(2 * i + top + 1);
			//Estimate the value of coordinate (x,y) of each Point on the board

			point_arr[i][j].Point_setFlag(0);
		}
	}
	countX = countO = 0;
}

void Board::Board_draw()
{

	

	//Draw top border
	Basic::gotoXY(left + 1, top);
	putchar(201);
	for (int i = 1; i < size * 4; i++)
	{
		sleep_for(nanoseconds(3000));	//for animation purpose
		if (i % 4 == 0)
		{
			putchar(209);
		}
		else
		{
			putchar(205);
		}
			
	}
	putchar(187);

	//Draw right border
	for (int i = 1; i < size * 2; i++)
	{
		sleep_for(nanoseconds(3500));
		Basic::gotoXY(size * 4 + left + 1, i + top);
		if (i % 2 == 0)
		{
			putchar(182);
		}
		else
		{
			putchar(186);
		}
	}
	Basic::gotoXY(size * 4 + left + 1, size * 2 + top);
	putchar(188);

	//Draw bottom border
	for (int i = 1; i < size * 4; i++)
	{
		Basic::gotoXY(size * 4 + left - i + 1, size * 2 + top);
		sleep_for(nanoseconds(3000));
		if (i % 4 == 0)
		{
			putchar(207);
		}
		else
		{
			putchar(205);
		}
	}
	Basic::gotoXY(left + 1, size * 2 + top);
	putchar(200);

	//Draw left border
	for (int i = 1; i < size * 2; i++)
	{
		sleep_for(nanoseconds(3500));
		Basic::gotoXY(left + 1, size * 2 + top - i);
		if (i % 2 == 0)
		{
			putchar(199);
		}
		else
		{
			putchar(186);
		}
	}

	//Draw vertical lines:
	for (int i = 1; i < size * 2; i++)
	{
		for (int j = 4; j < size * 4; j += 4)
		{
			if (i % 2 == 1)
			{
				Basic::gotoXY(j + left + 1, i + top);
				putchar(179);
			}
		}
		sleep_for(nanoseconds(3500));
	}

	//Draw horizontal line
	for (int i = 1; i < size * 4; i++)
	{
		for (int j = 2; j < size * 2; j += 2)
		{
			Basic::gotoXY(i + left + 1, j + top);
			if (i % 4 == 0)
			{
				putchar(197);
			}
			else
			{
				putchar(196);
			}

		}
		sleep_for(nanoseconds(3500));
	}

} 

int Board::Board_setMove(int px, int py, int turn)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (point_arr[i][j].Point_getX() == px && point_arr[i][j].Point_getY() == py)
			{
				if (point_arr[i][j].Point_getFlag() == 0)
				{
					if (turn == 1)
					{
						countX += 1;
						point_arr[i][j].Point_setFlag(1);
					}
					if (turn == -1)
					{
						countO += 1;
						point_arr[i][j].Point_setFlag(-1);
					}
					return point_arr[i][j].Point_getFlag();
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return -10;

}

int Board::Board_getFlag(int pX, int pY)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (point_arr[i][j].Point_getX() == pX && point_arr[i][j].Point_getY() == pY)
			{
				return point_arr[i][j].Point_getFlag();
			}
		}
	}

	return -10;
}

bool Board::Board_Wincol_check(int i, int j, int flag)
{
	int count = -1;

	int pu = i;	//point under
	while (point_arr[pu][j].Point_getFlag() == flag)
	{
		if (pu == size - 1)
		{
			count += 1;
			break;
		}
		count += 1;
		pu += 1;
		
	}
	
	int pa = i;		//point above
	while (point_arr[pa][j].Point_getFlag() == flag)
	{
		if (pa == 0)
		{
			count += 1;
			break;
		}
		count += 1;
		pa -= 1;
		
	}

	if (count >= 5)
	{
		win = new Point[5];
		if (pa == 0 && point_arr[pa][j].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(pa + tmp);
				win[tmp].Point_setY(j);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (pu == size - 1 && point_arr[pu][j].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(pu - tmp);
				win[tmp].Point_setY(j);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[pa][j].Point_getFlag() == -flag && point_arr[pu][j].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(pu - tmp);
				win[tmp].Point_setY(j);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[pa][j].Point_getFlag() == flag && point_arr[pu][j].Point_getFlag() != flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(pa + tmp);
				win[tmp].Point_setY(j);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[pa][j].Point_getFlag() != flag && point_arr[pu][j].Point_getFlag() != flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(pa + tmp +1);
				win[tmp].Point_setY(j);
				win[tmp].Point_setFlag(flag);
			}
				return true;
		}
	}
	return false;
}


bool Board::Board_Winrow_check(int i, int j, int flag)
{
	int count = -1;

	int pr = j;
	while (point_arr[i][pr].Point_getFlag() == flag)
	{
		if (pr == size - 1)
		{
			count++;
			break;
		}
		count += 1;
		pr += 1;
	}

	int pl = j;
	while (point_arr[i][pl].Point_getFlag() == flag)
	{
		if (pl == 0)
		{
			count++;
			break;
		}
		count += 1;
		pl -= 1;
	}

	if (count >= 5)
	{
		win = new Point[5];
		if (pr == size - 1 && point_arr[i][pr].Point_getFlag() == flag)
		{
			
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i);
				win[tmp].Point_setY(pr - tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (pl == 0 && point_arr[i][pl].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i);
				win[tmp].Point_setY(pl + tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[i][pr].Point_getFlag() == flag && point_arr[i][pl].Point_getFlag() != flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i);
				win[tmp].Point_setY(pr - tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[i][pr].Point_getFlag() != flag && point_arr[i][pl].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i);
				win[tmp].Point_setY(pl + tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[i][pr].Point_getFlag() != flag && point_arr[i][pl].Point_getFlag() != flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i);
				win[tmp].Point_setY(pl + tmp + 1);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}
	}
	return false;

}


bool Board::Board_WinmainDiag_check(int i, int j, int flag)
{
	int count = -1;

	int i_up = i;
	int j_left = j;
	while (point_arr[i_up][j_left].Point_getFlag() == flag)
	{
		if (i_up <= 0 || j_left <= 0)
		{
			count += 1;
			break;
		}
		count += 1;
		i_up -= 1;
		j_left -= 1;
	}

	int i_down = i;
	int j_right = j;
	while (point_arr[i_down][j_right].Point_getFlag() == flag)
	{
		if (i_down >= size - 1 || j_right >= size - 1)
		{
			count += 1;
			break;
		}
		count += 1;
		i_down += 1;
		j_right += 1;
	}

	if (count >= 5)
	{
		win = new Point[5];

		if (point_arr[i_up][j_left].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_up + tmp);
				win[tmp].Point_setY(j_left + tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[i_down][j_right].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_down - tmp);
				win[tmp].Point_setY(j_right - tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (!(point_arr[i_down][j_right].Point_getFlag() == flag) && !(point_arr[i_up][j_left].Point_getFlag() == flag))
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_down - tmp - 1);
				win[tmp].Point_setY(j_right - tmp - 1);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

	}
	return false;
}

bool Board::Board_WinextraDiag_check(int i, int j, int flag)
{
	int count = -1;

	int i_up = i;
	int j_right = j;
	while (point_arr[i_up][j_right].Point_getFlag() == flag)
	{
		if (i_up <= 0 || j_right >= size - 1)
		{
			count += 1;
			break;
		}
		count += 1;
		i_up -= 1;
		j_right += 1;
	}

	int i_down = i;
	int j_left = j;
	while (point_arr[i_down][j_left].Point_getFlag() == flag)
	{
		if (i_down >= size - 1 || j_left <= 0)
		{
			count += 1;
			break;
		}
		count += 1;
		i_down += 1;
		j_left -= 1;
	}

	if (count >= 5)
	{
		win = new Point[5];
		if (point_arr[i_up][j_right].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_up + tmp);
				win[tmp].Point_setY(j_right - tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (point_arr[i_down][j_left].Point_getFlag() == flag)
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_down - tmp);
				win[tmp].Point_setY(j_left + tmp);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}

		if (!(point_arr[i_up][j_right].Point_getFlag() == flag) && !(point_arr[i_down][j_left].Point_getFlag() == flag))
		{
			for (int tmp = 0; tmp < 5; tmp++)
			{
				win[tmp].Point_setX(i_down - tmp - 1);
				win[tmp].Point_setY(j_left + tmp + 1);
				win[tmp].Point_setFlag(flag);
			}
			return true;
		}
	}
	return false;

}

int Board::Board_Win_check(int px, int py)
{
	if (countO + countX == size * size)
	{
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (point_arr[i][j].Point_getX() == px && point_arr[i][j].Point_getY() == py)
			{
				int turn = point_arr[i][j].Point_getFlag();
				if (Board_Wincol_check(i, j, turn) || Board_Winrow_check(i, j, turn) || Board_WinmainDiag_check(i, j, turn) || Board_WinextraDiag_check(i, j, turn))
				{
					return turn;
				}
			}
		}
	}
	
	return 2;
	
}
