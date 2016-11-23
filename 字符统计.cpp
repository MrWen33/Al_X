#include<iostream>
#include<string>
using namespace std;
struct zifu
{
	char No;
	int count;
};
int main()
{
	zifu zifu[50];
	for (int i = 0;i < 50;i++)
	{
		zifu[i].No = '/0';
		zifu[i].count = 0;
	}
	string all;
	cin >> all;
	int size = all.size();
	int i1;
	for (int i = 0;i < size;i++)
	{
		for (int i1 = i;i1 < size;i1++)
		{
			int tempi = all[i];
			int tempi1 = all[i1];
			if (tempi > tempi1)
			{
				char temp;
				temp = all[i];
				all[i] = all[i1];
				all[i1] = temp;
			}
		}
	}
	for (int i = 0;i < size;i++)
	{
		for (zifu[i].No=all[i],i1=i;all[i1] == zifu[i].No;i1++)
		{
			zifu[i].count++;
		}
		i = i1-1;
	}
	for (int i = 0;i < size;i++)
	{
		if (zifu[i].No!='0')
		{
			cout << zifu[i].No << " " << zifu[i].count<<endl;
		}
	}
	return 0;
}