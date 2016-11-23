#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int graphdriver = DETECT, graphmode;
	double angle = 0.0;
	int m,n=6666,s;
	scanf_s("%d%d",&m,&s);
	initgraph(&graphdriver, &graphmode, "..\\BGI\\");
	for (double x1, y1;angle < 720;angle+=m,n+=6*n)
	{
		y1 = 150+100*(1.7*cos(angle*3.1415926/360)-cos( 2*angle*3.1415926 / 360));
		x1 = 300+79 * (2 * sin(angle*3.1415926 / 360) - sin(2*angle*3.1415926 / 360));
		setcolor(0x9f);
		circle(x1, y1,s);
	}
	system("pause");
	closegraph();
}