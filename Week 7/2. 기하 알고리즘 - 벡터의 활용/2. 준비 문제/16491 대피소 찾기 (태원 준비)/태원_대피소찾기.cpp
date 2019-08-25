//https://jason9319.tistory.com/358 참고
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
pair <int, int> robot[11];
pair <int, int> shalter[11];
int inter[11][11][11][11];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}

int isIntersect(pair<pair <int, int> , pair <int, int>> x, pair<pair <int, int>, pair <int, int>> y) {
	pair<int, int> a = x.first;
	pair<int, int> b = x.second;
	pair<int, int> c = y.first;
	pair<int, int> d = y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

void SearchShalter(int* brute)
{
		do
		{
			bool temp = false;
			for (int i = 1; i <= n; i++)
			{
				if (temp == true)
					break;
				for (int j = i+1; j <= n; j++)
				{
					if (inter[i][j][brute[i - 1]][brute[j - 1]])
					{
						temp = true;
						break;
					}
				}

			}

			if (!temp) // 정해진 모든 경우의 수 선분들이 겹치지 않았으면 false
			{
				for (int i = 0; i < n; i++)
					cout << brute[i] << "\n"; // 출력 
				break;
			}
		} while (next_permutation(brute, brute + n)); // 만나는 값이 위에서 나왔으면 배열 리프레시
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int brute[11];

	for (int i = 0; i < n; i++)
	{
		brute[i] = i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> robot[i].first >> robot[i].second;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> shalter[i].first >> shalter[i].second;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue; // i == j면 같은선분 
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					pair <pair <int, int>, pair <int, int>> saveRobot1 , saveRobot2;
					if (k == l) continue;
					saveRobot1.first = robot[i];
					saveRobot1.second = shalter[k];
					saveRobot2.first = robot[j];
					saveRobot2.second = shalter[l];
						inter[i][j][k][l] = isIntersect(saveRobot1, saveRobot2);
				}
			}
		}
	}
	SearchShalter(brute);

	return 0;
}