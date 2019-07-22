#include <iostream>
using namespace std;
int a[2][41];
int main()
{
	a[0][0] = 1;
	a[1][0] = 0;
	a[1][0] = 0;
	a[1][1] = 1;
	for (int i = 2; i < 41; i++)
	{
		a[0][i] = a[0][i - 1] + a[0][i - 2];
		a[1][i] = a[1][i - 1] + a[1][i - 2];
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		cout << a[0][k] << " " << a[1][k] << "\n";
	}
	return 0;
}
