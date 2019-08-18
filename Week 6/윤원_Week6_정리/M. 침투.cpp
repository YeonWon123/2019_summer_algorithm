#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int N, M; int findpath = 0;
int map[1000][1000];
string tap[1000];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


int isInRanGe(int x, int y) {
	return (0 <= x && x < M) && (0 <= y && y < N);
}

void dfs(int a, int b) {
	map[a][b] = 1;
	if (a == M - 1) {
		findpath = 1; return;
	}

	for (int i = 0; i < 4; i++) {
		int ax = a + dx[i]; int ay = b + dy[i];

		if (isInRanGe(ax, ay) && !map[ax][ay])
			dfs(ax, ay);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		cin >> tap[i];
		for (int j = 0; j < N; j++) {
			map[i][j] = tap[i][j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		if (findpath != 1 && !map[0][i])
       			dfs(0, i);
	}

	if (findpath == 1)  cout << "YES";
	else cout << "NO";
	return 0;
}
