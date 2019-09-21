// �ؼ� : https://red-pulse.tistory.com/169

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
	// a�ٿ� �ִ� ����
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &c);
		arr[n + i] = { c,1 };
	}
	// b�ٿ� �ִ� ����

	sort(arr, arr + n + m);
	// ������� -> ���� �������� ����

	for (int i = 1; i < n + m; i++)
		if (arr[i - 1].second != arr[i].second)
			// a�� b�� ���� ���� ���
		{
			if (mi == arr[i].first - arr[i - 1].first)
				num++;
			// ���� ������ �ּ� �Ÿ��� ������ �Ÿ��� ���� ���.
			if (mi > arr[i].first - arr[i - 1].first)
			{
				mi = arr[i].first - arr[i - 1].first;
				num = 1;
			}
			// ���ο� �ּ� �Ÿ��� �߰��� ���
		}
	printf("%d %d", mi + abs(a - b), num);
	// ����Ѵ�.
	return 0;
}