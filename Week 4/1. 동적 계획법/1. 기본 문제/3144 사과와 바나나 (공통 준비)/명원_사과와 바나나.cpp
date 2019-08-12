#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct tree {

	char type;
	int count;

};

tree arr[1501][1501];

int r, c, sum_a[1501][1501] = {}, sum_b[1501][1501] = {}, dp[1501][1501];



int solve(const int &i, const int &j) {

	int &ret = dp[i][j];

	if (ret != -1)
		return ret;

	if (i == 1 && j == 1)
		return 0;

	if (i > 1)
		ret = max(ret, solve(i - 1, j) + sum_a[i][j - 1]);

	if (j > 1)
		ret = max(ret, solve(i, j - 1) + sum_b[i - 1][j]);


	if (i > 1 && j > 1)
		ret = max(ret, solve(i - 1, j - 1) + sum_a[i][j - 1] + sum_b[i - 1][j]);

	return ret;

}






int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	fill_n(&dp[0][0], 1501 * 1501, -1);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {

			string buf;
			cin >> buf;


			arr[i][j].type = buf[0];
			arr[i][j].count = stoi(buf.substr(1, buf.length() - 1));  // string->int

			sum_a[i][j] = sum_a[i][j - 1] + (buf[0] == 'A' ? arr[i][j].count : 0);
			sum_b[i][j] = sum_b[i - 1][j] + (buf[0] == 'B' ? arr[i][j].count : 0);
		}
	}


	cout << solve(r, c) << "\n";




	//system("pause");
	return 0;

}