#include <iostream>
using namespace std;
long a[102][11];
int n;
int main()
{
	for (int i = 1; i < 10; i++)
		a[1][i] = 1;
	cin >> n;

		for (int i = 2; i <= n; i++)
			for (int j = 0; j < 10; j++)
			{
				if (j == 0)
				{
					a[i][j] = a[i - 1][j + 1];
				}
				else if(j == 9)
				{
					a[i][j] = a[i - 1][j - 1];
				}
				else
				{
					a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1] % 1000000000) ;
				}
			}
	long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += a[n][i];
	}

	cout << sum % 1000000000 << "\n";

	return 0;
}