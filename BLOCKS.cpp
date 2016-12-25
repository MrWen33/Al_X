#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<thread>
#define Wid 30
using std::vector;
using namespace std;
void Printblock(int x[4][2] ,COLORREF color,int dx=0,int dy=0)
{
	setfillcolor(color);
	setlinecolor(color);
	for (int i = 0;i < 4;i++)
	{
		fillrectangle((x[i][0]+dx)*Wid+1, (x[i][1]+dy)*Wid+1, x[i][0]*Wid + Wid+dx*Wid-1, x[i][1]*Wid + Wid+dy*Wid-1);
	}
};

struct Midfinger
{
	int U[4][4][2] = { { {2,1}, {2,2}, {2,3}, {1,2} }
	,{ { 1,2},{ 2,2},{ 2,3 },{ 3,2 } }
	,{ { 2,1 },{ 2,2 },{ 2,3 },{ 3,2 } }
	,{ { 2,1 },{ 2,2 },{ 1,2 },{ 3,2 } } };
}Midfinger;

struct Ishape
{
	int U[4][4][2] = { { { 0,2 },{ 1,2 },{ 2,2 },{ 3,2 } }
	,{ { 2,1 },{ 2,2 },{ 2,3 },{ 2,4 } }
	,{ { 0,2 },{ 1,2 },{ 2,2 },{ 3,2 } }
	,{ { 2,1 },{ 2,2 },{ 2,3 },{ 2,4 } } };
}Ishape;

struct FBlocks
{
	int U[4][4][2] = { { { 2,1 },{ 3,1 },{ 2,2 },{ 3,2 } }
	,{ { 2,1 },{ 3,1 },{ 2,2 },{ 3,2 } }
	,{ { 2,1 },{ 3,1 },{ 2,2 },{ 3,2 } }
	,{ { 2,1 },{ 3,1 },{ 2,2 },{ 3,2 } } };
}FBlocks;

struct RLshape
{
	int U[4][4][2] = { { { 2,1 },{ 2,2 },{ 2,3 },{ 3,3 } },
	{ { 1,2 }, { 2,2 }, { 3,2 }, { 1,3 } },
	{ { 1, 1 }, { 2,1 }, { 2,2 }, { 2,3 } },
	{ { 1,2 }, { 2,2 }, { 3,2 }, { 3,1 } } };
}RLshape;

struct LLshape
{
	int U[4][4][2] = { { { 1,3 },{ 2,2 },{ 2,1 },{ 2,3 } },
	{ { 1, 1 },{ 1,2 },{ 2,2 },{ 3,2 } },
	{ { 2, 1 },{ 2,2 },{ 2,3 },{ 3,1 } },
	{ { 1, 2 },{ 2,2 },{ 3,2 },{ 3,3 } } };
}LLshape;

void FieldPrint(int field[19][12],int line)
{
	for (int i = line;i >= 0;i--)
	{
		for (int i1 = 1;i1 < 11;i1++)
		{
			if (field[i][i1] == 1)
			{
				setfillcolor(getpixel(Wid*i1 + 10, Wid*i - 10));
				setcolor(BLACK);
				fillrectangle(Wid*i1,Wid*i, Wid*(i1+1), Wid*i+ Wid);
			}
		}
	}
};
inline void setplay(int play[4][2], int ran1, int ran2, int dx, int dy);
void conblock(int &,int &,bool &);
inline bool kickblock(int play[4][2], int field[19][12]);
void clearblock(int linenum, int field[19][12]);
COLORREF colorchoice(int);
void clearblock(int field[19][12]);

void main()
{
	start:
	bool isfloor = 0, skip = 0;
	IMAGE up;
	int ran2, ran1, rancolor,reran1,reran2,recolor;
	TCHAR sco[5];
	TCHAR speed[5];
	int field[19][12],score=0,preplay[4][2];
	initgraph(490, 550);
	time_t start, end;
	for (auto &a : field)
	{
		for (int &b : a)
		{
			b = 0;
		}
		a[0] = 1;
		a[11] = 1;
	}
	for (auto &a : field[18])
	{
		a = 1;
	}
	srand((unsigned)time(NULL));
	rectangle(29, 9, 331, 541);
	vector<bool> isscore(18, 1);
	char quit;
	bool isdead=0;
	int predx, preran, dx = 3, dy = 0, play[4][2], pre[4][2];
	ran1 = rand() % 5;
	ran2 = rand() % 4;
	rancolor = rand() % 7;
	reran1 = rand() % 5;
	reran2 = rand() % 4;
	recolor = rand() % 7;
	setplay(play, ran1, ran2, dx, dy);
	while (1)
	{
		setplay(preplay, reran1, reran2, 12, 10);
		Printblock(preplay, colorchoice(recolor));
		_stprintf_s(sco, _T("%d"), score);
		_stprintf_s(speed, _T("%d"), (150 - 10 * score));
		settextcolor(CYAN);
		settextstyle(35, 0, "Score");
		outtextxy(340, 150, "Score");
		settextcolor(WHITE);
		settextstyle(50, 0, " ");
		outtextxy(370, 190, sco);
		settextstyle(35, 0, " ");
		outtextxy(340, 10, "Speed");
		outtextxy(340, 260, "NEXT£º");
		settextstyle(25, 0, " ");
		outtextxy(400, 40, "ms/¿é");
		outtextxy(340, 40, speed);
		srand((unsigned)time(NULL));
		predx = dx;
		preran = ran2;
		conblock(dx, ran2,skip);
		setplay(play, ran1, ran2, dx, dy);
		if (kickblock(play, field))
		{
			ran2 = preran;
		}
		setplay(play, ran1, ran2, dx, dy);
		if (kickblock(play, field))
		{
			setplay(play, ran1, ran2, predx, dy);
			dx = predx;
		}
		Printblock(play, colorchoice(rancolor));
		for (auto &pl : play)
		{
			if (field[pl[1] + 1][pl[0]] == 1)
			{
				isfloor = 1;
			}
		}
		if (!skip)
		{
			Sleep(150 - 10*score);
		}
		if (_kbhit())
		{
			isfloor = 0;
			dy--;
		}
		if (isfloor)
		{
			for (auto &pl : play)
			{
				field[pl[1]][pl[0]] = 1;
			}
			dy = 0;
			dx = 3;
			isfloor = 0;
			Printblock(preplay, BLACK);
			ran1 = reran1;
			ran2 = reran2;
			rancolor = recolor;
			reran1 = rand() % 5;
			reran2 = rand() % 4;
			recolor = rand() % 7;
			skip = 0;
		}
		else
		{
			Printblock(play, BLACK);
			dy++;
		}
		for (int i = 0;i < 18;i++)
		{
			for (auto &n : field[i])
			{
				if (n == 0)
				{
					isscore[i] = 0;
				}
			}
		}
		for (int i=0;i<isscore.size();i++)
		{
			if (isscore[i])
			{
				clearblock(i, field);
				FieldPrint(field,i);
				clearblock(field);
				score++;
			}
			isscore[i] = 1;
		}
		for (int i = 1;i < 11;i++)
		{
			if (field[2][i] == 1)
			{
				isdead = 1;
			}
		}
		if (isdead)
		{
			break;
		}
	}
	cleardevice();
	outtextxy(130,205,"You die");
	settextstyle(20, 0, " ");
	outtextxy(130, 255, "Final score:");
	outtextxy(250, 255, sco);
	while (1)
	{
		quit = _getch();
		if (quit == 'q')
		{
			break;
		}
		else if (quit == 'r')
		{
			goto start;
		}
	}

}

void clearblock(int linenum,int field[19][12])
{
	for (int i=linenum;i>0;i--)
	{
		for (int i1 = 1; i1 < 11; i1++)
		{
			field[i][i1] = field[i - 1][i1];
		}
	}
}

void clearblock(int field[19][12])
{
	for (int i = 17;i >0;i--)
	{
		for (int i1 = 1;i1 < 11;i1++)
		{
			if (field[i][i1] == 0)
			{
				setfillcolor(BLACK);
				setcolor(BLACK);
				fillrectangle(Wid*i1, Wid*i , Wid*(i1 + 1), Wid*i + Wid );
			}
		}
	}
}

void conblock(int &dx,int &ran1,bool &skip)
{
	char ipt = '2';
	if (_kbhit())
	{
		ipt = _getch();
		if (ipt == 'a')
		{
			dx--;
		}
		if (ipt == 'd')
		{
			dx++;
		}
		if (ipt == 'w')
		{
			ran1++;
			if (ran1 == 4)
			{
				ran1 = 0;
			}
		}
		if (ipt == 's')
		{
			skip = 1;
		}
	}
}

inline bool kickblock(int play[4][2],int field[19][12])
{
	bool k = 0;
	for (int c = 0;c <4;c++)
	{
		if (field[play[c][1]][play[c][0]] == 1)
		{
			k = 1;
		}
	}
	return k;
}

inline void setplay(int play[4][2], int ran1, int ran2,int dx,int dy)
{
	if (ran1 == 0)
	{
		play[0][0] = Midfinger.U[ran2][0][0] + dx;
		play[0][1] = Midfinger.U[ran2][0][1] + dy;
		play[1][0] = Midfinger.U[ran2][1][0] + dx;
		play[1][1] = Midfinger.U[ran2][1][1] + dy;
		play[2][0] = Midfinger.U[ran2][2][0] + dx;
		play[2][1] = Midfinger.U[ran2][2][1] + dy;
		play[3][0] = Midfinger.U[ran2][3][0] + dx;
		play[3][1] = Midfinger.U[ran2][3][1] + dy;
	}
	else if (ran1 == 1)
	{
		play[0][0] = Ishape.U[ran2][0][0] + dx;
		play[0][1] = Ishape.U[ran2][0][1] + dy;
		play[1][0] = Ishape.U[ran2][1][0] + dx;
		play[1][1] = Ishape.U[ran2][1][1] + dy;
		play[2][0] = Ishape.U[ran2][2][0] + dx;
		play[2][1] = Ishape.U[ran2][2][1] + dy;
		play[3][0] = Ishape.U[ran2][3][0] + dx;
		play[3][1] = Ishape.U[ran2][3][1] + dy;
	}
	else if (ran1 == 2)
	{
		play[0][0] = FBlocks.U[ran2][0][0] + dx;
		play[0][1] = FBlocks.U[ran2][0][1] + dy;
		play[1][0] = FBlocks.U[ran2][1][0] + dx;
		play[1][1] = FBlocks.U[ran2][1][1] + dy;
		play[2][0] = FBlocks.U[ran2][2][0] + dx;
		play[2][1] = FBlocks.U[ran2][2][1] + dy;
		play[3][0] = FBlocks.U[ran2][3][0] + dx;
		play[3][1] = FBlocks.U[ran2][3][1] + dy;
	}
	else if (ran1 == 3)
	{
		play[0][0] = RLshape.U[ran2][0][0] + dx;
		play[0][1] = RLshape.U[ran2][0][1] + dy;
		play[1][0] = RLshape.U[ran2][1][0] + dx;
		play[1][1] = RLshape.U[ran2][1][1] + dy;
		play[2][0] = RLshape.U[ran2][2][0] + dx;
		play[2][1] = RLshape.U[ran2][2][1] + dy;
		play[3][0] = RLshape.U[ran2][3][0] + dx;
		play[3][1] = RLshape.U[ran2][3][1] + dy;
	}
	else if (ran1 == 4)
	{
		play[0][0] = LLshape.U[ran2][0][0] + dx;
		play[0][1] = LLshape.U[ran2][0][1] + dy;
		play[1][0] = LLshape.U[ran2][1][0] + dx;
		play[1][1] = LLshape.U[ran2][1][1] + dy;
		play[2][0] = LLshape.U[ran2][2][0] + dx;
		play[2][1] = LLshape.U[ran2][2][1] + dy;
		play[3][0] = LLshape.U[ran2][3][0] + dx;
		play[3][1] = LLshape.U[ran2][3][1] + dy;
	}
}

COLORREF colorchoice(int ran)
{
	if (ran == 0)
	{
		return YELLOW;
	}
	else if (ran == 1)
	{
		return RED;
	}
	else if (ran == 2)
	{
		return GREEN;
	}
	else if (ran == 3)
	{
		return BLUE;
	}
	else if (ran == 4)
	{
		return CYAN;
	}
	else if (ran == 5)
	{
		return MAGENTA;
	}
	else if (ran == 6)
	{
		return BROWN;
	}
}