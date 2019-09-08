#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int mod = 10007;

int main() {
	//scanf("%d", &n);
	string out_line;

	for (int k = 1; k <= 1000; k++) {
		int n, i, j, ans, dp[10001][10];
		n = k; ans = 0;
		out_line = to_string(k) + ".in";
		ofstream out(out_line);
		out << k;
		out.close();

		for (i = 0; i <= 9; i++) dp[1][i] = 1;
		for (i = 2; i <= n; i++) {
			dp[i][0] = dp[i - 1][0];
			for (j = 1; j <= 9; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
		for (i = 0; i <= 9; i++) {
			ans = (ans + dp[n][i]) % mod;
		}

		string out_pr = to_string(k) + ".out";
		ofstream out2(out_pr);
		out2 << ans;
		out2.close();

	}
	return 0;
}