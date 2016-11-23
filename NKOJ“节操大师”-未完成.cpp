#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, k,i,i1=0;
	cin >> n >> k;
	if (k >= n / 2)
	{
		cout << 1;
	}
	else
	{
		int n1 = n;
		for ( i = 0;n1 >= pow(2, i) && k >= pow(2, i+1);i++)
		{
			n1 -= pow(2, i);
		}
		if (k >= pow(2, i))
		{
			n1 -= 2*pow(2, i);
		}
		else
		{

		}
		cout << n1;
	}
	return 0;
}