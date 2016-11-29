#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<vector>
int randomx();
int randomy();
using namespace std;
using std::vector;
int main()
{
	int graphdetect = DETECT, graphmode, cnt = 0, cnt1 = 0;
	char input;
	bool judgekick=0,judgemov=1,judgecoin=1,eat=1;
	vector<vector<int> > snake_body(1000000);
	vector<int> food(2);
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
			setcolor(GREEN);
			rectangle(food[0], food[1], food[0] + 10, food[1] + 10);
		}
		cnt = 0;
		for (;snake_body[cnt].empty();cnt++);
		for (;!snake_body[cnt].empty();cnt++)
		{
			setcolor(WHITE);
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
		if (snake_body[cnt] == snake_body[cnt - 2])
		{
			judgemov = 0;
			snake_body[cnt].clear();
			eat = 0;
		}
		if(judgemov)
		{
			cnt = 0;
			for (;snake_body[cnt].empty();cnt++);
			for (cnt1=cnt;!snake_body[cnt1].empty();cnt1++);
			if (snake_body[cnt1-1] != food)
			{
				setcolor(BLACK);
				rectangle(snake_body[cnt][0], snake_body[cnt][1], snake_body[cnt][0] + 10, snake_body[cnt][1] + 10);
				snake_body[cnt].erase(snake_body[cnt].begin(), snake_body[cnt].end());
				eat = 0;
			}
			else
			{
				eat = 1;
			}
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
		judgecoin = 1;
	}
	return 0;
}

int randomx()
{
	srand((unsigned int)time(NULL)*time(NULL));
	int randomx = 2 + rand() % 60;
	return randomx*10;
}

int randomy()
{
	srand((unsigned int)time(NULL)*time(NULL)*time(NULL));
	int randomy = 2 + rand() % 44;
	return randomy*10;
}
