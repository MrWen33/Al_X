#include<iostream>
using namespace std;
int f(int x,int &cnt)
{
	if (x == 1)
	{
		return 0;
	}
	else if (x % 2 == 0)
	{
		f(x / 2,cnt);
	}
	else if (x % 2 != 0)
	{
		f(3*x + 1,cnt);
	}
	cnt++;
	return cnt;
};
int main()
{
	int T,n,cnt=0,cstep=0;
	cin >> T;
	for (;cnt < T;cnt++)
	{
		cin >> n;
		if (n > 0)
		{
			cout << f(n, cstep) << endl;
			cstep = 0;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}
