#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// ����
	sort(arr, arr + N);

	// ������ ���ϱ�, ������ ���ϱ�
	int answer = arr[0];
	for (int i = 1; i < N; i++) {
		arr[i] += arr[i - 1];
		answer += arr[i];
	}

	cout << answer;
	return 0;
}