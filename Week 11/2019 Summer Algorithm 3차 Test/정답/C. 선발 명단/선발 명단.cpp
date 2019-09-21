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

int bias = 12;
int f[33][33];
int d[33][33];
int c[33][33];
vector<int> g[33];
int s = 24, t = 25;

int inque[33];
int dist[33];
int par[33];

void init() {
	memset(f, 0, sizeof f);
	memset(d, 0, sizeof d);
	memset(c, 0, sizeof c);
	for (int i = 0; i < 33; i++) g[i].clear();
	memset(inque, 0, sizeof inque);
	memset(dist, 0x3f, sizeof dist);
	memset(par, -1, sizeof par);
}

int mcmf() {
	int ret = 0;
	while (1) {
		memset(inque, 0, sizeof inque);
		memset(dist, 0x3f, sizeof dist);
		memset(par, -1, sizeof par);

		queue<int> q;
		q.push(s); inque[s] = 1;
		dist[s] = 0;
		while (!q.empty()) {
			int now = q.front(); q.pop(); inque[now] = 0;
			for (auto nxt : g[now]) {
				if (c[now][nxt] - f[now][nxt] > 0 && dist[nxt] > dist[now] + d[now][nxt]) {
					dist[nxt] = dist[now] + d[now][nxt];
					par[nxt] = now;
					if (!inque[nxt]) {
						q.push(nxt); inque[nxt] = 1;
					}
				}
			}
		}
		if (par[t] == -1) break;
		for (int i = t; i != s; i = par[i]) {
			int a = par[i], b = i;
			f[a][b]++; f[b][a]--;
			ret += d[a][b];
		}
	}
	return -ret;
}

void solve() {
	init();
	for (int i = 1; i <= 11; i++) {
		for (int j = bias + 1; j <= bias + 11; j++) {
			cin >> d[i][j]; d[i][j] *= -1;
			if (!d[i][j]) continue;
			c[i][j] = 1;
			g[i].push_back(j); g[j].push_back(i);
			d[j][i] = -d[i][j];
		}
	}

	for (int i = 1; i <= 11; i++) {
		g[s].push_back(i); g[i].push_back(s);
		c[s][i] = 1;
	}
	for (int i = bias + 1; i <= bias + 11; i++) {
		g[i].push_back(t); g[t].push_back(i);
		c[i][t] = 1;
	}

	cout << mcmf() << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int asdf; cin >> asdf;
	while (asdf--) solve();
}

// ÇØ¼³ : https://justicehui.github.io/icpc/2019/04/11/BOJ3980/