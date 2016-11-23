#include<iostream>
#include<vector>
#include<stdlib.h>
using std::vector;
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> pointv(n);
	for (int i = 0;i < m;i++)
	{
		int start, end;
		cin >> start >> end;
		pointv[end - 1].push_back(start);
	}
	for (int i = 0;i < m;i++)
	{
		vector<int> sta;
		for (int i1 = 0;i1 < n;i1++)
		{
			if (pointv[i1].size() == 0)
			{
				sta.push_back(i1);
			}
		}
		for (int i1 = 0;i1 < n;i1++)
		{
			for (auto itr = sta.begin();itr != sta.end();itr++)
			{
				if (*itr == i1)
				{
					for (int i2 = 0;i2 < n;i2++)
					{
						if (pointv[i2].size() != 0)
						{
							next:
							for (auto itr1 = pointv[i2].begin();itr1 < pointv[i2].end();)
							{
								if (*itr1 == i1 + 1)
								{
									pointv[i2].erase(itr1);
									goto next;
								}
								else
								{
									itr1++;
								}
							}
						}
					}
				}
			}
		}
	}
	bool jug = 0;
	for (int i = 0;i < n;i++)
	{
		if (pointv[i].size() != 0)
		{
			jug = 1;
		}
	}
	if (jug)
	{
		cout << "no";
	}
	else
	{
		cout << "yes";
	}
	system("pause");
	return 0;
}