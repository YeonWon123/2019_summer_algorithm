#include <iostream>
using namespace std;

int arr[1000000] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		long long answer = 0;
		int i; long long max = -1;
		for (i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int j = i-1; j >= 0; j--) {
			if (max < arr[j]) max = arr[j];
			answer += max - arr[j];
		}

		cout << answer << "\n";
	}
}