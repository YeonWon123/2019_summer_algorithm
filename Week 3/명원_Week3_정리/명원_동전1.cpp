#include<iostream>
using namespace std;

int n, k;
int coin[101];
int dp[10001] = { 0 };





int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	//1. 입력
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	//2. 초기화

	dp[0] = 1;   // 가치가 0일 때는 오직 1가지만 가능

	//3. dp를 채우자

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= k; j++) {


			if (j >= coin[i]) {

				dp[j] += dp[j - coin[i]];
			}

		}
	}



	cout << dp[k];



	system("pause");
	return 0;
}