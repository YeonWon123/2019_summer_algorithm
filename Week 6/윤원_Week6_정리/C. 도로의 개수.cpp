#include <iostream>
#include <vector>
using namespace std;

long long arr[101][101];

vector< pair< pair<int, int>, pair<int, int> > > save;
bool check(int a, int b, int c, int d);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int temp;
		if (a > c) {
			temp = a;
			a = c;
			c = temp;
		}

		if (b > d) {
			temp = b;
			b = d;
			d = temp;
		}
		//cout << a << b << c << d << endl;
		save.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
	}

	arr[0][0] = 1;

	// 1. 모서리부분 전부 하기
	for (int i = 1; i <= M; i++) {
		if (check(0, i - 1, 0, i)) {
			arr[0][i] = 0;
		}
		else
			arr[0][i] = arr[0][i-1];
	}

	for (int i = 1; i <= N; i++) {
		if (check(i - 1, 0, i, 0)) {
			arr[i][0] = 0;
		}
		else
			arr[i][0] = arr[i - 1][0];
	}

	// 2. 안으로 파고들어가기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)  {
			arr[i][j] = (check(i, j - 1, i, j) ? 0 : arr[i][j - 1]) + (check(i - 1, j, i, j) ? 0 : arr[i - 1][j]);
		}
	}

	cout << arr[N][M];
}

// 공사중인지 확인
bool check(int a, int b, int c, int d) {
	for (int i = 0; i < save.size(); i++) {
		if (save[i].first.first == a && save[i].first.second == b 
			&& save[i].second.first == c && save[i].second.second == d) {
			return 1;
		}
	}
	return 0;
}