#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int DP[1000][3];
int N;


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	///////// 1. 입력
	cin >> N;

	int first, second, third;
	for (int i = 0; i < N; i++) {

		cin >> DP[i][0] >> DP[i][1] >> DP[i][2];
	}

	//3. dp 채우기

	for (int i = 1; i < N; i++) {

		DP[i][0] += min(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] += min(DP[i - 1][0], DP[i - 1][2]);
		DP[i][2] += min(DP[i - 1][1], DP[i - 1][0]);

	}

	cout << min(DP[N-1][0], min(DP[N-1][1], DP[N-1][2]));


	//system("pause");
	return 0;
}