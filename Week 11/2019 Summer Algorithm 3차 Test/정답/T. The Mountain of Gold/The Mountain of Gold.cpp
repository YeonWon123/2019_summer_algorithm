#define _CRT_SECURE_NO_WARMINGS

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> arr;

int T, N, M;
int D[1001];
bool V[1001], U[1001];
vector <arr> con, conr;

struct {
	int s, e, c;
} edge[2001];

void bfs(bool* vis, vector <arr>& cond)
{
	queue <int> que;
	que.push(1); vis[1] = 1;
	while (!que.empty()) {
		int q = que.front(); que.pop();
		for (int t : cond[q]) {
			if (!vis[t]) vis[t] = 1, que.push(t);
		}
	}
}

int main()
{
	int ts = 0, i, j;
	for (scanf("%d", &T); T--;) {
		printf("Case #%d: ", ++ts);
		scanf("%d%d", &N, &M);
		con.clear(), conr.clear();
		con.resize(N + 1, arr());
		conr.resize(N + 1, arr());
		for (i = 1; i <= M; i++) {
			scanf("%d%d%d", &edge[i].s, &edge[i].e, &edge[i].c);
			edge[i].s++; edge[i].e++;
			con[edge[i].s].push_back(edge[i].e);
			conr[edge[i].e].push_back(edge[i].s);
		}
		for (i = 1; i <= N; i++) V[i] = 0, U[i] = 0;
		bfs(V, con);
		bfs(U, conr);
		for (i = 1; i <= N; i++) V[i] &= U[i], D[i] = 2e9;
		D[1] = 0;
		for (i = 1; i <= N; i++) {
			bool sw = 0;
			for (j = 1; j <= M; j++) if (V[edge[j].s] && V[edge[j].e]) {
				if (D[edge[j].e] > D[edge[j].s] + edge[j].c)
					D[edge[j].e] = D[edge[j].s] + edge[j].c, sw = 1;
			}
			if (!sw) break;
		}
		puts(i > N ? "possible" : "not possible");
	}
}

// 출처: https://blog.myungwoo.kr/83 [PS 이야기]