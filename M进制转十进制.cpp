#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	double m, s = 0;
	string n;
	cin >> n ;
	cin >> m;
	double c = n.size();
	for (int i = 0;i<c;i++)
	{
		if (n[i]<58) 
		{
			s += (n[i]-48)*pow(m,c-1-i);
		}
		else if(n[i]=='A')
		{
			s += 10*pow(m,c-1-i);
		}
		else if (n[i] == 'B')
		{
			s += 11 * pow(m, c - 1 - i);
		}
		else if (n[i] == 'C')
		{
			s += 12 * pow(m, c - 1 - i);
		}
		else if (n[i] == 'D')
		{
			s += 13 * pow(m, c - 1 - i);
		}
		else if (n[i] == 'E')
		{
			s += 14 * pow(m, c - 1 - i);
		}
		else if (n[i] == 'F')
		{
			s += 15 * pow(m, c - 1 - i);
		}
	}
	cout << s;
	return 0;
}