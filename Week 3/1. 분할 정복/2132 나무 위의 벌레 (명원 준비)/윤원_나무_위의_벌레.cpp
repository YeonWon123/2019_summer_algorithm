#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct M {
	int loc, p; // loc = ��ġ, p : ����ġ
} M;

typedef struct item {
	int from, to;
} item;

vector <int> con[10001];
M dp[3][10001]; // dp[2][x] = �� �������� ���� ��..
queue<item> Q;
int arr[10001];
char visit[10001];

// ������ȹ���� ����� dfs
int dfs1(int cur, int parent) {
	int next, ret;
	dp[0][cur].p = arr[cur];
	for (int i = 0; i < con[cur].size(); i++) {
		next = con[cur][i];
		if (next == parent) continue;

		ret = arr[cur] + dfs1(next, cur);
		if (ret > dp[0][cur].p)
		{
			dp[1][cur] = dp[0][cur];
			dp[0][cur].loc = next;
			dp[0][cur].p = ret;
		}
		else if (ret > dp[1][cur].p) {
			dp[1][cur].loc = next;
			dp[1][cur].p = ret;
		}
	}
	return dp[0][cur].p;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b, cur, next, tt, llo, mmx = -1;
	item I, C;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}

	// 1�������� dfs Ž�� ����
	dfs1(1, -1);

	// bfs�� �־�� �� ���� : parent, cur, cost
	I.from = -1; I.to = 1; visit[1] = 1; Q.push(I);
	while (!Q.empty()) {
		C = Q.front(); Q.pop();
		// ���� ��ġ : C.to
		cur = C.to;
		if (C.from != -1) {
			// dp[0][C.from]�� ������
			if (dp[0][C.from].loc != cur)
				tt = dp[0][C.from].p + arr[cur];
			else
				tt = dp[1][C.from].p + arr[cur];
			if (tt > dp[0][cur].p) {
				dp[1][cur] = dp[0][cur];
				dp[0][cur].loc = C.from;
				dp[0][cur].p = tt;
			}
			else if (tt > dp[1][C.to].p) {
				dp[1][cur].loc = C.from;
				dp[1][cur].p = tt;
			}
		}
		for (int i = 0; i < con[cur].size(); i++) {
			next = con[cur][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				I.from = cur;
				I.to = next;
				Q.push(I);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (mmx < dp[i][j].p) {
				mmx = dp[i][j].p;
				llo = j;
			}
		}
	}
	cout << mmx << " " << llo;
	return 0;
}