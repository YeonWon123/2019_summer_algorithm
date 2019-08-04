#include<cstdio>
#include<cstring>

#include<iostream>
using namespace std;


int a[501][2];
int DP[501][501];


int solve(int i, int j)
{
	if (i == j) return 0;

	if (i + 1 == j) {

		return a[i][0] * a[i][1] * a[j][1];
	}


	int &ret = DP[i][j];

	if (ret != -1) return DP[i][j];

	for (int k = i; k < j; k++) {

		int temp = solve(i, k) + solve(k + 1, j) + a[i][0] * a[k][1] * a[j][1];
		if (ret == -1 || ret > temp) {

			ret = temp;
		}


	}

	return ret;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	memset(DP, -1, sizeof(DP));

	for (int i = 1; i <= n; i++) {

		cin >> a[i][0] >> a[i][1];

	}

	system("pause");
	cout << solve(1, n);

}