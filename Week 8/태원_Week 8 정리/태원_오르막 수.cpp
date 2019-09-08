#include <iostream>
using namespace std;
int dp[1001][10];
int n;
void Uphillnumber()
{
		for (int i = 0; i < 10; i++)
		{
			dp[1][i] = 1;
		}
		if (n == 1)
			return;
		for(int i = 2; i <= n; i++)
			for (int j = 0; j < 10; j++)
				for(int k = j; k < 10; k++)
			{
					dp[i][k] += dp[i - 1][j];
					dp[i][k] = dp[i][k] % 10007;
			}
	}

int main()
{
	cin >> n;
	int sum = 0;
	Uphillnumber();
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i] % 10007;
	}
	cout << sum % 10007 << "\n";
	return 0;
}