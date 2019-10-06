#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> arr[10000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i].first = abs(input);

		if (input > 0)
			arr[i].second = 1;
		else if (input < 0)
			arr[i].second = -1;
		else
			arr[i].second = 0;
	}

	sort(arr, arr + n);

	// �ڿ������� 3���� ���ڸ� ��
	// �� �� ���� ũ�� ������ ���� ��ȯ��
	int num1, num2, num3;
	num1 = arr[n - 1].first * arr[n - 1].second;
	num2 = arr[n - 2].first * arr[n - 2].second;
	num3 = arr[n - 3].first * arr[n - 3].second;

	int result[4];
	result[0] = num1 * num2;
	result[1] = num1 * num3;
	result[2] = num2 * num3;
	result[3] = num1 * num2 * num3;
	sort(result, result + 4);
	cout << result[3];
	return 0;
}