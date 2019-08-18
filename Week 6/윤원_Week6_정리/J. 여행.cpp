#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 99999
using namespace std;
int val[301][301];
int cache[301][301];
int m, n, k;
void search()
{
	int start, end, valse;

	cin >> start >> end >> valse;

	if (start >= end)
		return;
	val[start][end] = max(val[start][end], valse);
}

int dp(int city, int count)
{
	if (count == m && city != n)
		return -INF;
	if (city == n)
		return 0;

	int& result = cache[city][count];
	if (result != -1)
		return result;

	result = 0;

	for (int to = city + 1; to <= n; to++)
	{
		if (val[city][to])
			result = max(result, val[city][to] + dp(to, count + 1));
	}
	return result;
}
int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		search();
	}
	memset(cache, -1, sizeof(cache));
	cout << dp(1, 1) << "\n";
	return 0;

}