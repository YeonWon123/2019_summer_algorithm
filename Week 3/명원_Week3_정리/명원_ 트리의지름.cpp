#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector < vector <pair<int, int>>> Graph;
int n, d[10010];
bool check[10010];

int dfs(int x) {
	check[x] = true;
	int ret = x;
	d[x] = 0;
	for (int i = 0; i < Graph[x].size(); i++) {
		int next = Graph[x][i].first;
		int cost = Graph[x][i].second;

		if (check[next]) continue;

		int ret_next = dfs(next);

		if (d[x] < d[next] + cost) {
			d[x] = d[next] + cost;
			ret = ret_next;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	Graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		Graph[u].push_back({ v, w });
		Graph[v].push_back({ u, w });
	}
	int s = dfs(0);
	memset(check, 0, sizeof(check));
	memset(d, 0, sizeof(d));
	int e = dfs(s);
	cout << d[s];


	//system("pause");
	return 0;
}