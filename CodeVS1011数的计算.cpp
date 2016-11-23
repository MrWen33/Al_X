#include<iostream>
using namespace std;
int nyr(int n);
int main()
{
	int n;
	cin >> n;
	cout << nyr(n);
	
}
int nyr(int n)
{
	int s;
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int a = n / 2;
		s = 1;
		for (int i = 1;i <= a;i++)
		{
			s += nyr(i);
		}
		return s;
	}
}