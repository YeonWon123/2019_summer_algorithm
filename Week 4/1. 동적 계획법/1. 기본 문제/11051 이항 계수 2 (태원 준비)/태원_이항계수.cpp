#include <iostream>
#define max 10007
using namespace std;

int combi[1001][1001];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 1000; i++)
	{
		combi[i][0] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i > j)
				combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % max;
			else if (i == j)
			{
				combi[i][j] = 1;
				break;
			}
		}
	}
	cout << combi[n][k] << "\n";

	return 0;
}


