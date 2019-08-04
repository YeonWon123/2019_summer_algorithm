#include<iostream>
using namespace std;

int N;
int dp[1000000];


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	cin >> N;

	// dp 초기화

	dp[0] = 1;  dp[1] = 2;

	//dp 채우기

	for (int i = 2; i < N; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;  // 만일 N이 백만 번째면 int형  longlong 도 범위를
		                                          // 벗어 난다.  따라서 나눈 값을 저장해주자.

	}

	
	cout << dp[N - 1];


	//system("pause");
	return 0;
}