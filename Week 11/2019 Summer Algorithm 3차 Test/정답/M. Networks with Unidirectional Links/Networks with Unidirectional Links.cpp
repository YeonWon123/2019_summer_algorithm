// https://blog.myungwoo.kr/35

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1004

int T, N, M, ans;
int used[MAXN], match[MAXN], dist[MAXN];
vector <int> con[MAXN];
queue <int> que;

void bfs()
{
	int i, k, m, q;
	for (i = 1; i <= N; i++) dist[i] = 1e9;
	for (i = 1; i <= N; i++) if (!used[i]) dist[i] = 0, que.push(i);
	while (!que.empty()) {
		q = que.front(), que.pop();
		for (i = con[q].size(); i--;) {
			k = con[q][i];
			m = match[k];
			if (m && dist[m] == 1e9) dist[m] = dist[q] + 1, que.push(m);
		}
	}
}

bool dfs(int n)
{
	int i, k, m;
	for (i = con[n].size(); i--;) {
		k = con[n][i];
		m = match[k];
		if (!m || dist[m] == dist[n] + 1 && dfs(m)) {
			used[n] = 1, match[k] = n;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j, k;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; i++) used[i] = match[i] = 0, con[i].clear();
		while (M--) {
			scanf("%d%d", &i, &j); ++i, ++j;
			con[i].push_back(j);
		}
		for (ans = 0;;) {
			bfs();
			int flow = 0;
			for (i = 1; i <= N; i++) if (!used[i] && dfs(i)) flow++;
			ans += flow;
			if (!flow) break;
		}
		printf("%d\n", ans);
	}
}