#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <cstring>
using namespace std;
int min_v(int a, int b) { return a < b ? a : b; }
int max_v(int a, int b) { return a > b ? a : b; }
const int MAX_V = 20001;
vector<vector<int>> adj;
stack<int> stk;
int sccId[MAX_V], discovered[MAX_V], sccCount, discCount;
int scc(int u) {
	stk.push(u);
	int ret = discovered[u] = discCount;
	discCount++;
	for (int& v : adj[u]) {
		if (discovered[v] == -1)
			ret = min_v(ret, scc(v));
		else if (sccId[v] == -1)
			ret = min_v(ret, discovered[v]);
	}

	if (ret == discovered[u]) {
		while (1) {
			int t = stk.top();
			stk.pop();
			sccId[t] = sccCount;
			if (t == u) break;
		}
		sccCount++;
	}
	return ret;
}

int main() {
	int N, M, T, s1, s2, i, ans, ind[MAX_V], outd[MAX_V], inc, outc;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		while (!stk.empty()) stk.pop();
		adj.clear(); adj.resize(N);
		ans = sccCount = discCount = 0;
		memset(sccId, -1, sizeof sccId);
		memset(discovered, -1, sizeof discovered);
		while (M--) {
			scanf("%d%d", &s1, &s2);
			s1--, s2--;
			adj[s1].push_back(s2);
		}

		for (i = 0; i < N; i++)
			if (discovered[i] == -1) scc(i);

		memset(ind, 0, sizeof ind);
		memset(outd, 0, sizeof outd);
		for (i = 0; i < N; i++) {
			for (int& v : adj[i])
				if (sccId[i] != sccId[v]) {
					outd[sccId[i]]++;
					ind[sccId[v]]++;
				}
		}
		inc = outc = 0;
		for (i = 0; i < sccCount; i++) {
			if (!ind[i]) inc++;
			if (!outd[i]) outc++;
		}
		printf("%d\n", sccCount == 1 ? 0 : max_v(inc, outc));
	}

	return 0;
}