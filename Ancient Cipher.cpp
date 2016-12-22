#include<iostream>
#include<string>
#include<vector>
using std::vector;
using namespace std;
struct zifu
{
	char No;
	int count;
};
int main()
{
	zifu zifu[100],zifu1[100];
	for (int i = 0;i < 100;i++)
	{
		zifu[i].No = '\0';
		zifu[i].count = 0;
		zifu1[i].No = '\0';
		zifu1[i].count = 0;
	}
	string all,all1;
	cin >> all>>all1;
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
		for (zifu[i].No = all[i], i1 = i;all[i1] == zifu[i].No;i1++)
		{
			zifu[i].count++;
		}
		i = i1 - 1;
	}
	int size1 = all1.size();
	i1=0;
	for (int i = 0;i < size1;i++)
	{
		for (int i1 = i;i1 < size1;i1++)
		{
			int tempi = all1[i];
			int tempi1 = all1[i1];
			if (tempi > tempi1)
			{
				char temp;
				temp = all1[i];
				all1[i] = all1[i1];
				all1[i1] = temp;
			}
		}
	}
	for (int i = 0;i < size;i++)
	{
		for (zifu1[i].No = all1[i], i1 = i;all1[i1] == zifu1[i].No;i1++)
		{
			zifu1[i].count++;
		}
		i = i1 - 1;
	}
	int www=0, www1=0;
	for (int i = 0;i<100;i++)
	{
		if (zifu[i].No != '\0')
		{
			www++;
		}
	}
	for (int i = 0;i<100;i++)
	{
		if (zifu1[i].No != '\0')
		{
			www1++;
		}
	}
	vector<int> z(www), z1(www1);
	for (int i = 0;i<100;i++)
	{
		if (zifu[i].No != '\0')
		{
			z.push_back(zifu[i].count);
		}
	}
	for (int i = 0;i<100;i++)
	{
		if (zifu1[i].No != '\0')
		{
			z1.push_back(zifu1[i].count);
		}
	}
	for (int i = 0;i < z.size();i++)
	{
		for (int i1 = i;i1 < z.size();i1++)
		{
			if (z[i] < z[i1])
			{
				int temp = 0;
				temp = z[i];
				z[i] = z[i1];
				z[i1] = temp;
			}
		}
	}
	for (int i = 0;i < z1.size();i++)
	{
		for (int i1 = i;i1 < z1.size();i1++)
		{
			if (z1[i] < z1[i1])
			{
				int temp = 0;
				temp = z1[i];
				z1[i] = z1[i1];
				z1[i1] = temp;
			}
		}
	}
	if (z == z1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}