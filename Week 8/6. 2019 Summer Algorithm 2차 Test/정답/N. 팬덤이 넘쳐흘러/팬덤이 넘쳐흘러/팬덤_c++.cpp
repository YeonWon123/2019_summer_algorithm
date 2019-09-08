#include <stdio.h>
#include <climits>
#include <algorithm>

int main(void) {
	int n;
	scanf("%d", &n);

	int min_finish = INT_MAX / 2, max_start = 0;

	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		max_start = std::max(max_start, a);
		min_finish = std::min(min_finish, b);
	}

	printf("%d\n", std::max(0, max_start - min_finish));
}