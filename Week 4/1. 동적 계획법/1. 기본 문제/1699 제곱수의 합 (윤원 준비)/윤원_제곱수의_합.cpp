#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	// 1. d[1] = 1, d[2] = 2, d[3] = 3, d[4] = 4, ... �� �ϴ� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
	}

	// 2. d[i] = min(d[i], d[i-j*j] + 1) (��, j�� 2���� j*j <= i) ��ȭ�� ���
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];
	return 0;
}