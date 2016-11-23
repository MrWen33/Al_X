#include<iostream>
using namespace std;
int main()
{
	int n,s,i,i1,a[100][100],s0=0;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		if (i <= (n / 2)+1)
		{
			for (i1 = 1;i1 <= n;i1++)
			{
				if (i1 >= i&i1 <= n + 1 - i)
				{
					int n1 = n - 2*(i-1);
					int s1 = n1*n1 - 2 * n1 + 2 - i1 +i;
					cout << s1<<" ";
					a[i][i1] = s1;
				}
				else if (i1 < i)
				{
					int s2 = a[i - 1][i1] + 1;
					cout << s2<<" ";
					a[i][i1] = s2;
				}
				else if (i1 > n+1-i)
				{
					int s3 = a[i - 1][i1] - 1;
					cout << s3<<" ";
					a[i][i1] = s3;
				}
			}
		}
		else 
		{
			for (i1 = 1;i1 <= n;i1++)
			{
				if (i1 <= i&i1 >= n + 1 - i)
				{
					int n1 = n - 2 * (n-i);
					int s1 = n1*n1 -n+i1+n-i;
					cout << s1 << " ";
					a[i][i1] = s1;
				}
				else if (i1 < i)
				{
					int s2 = a[i - 1][i1] + 1;
					cout << s2 << " ";
					a[i][i1] = s2;
				}
				else if (i1 > n + 1 - i)
				{
					int s3 = a[i - 1][i1] - 1;
					cout << s3 << " ";
					a[i][i1] = s3;
				}
			}
		}
		cout << endl;
	}
	for (i = 1;i <= (n/2)+1;i++)
	{
		int m = 2*i - 1;
		int m1 = m*m;
		int m2 = m*m - (m - 1);
		int m3 = m*m - 2 * (m - 1);
		int m4 = m*m - 3 * (m - 1);
		s0 = s0 + m1 + m2 + m3 + m4;
	}
	cout << s0-3;
	return 0;
}