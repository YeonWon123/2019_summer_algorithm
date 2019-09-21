// 해설 : https://red-pulse.tistory.com/169

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAX 1000005
#define INF 987654321
#define MOD 1000000
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, m, a, b, c, mi = INF, num = 0;
pi arr[MAX];

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &a, &b);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c);
		arr[i] = { c,0 };
	}
	// a줄에 있는 점들
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &c);
		arr[n + i] = { c,1 };
	}
	// b줄에 있는 점들

	sort(arr, arr + n + m);
	// 페어정렬 -> 값을 기준으로 정렬

	for (int i = 1; i < n + m; i++)
		if (arr[i - 1].second != arr[i].second)
			// a줄 b줄 점이 만난 경우
		{
			if (mi == arr[i].first - arr[i - 1].first)
				num++;
			// 현재 까지의 최소 거리와 동일한 거리를 가진 경우.
			if (mi > arr[i].first - arr[i - 1].first)
			{
				mi = arr[i].first - arr[i - 1].first;
				num = 1;
			}
			// 새로운 최소 거리를 발견한 경우
		}
	printf("%d %d", mi + abs(a - b), num);
	// 출력한다.
	return 0;
}