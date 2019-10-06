#include <iostream>
#include <string>
#define SIZE (1<<21)
#define MAX(a,b) (a > b ? a : b)
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, a, k, size, left, right;
	cin >> k;
	size = 1 << (k + 1);
	int tree[SIZE] = { 0 }, path[SIZE] = { 0 }, sum[SIZE] = { 0 };
	for (i = 2; i < size; i++) {
		cin >> a;
		tree[i] = a;
	}

	for (i = 1 << k; --i > 0; ) {
		left = i << 1; right = left + 1;
		path[i] = MAX(path[left] + tree[left], path[right] + tree[right]);
		sum[i] = sum[left] + sum[right] + (path[i] - path[left]) + (path[i] - path[right]);
	}
	cout << sum[1];
	return 0;
}