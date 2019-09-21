#define _CRT_SECURE_NO_WARNINGS

#include <cctype> 
#include <cerrno> 
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale> 
#include <cmath> 
#include <csetjmp>
#include <csignal>
#include <cstdarg> 
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <ctime>
#include <ccomplex>
#include <cfenv> 
#include <cinttypes>
#include <cstdalign> 
#include <cstdbool>
#include <cstdint> 
#include <ctgmath>
#include <cwchar> 
#include <cwctype>
#include <algorithm> 
#include <bitset>
#include <complex>
#include <deque> 
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip> 
#include <ios>
#include <iosfwd>
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale>
#include <map>
#include <memory>
#include <new> 
#include <numeric>
#include <ostream> 
#include <queue> 
#include <set> 
#include <sstream>
#include <stack> 
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector>
#include <array>
#include <atomic> 
#include <chrono> 
#include <condition_variable> 
#include <forward_list> 
#include <future> 
#include <initializer_list> 
#include <mutex> 
#include <random> 
#include <ratio> 
#include <regex> 
#include <scoped_allocator>
#include <system_error>
#include <thread> 
#include <tuple>
#include <typeindex> 
#include <type_traits> 
#include <unordered_map> 
#include <unordered_set>
#include <cassert>
using namespace std;

const int N = 105, M = 505, INF = 1e9;
pair<int, pair<int, int> > edges[M];

struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
	int N;
	vector<vector<Edge> > G;
	vector<Edge*> dad;
	vector<int> Q;

	Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

	void AddEdge(int from, int to, int cap, int revcap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, revcap, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int s, int t) {
		fill(dad.begin(), dad.end(), (Edge*)NULL);
		dad[s] = &G[0][0] - 1;

		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail) {
			int x = Q[head++];
			for (int i = 0; i < G[x].size(); i++) {
				Edge& e = G[x][i];
				if (!dad[e.to] && e.cap - e.flow > 0) {
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}
		if (!dad[t]) return 0;

		long long totflow = 0;
		for (int i = 0; i < G[t].size(); i++) {
			Edge* start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for (Edge* e = start; amt && e != dad[s]; e = dad[e->from]) {
				if (!e) { amt = 0; break; }
				amt = min(amt, e->cap - e->flow);
			}
			if (amt == 0) continue;
			for (Edge* e = start; amt && e != dad[s]; e = dad[e->from]) {
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		return totflow;
	}

	long long GetMaxFlow(int s, int t) {
		long long totflow = 0;
		while (long long flow = BlockingFlow(s, t))
			totflow += flow;
		return totflow;
	}
};


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		edges[i] = { w, {u, v} };
	}
	sort(edges, edges + m);
	Dinic mf(n);
	long long ans = 0;
	for (int i = 0, j = 0; i < m; ++i) {
		while (j < i && edges[j].first < edges[i].first) {
			mf.AddEdge(edges[j].second.first, edges[j].second.second, 1, 1);
			++j;
		}
		for (int j = 0; j < n; ++j) {
			for (auto& it : mf.G[j])
				it.flow = 0;
		}
		ans += mf.GetMaxFlow(edges[i].second.first, edges[i].second.second);
	}
	cout << ans << endl;
	return 0;
}