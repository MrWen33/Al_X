#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cin >> n;
	double fn = (1 / pow(5.0, 0.5))*(pow((1.0+ pow(5.0, 0.5))/2,n)- pow((1.0 - pow(5.0, 0.5)) / 2, n));
	int t = (int)fn;
	cout << t;
	return 0;
}