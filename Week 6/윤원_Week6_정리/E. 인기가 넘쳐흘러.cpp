#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

int input[310], weight[310][310], dp[310][310];
std::vector<std::pair<int, int>> interval;
int n, m, k, t;

int func(int x, int y) {
	if (x == interval.size())
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i <= k - y; i++)
		dp[x][y] = std::max(dp[x][y], func(x + 1, y + i) + weight[x][i]);

	return dp[x][y];
}

int main(void) {
	scanf("%d %d %d %d", &n, &m, &k, &t);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int j = a; j < b; j++)
			input[j]++;
	}

	int start = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		if (input[i] >= t) {
			if (i != start) {
				interval.push_back(std::make_pair(start, i - 1));
			}
			r++;
			start = i + 1;
		}
	}
	if (start <= n)
		interval.push_back(std::make_pair(start, n));

	for (int i = 0; i < interval.size(); i++) {
		for (int j = 1; j <= k; j++) {
			for (int z = interval[i].first; z <= interval[i].second; z++) {
				if (input[z] + j >= t) {
					weight[i][j]++;
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", func(0, 0) + r);
}