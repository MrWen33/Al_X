#include<iostream>
using namespace std;
int main()
{
	int n;
	bool j=1;
	cin >> n;
	if (n % 2 == 0)
	{
		if (n == 2)
		{
			cout << "\\t";
		}
		else
		{
			cout << "\\n";
		}
	}
	else
	{
		for (int i=2;i<n;i++)
		{
			if (n%i==0)
			{
				j = 0;
			}
			else 
			{

			}
		}
		if (j == 0)
		{
			cout << "\\n";
		}
		else
		{
			cout << "\\t";
		}
	}
	return 0;
}