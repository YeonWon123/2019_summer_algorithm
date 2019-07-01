#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, R;
vector<int> arr;

void print_array() {
	for (int i = 0; i < R; ++i) {
		printf("%d ", arr[i]);
	}
	puts("");
}

int main(void)
{
	scanf("%d%d", &N, &R);
	for (int i = 1; i <= N; ++i) {
		arr.push_back(i);
	}

	do {
		print_array();
		reverse(arr.begin() + R, arr.end());
	} while (next_permutation(arr.begin(), arr.end()));
}