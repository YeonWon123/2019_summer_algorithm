#include <iostream>
using namespace std;

// 전역변수
int map[129][129];
int blue = 0;
int white = 0;

// 색종이 분석
int cur(int y, int x, int N) {
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (map[i][j] != map[y][x])
				return 0; // 하얀색 색종이와 파란색 색종이가 섞여 있음
		}
	}
	if (map[y][x] == 0) return 1; // 하얀색 색종이
	if (map[y][x] == 1) return 2; // 파란색 색종이
}

// 분할정복
void divide(int y, int x, int N) {
	int now = cur(y, x, N);
	if (now == 0) {
		// 나눠야 함
		divide(y, x, N / 2);
		divide(y, x + N / 2, N / 2);
		divide(y + N / 2, x, N / 2);
		divide(y + N / 2, x + N / 2, N / 2);
	}
	else if (now == 1) {
		white++;
	}
	else if (now == 2) {
		blue++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	divide(1, 1, N);
	cout << white << "\n" << blue;
	return 0;
}