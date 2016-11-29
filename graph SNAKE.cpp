#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<vector>
using namespace std;
using std::vector;
int main()
{
	int graphdetect = DETECT, graphmode, cnt = 0, cnt1 = 0;
	char input,preinput='s';
	bool judgekick=0,judgemov=1;
	vector<vector<int> > snake_body(1000000);
	snake_body[0].push_back(60);
	snake_body[0].push_back(60);
	snake_body[1].push_back(70);
	snake_body[1].push_back(60);
	snake_body[2].push_back(70);
	snake_body[2].push_back(70);
	initgraph(&graphdetect, &graphmode, " ");
	setcolor(RED);
	rectangle(630, 470, 10, 10);
	rectangle(625, 465, 15, 15);
	setcolor(WHITE);
	while (1)
	{
		setcolor(WHITE);
		for (;snake_body[cnt].empty();cnt++);
		for (;!snake_body[cnt].empty();cnt++)
		{
			rectangle(snake_body[cnt][0], snake_body[cnt][1], snake_body[cnt][0] + 10, snake_body[cnt][1] + 10);
		}
		input=_getch();
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
		}
		if(judgemov)
		{
			cnt = 0;
			for (;snake_body[cnt].empty();cnt++);
			setcolor(BLACK);
			rectangle(snake_body[cnt][0], snake_body[cnt][1], snake_body[cnt][0] + 10, snake_body[cnt][1] + 10);
			snake_body[cnt].erase(snake_body[cnt].begin(), snake_body[cnt].end());
			cnt1 = cnt + 1;
			for (cnt = cnt + 1;!snake_body[cnt].empty();cnt++);
			cnt--;
			for (;cnt1 < cnt;cnt1++)
			{
				if (snake_body[cnt1] == snake_body[cnt]||
					snake_body[cnt][0]<15||snake_body[cnt][0]>=620||
					snake_body[cnt][1]<15||snake_body[cnt][1]>=460)
				{
					judgekick = 1;
				}
			}
			if (judgekick)
			{
				break;
			}
		}
		judgemov = 1;
		cnt = 0;
	}
	return 0;
}

int randomx()
{
	srand((unsigned int)time(NULL));
	int randomx = 20 + rand() % 610;
	return randomx;
}

int randomy()
{
	srand((unsigned int)time(NULL));
	int randomy = 20 + rand() % 450;
	return randomy;
}