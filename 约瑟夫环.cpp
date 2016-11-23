#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int pep[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 },k,num=12;
	cin >> k;
	int k1 = k - 1;
	while (k1 >= 12)
	{
		k1 -= 12;
	}
	for (;num != 1;num--)
	{
		pep[k1] = 0;
		for (int i=0;i < k;i++,k1++)
		{
			if (k1 >= 12)
			{
				k1 -= 12;
			}
			if (pep[k1] == 0)
			{
				i--;
			}
		}
		k1--;
		while (k1 >= 12)
		{
			k1 -= 12;
		}
		for (int i = 0;i < 12;i++)
		{
			cout << setw(3) << pep[i];
		}
		cout << endl;
	}
	for (int i = 0;i < 12;i++)
	{
		if (pep[i] != 0)
		{
			cout <<setw(3)<< pep[i];
		}
	}
	cin>>num;
	return 0;
}