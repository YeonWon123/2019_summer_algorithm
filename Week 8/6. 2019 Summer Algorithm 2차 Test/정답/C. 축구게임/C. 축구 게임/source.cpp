#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int* arr;
	arr = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cnt += arr[i];
		if (cnt < (i * (i + 1) / 2)) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", cnt == n * (n - 1) / 2 ? 1 : -1);
	return 0;
}