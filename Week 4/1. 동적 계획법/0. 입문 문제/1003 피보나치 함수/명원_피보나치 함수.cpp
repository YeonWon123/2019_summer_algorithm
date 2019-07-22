#include<iostream>
using namespace std;

int zero = 0;
int one = 0;
int dp[2][40];


void fibonacci(int N) {

	// dp �ʱ�ȭ  
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;


	for (int i = 2; i <= N; i++) {

		dp[0][i] = dp[0][i - 1] + dp[0][i - 2]; // 0�� ����
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2]; // 1�� ����

	}
	
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	int T = 0;  int N = 0;

	

 //  �Ǻ���ġ ����

	cin >> T;
	for (int i = 0; i < T; i++) {


		cin >> N;
		fibonacci(N);

		cout << dp[0][N] << " " << dp[1][N] << "\n";
	}



	//system("pause");
	return 0;
}