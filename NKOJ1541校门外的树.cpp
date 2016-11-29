#include<iostream>
#include<vector>
using std::vector;
using namespace std;
int main()
{
	int L, M,i=0,a1,a2,s=0;
	cin >> L >> M;
	vector<vector<int> > array(M);
	vector<int> len(L+1, 1);
	for ( i = 0; i < M; i++)
	{
		cin >> a1 >> a2;
		array[i].push_back(a1);
		array[i].push_back(a2);
	}
	for (int i = 0;i <= L;i++)
	{
		for (int i1 = 0;i1 < M;i1++)
		{
			if (i >= array[i1][0] && i <= array[i1][1])
			{
				len[i] = 0;
			}
		}
	}
	for (int i2=0;i2<=L;i2++)
	{
		if (len[i2] == 1)
		{
			s++;
		}
	}
	cout << s<<endl;
	return 0;
}