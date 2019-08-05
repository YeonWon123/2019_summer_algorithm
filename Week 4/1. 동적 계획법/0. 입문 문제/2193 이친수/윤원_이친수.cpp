#include <iostream>
using namespace std;

long long arr[100]; // 자료형에 주의

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	arr[1] = 1;
	arr[2] = 1;

	int N;
	cin >> N;
	for (int i = 3; i <= N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[N];
	return 0;
}