#include<iostream>
#include<string>
#include<vector>
using std::vector;
using namespace std;
int main()
{
	int i,i1,cnt=0,i2=0;
	string num1, num2;
	vector<int> ans(1,0);
	cin >> num1 >> num2;
	if (num1.size() < num2.size())
	{
		string temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	for (i = 0;i < num1.size()-num2.size();i++)
	{
		ans.push_back(num1[i]-48);
	}
	for (i1 = i;i1 < num1.size();i1++,i2++)
	{
		ans.push_back(num1[i1]+num2[i2]-96);
	}
	for (i = ans.size()-1;i != 0;i--)
	{
		while (ans[i] >= 10)
		{
			ans[i] -= 10;
			cnt++;
		}
		ans[i - 1] += cnt;
		cnt = 0;
	}
	if (ans[0] == 0)
	{
		for (i = 1;i < ans.size();i++)
		{
			cout << ans[i];
		}
	}
	else
	{
		for (i = 0;i < ans.size();i++)
		{
			cout << ans[i];
		}
	}
	cout << endl;
	return 0;
}