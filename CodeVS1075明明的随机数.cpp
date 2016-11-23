#include<iostream>
using namespace std;
int main ()
{
	int n,s=0;
	cin >> n;
	int a[200];
	int i = 0;
	for (;i < 200;i++) {
		a[i] = '\0';
	}
	for (i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (i = 0;a[i] != '\0';i++) {
		for (int i1 = i;i1 < 200;i1++) {
			if (a[i1] <= a[i]) {
				int temp;
				temp = a[i];
				a[i] = a[i1];
				a[i1] = temp;
			}
		}
	}
	for (i = 1;a[200 - i] != '\0';i++) {
		a[n-i] = a[200 - i];
		a[200 - i] = '\0';
	}
	for (i = 0;i < n;i++) {
		if (a[i] != a[i + 1]) {
			cout << a[i] << " ";
			s++;
		}
		else {}
	}
	return 0;
}