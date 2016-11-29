#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	int num[9],sum=0,cnt=0,md;
	while (getline(cin, line))
	{
		num[0] = line[0] - 48;
		num[1] = line[2] - 48;
		num[2] = line[3] - 48;
		num[3] = line[4] - 48;
		num[4] = line[6] - 48;
		num[5] = line[7] - 48;
		num[6] = line[8] - 48;
		num[7] = line[9] - 48;
		num[8] = line[10] - 48;
		for (;cnt < 9;cnt++)
		{
			sum += num[cnt] * (cnt + 1);
		}
		md = sum%11;
		if (md == 10&&line[12]=='X')
		{
			cout << "Right" << endl;
		}
		else if(md==line[12]-48)
		{
			cout << "Right" << endl;
		}
		else if (md == 10)
		{
			line[12] = 'X';
			cout << line << endl;
		}
		else if (md != line[12])
		{
			char a = md + 48;
			line[12] = a;
			cout << line << endl;
		}
		sum = 0, cnt = 0;
	}
	return 0;
}