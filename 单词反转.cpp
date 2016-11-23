#include<iostream>
#include<string>
using namespace std;
using std::string;
int main()
{
	string a[100];
	int i = 0;
    while(cin>>a[i])
	{
		i++;
	}
	i--;
	for (;i >= 0;i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}