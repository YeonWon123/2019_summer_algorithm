#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
using namespace std;

class Line {
public:
	int left, right;
};

bool compare(Line a, Line b) {
	return a.right < b.right;
}

int main(void)
{
	int i, a, b, d, ans = -1, n;
	scanf("%d", &n);
	Line line[100001];
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		line[i].left = min(a, b);
		line[i].right = max(a, b);
	}
	scanf("%d", &d);

	sort(line, line + n, compare);

	priority_queue<int> pq;
	for (i = 0; i < n; i++) {
		pq.push(-line[i].left);
		while (!pq.empty() && -pq.top() < line[i].right - d)
			pq.pop();
		ans = max(ans, (int)pq.size());
	}
	printf("%d\n", ans);
}