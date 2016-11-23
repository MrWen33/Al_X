#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	char a[100], b[100];
	for (;i<100;i++)
	{
		a[i] = '\0';
		b[i] = '\0';
	}
	cin >> a >> b;
	char *m = a, *n = b;
	for (i = 0;b[i] != '\0';i++)
	{
	}
	int t = i+1;
	i = 1;
next1:
	if (*m == *n)
	{
		int i0 = 1;
		for (;*m == *n&*m!='\0';m++, n++, i0++)
		{
		}
		if (i0 != t)
		{
			for(;i0>1;i0--,i++)
			{
				n--;
			}
			goto next1;
		}
		else {}
	}
	else
	{
		m++;
		i++;
		goto next1;
	}
	cout << i;
	return 0;
}