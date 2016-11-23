#include<iostream>
using namespace std;
int main()
{
	double n,i=1;
	cin >> n;
	for (;i < 10000000&n>0;i++)
	{
		n -= 4*i - 3;
	}
	i = i - 1;
	n += 4 * (i) - 3;
	double t = 2 * i - 1;
	n -= t;
	if (t == 1)
	{
		cout << "1";
	}
	else
	{
	    if(n>0)
	    {
		    cout << (t - n)<<"/"<< (1 + n);
	    }
	    else
	    {
			cout << (t + n) << "/" << (-n);
	    }
	}
	return 0;
}