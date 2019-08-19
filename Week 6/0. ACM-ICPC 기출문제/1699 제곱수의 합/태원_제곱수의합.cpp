#include <iostream>
#include <algorithm>
using namespace std;
int n;
int k;
int cnt;
int dp[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int i = 1;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
	}
	for(int i = 2; i <= n; i++)
		for (int j = 2; j*j <= i; j++)
	{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	cout << dp[n] << "\n";
	return 0;
}
