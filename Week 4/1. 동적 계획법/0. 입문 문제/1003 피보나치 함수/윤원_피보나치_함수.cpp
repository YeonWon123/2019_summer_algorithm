#include <iostream>
using namespace std;

pair<int, int> arr[41];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 배열 초기화
	arr[0].first = 1;
	arr[0].second = 0;
	arr[1].first = 0;
	arr[1].second = 1;

	// 점화식
	// arr[x].first = arr[x-1].first + arr[x-2].first
	// arr[x].second = arr[x-1].second + arr[x-2].second
	for (int i = 2; i <= 40; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}

	int testcase, temp;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> temp;
		cout << arr[temp].first << " " << arr[temp].second << "\n";
	}
}