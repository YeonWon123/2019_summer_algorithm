#include<iostream>
using namespace std;

int N;
int dp[1000000];


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	cin >> N;

	// dp �ʱ�ȭ

	dp[0] = 1;  dp[1] = 2;

	//dp ä���

	for (int i = 2; i < N; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;  // ���� N�� �鸸 ��°�� int��  longlong �� ������
		                                          // ���� ����.  ���� ���� ���� ����������.

	}

	
	cout << dp[N - 1];


	//system("pause");
	return 0;
}