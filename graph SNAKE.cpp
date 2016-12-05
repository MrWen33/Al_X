#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<vector>
int randomx();
int randomy();
void filltangle(int x1, int y1, COLORREF color);
using namespace std;
using std::vector;
int main()
{
	start:
	int  cnt = 0, cnt1 = 0,score=0;
	char input='s',preinput='s',exit,mode;
	bool judgekick = 0, judgemov = 1, judgecoin = 1, eat = 1;
	vector<vector<int> > snake_body(1000000);
	vector<int> food(2);
	snake_body[0].push_back(60);
	snake_body[0].push_back(60);
	snake_body[1].push_back(70);
	snake_body[1].push_back(60);
	snake_body[2].push_back(70);
	snake_body[2].push_back(70);
	initgraph(740,480);
	settextcolor(LIGHTCYAN);
	settextstyle(50, 0, "贪吃蛇");
	outtextxy(280, 180, "贪吃蛇");
	settextcolor(LIGHTBLUE);
	settextstyle(30, 0, "按任意键继续");
	outtextxy(270, 280, "按任意键继续");
	settextcolor(DARKGRAY);
	settextstyle(20, 0, "By Handso");
	outtextxy(640, 450, "By Handso");
	_getch();
	cleardevice();
	settextcolor(LIGHTCYAN);
	settextstyle(50, 0, "贪吃蛇");
	outtextxy(280, 180, "贪吃蛇");
	settextcolor(LIGHTBLUE);
	settextstyle(25, 0, "模式选择");
	outtextxy(300, 250, "模式选择");
	settextstyle(20, 0, "A.老人模式");
	outtextxy(300, 280, "A.老人模式");
	settextstyle(20, 0, "B.是男人就吃一百个模式");
	outtextxy(300, 300, "B.是男人就吃一百个模式");
	next1:
	mode=_getch();
	if (mode != 'a'&&mode != 'b')
	{
		goto next1;
	}
	cleardevice();
	TCHAR s[5];
	setcolor(RED);
	rectangle(630, 470, 10, 10);
	rectangle(625, 465, 15, 15);
	setcolor(WHITE);
	while (1)
	{
		settextcolor(DARKGRAY);
		settextstyle(20, 0, "By Handso");
		outtextxy(640, 450, "By Handso");
		settextcolor(WHITE);
		_stprintf_s(s, _T("%d"), score);
		settextstyle(30, 0, "Score");
		outtextxy(650, 40, "Score");
		settextstyle(30, 0, s);
		outtextxy(680, 80, s);
		for (;snake_body[cnt].empty();cnt++);
		for (;!snake_body[cnt].empty();cnt++)
		{
			if (food == snake_body[cnt])
			{
				judgecoin = 1;
			}
		}
		if (eat)
		{
			while (judgecoin)
			{
				food[0] = randomx();
				food[1] = randomy();
				judgecoin = 0;
				cnt = 0;
				for (;snake_body[cnt].empty();cnt++);
				for (;!snake_body[cnt].empty();cnt++)
				{
					if (food == snake_body[cnt])
					{
						judgecoin = 1;
					}
				}
			}
			setfillcolor(YELLOW);
			solidcircle(food[0]+5, food[1]+5,4);
		}
		cnt = 0;
		for (;snake_body[cnt].empty();cnt++);
		for (;!snake_body[cnt].empty();cnt++)
		{
			setcolor(BLACK);
			ellipse(snake_body[cnt][0], snake_body[cnt][1], snake_body[cnt][0] + 10, snake_body[cnt][1] + 10);
		}
		cnt--;
		setfillcolor(GREEN);
		setcolor(GREEN);
		fillellipse(snake_body[cnt][0], snake_body[cnt][1], snake_body[cnt][0] + 10, snake_body[cnt][1] + 10);
		cnt++;
		if (mode == 'b')
		{
			Sleep(101-score);
		}
		else
		{
			Sleep(100);
		}
		if (_kbhit())
		{
			input = _getch();
			if (input != 'a'&&input != 'w'&&input != 's'&&input != 'd'&&input != 'q')
			{
				input = preinput;
			}
		}
		if (input == 'd')
		{
			snake_body[cnt].push_back(snake_body[cnt - 1][0] + 10);
			snake_body[cnt].push_back(snake_body[cnt - 1][1]);
		}
		if (input == 's')
		{
			snake_body[cnt].push_back(snake_body[cnt - 1][0]);
			snake_body[cnt].push_back(snake_body[cnt - 1][1] + 10);
		}
		if (input == 'a')
		{
			snake_body[cnt].push_back(snake_body[cnt - 1][0] - 10);
			snake_body[cnt].push_back(snake_body[cnt - 1][1]);
		}
		if (input == 'w')
		{
			snake_body[cnt].push_back(snake_body[cnt - 1][0]);
			snake_body[cnt].push_back(snake_body[cnt - 1][1] - 10);
		}
		if (input == 'q')
		{
			break;
		}
		preinput = input;
		if (snake_body[cnt] == snake_body[cnt - 2])
		{
			judgemov = 0;
			snake_body[cnt].clear();
			eat = 0;
		}
		if (judgemov)
		{
			cnt = 0;
			for (;snake_body[cnt].empty();cnt++);
			for (cnt1 = cnt;!snake_body[cnt1].empty();cnt1++);
			if (snake_body[cnt1 - 1] != food)
			{
				filltangle(snake_body[cnt][0], snake_body[cnt][1], BLACK);
				snake_body[cnt].erase(snake_body[cnt].begin(), snake_body[cnt].end());
				eat = 0;
			}
			else
			{
				eat = 1;
				score++;
			}
			cnt1 = cnt + 1;
			for (cnt = cnt + 1;!snake_body[cnt].empty();cnt++);
			cnt--;
			for (;cnt1 < cnt;cnt1++)
			{
				if (snake_body[cnt1] == snake_body[cnt] ||
					snake_body[cnt][0]<15 || snake_body[cnt][0] >= 620 ||
					snake_body[cnt][1]<15 || snake_body[cnt][1] >= 460)
				{
					judgekick = 1;
				}
			}
			if (judgekick)
			{
				Sleep(1500);
				cleardevice();
				settextcolor(RED);
				settextstyle(50, 0, "Final score");
				outtextxy(240, 100, "Final score");
				settextcolor(WHITE);
				settextstyle(60, 0, s);
				outtextxy(350, 160, s);
				settextcolor(CYAN);
				settextstyle(35, 0, "按R重新开始");
				outtextxy(270, 240, "按R重新开始");
				settextstyle(35, 0, "按Q退出游戏");
				outtextxy(270, 290, "按Q退出游戏");
				exit:
				exit=_getch();
				if (exit == 'q')
				{
					break;
				}
				else if (exit == 'r')
				{
					goto start;
				}
				else
				{
					goto exit;
				}
			}
		}
		judgemov = 1;
		cnt = 0;
		judgecoin = 1;
	}
	return 0;
}

int randomx()
{
	srand((unsigned int)time(NULL)*time(NULL));
	int randomx = 2 + rand() % 60;
	return randomx * 10;
}

int randomy()
{
	srand((unsigned int)time(NULL)*time(NULL)*time(NULL));
	int randomy = 2 + rand() % 44;
	return randomy * 10;
}

void filltangle(int x1, int y1, COLORREF color)
{
	for (int i1 = x1;i1 <= x1 + 10;i1++)
	{
		for (int i2 = y1;i2 <= y1 + 10;i2++)
		{
			putpixel(i1, i2, color);
		}
	}
}