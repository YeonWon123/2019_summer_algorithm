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

const int N = 55;
const long long inf = 1e18;

vector<pair<int, int>> edge[5][N];
int n[5], pos[5], a[5][N], air[5];
int p;
long long dp[N * N * N][1 << 3];

void decode(int mask) {
	for (int i = p - 1; i >= 0; i--) {
		pos[i] = mask % n[i];
		mask /= n[i];
	}
}

int encode() {
	int ret = 0;
	for (int i = 0; i < p; i++) {
		ret = ret * n[i] + pos[i];
	}
	return ret;
}

int main() {
	scanf("%d", &p);
	for (int it = 0; it < p; it++) {
		int m;
		scanf("%d %d", n + it, &m);
		for (int i = 0; i < n[it]; i++) scanf("%d", &a[it][i]);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			edge[it][u].emplace_back(v, w);
		}
		scanf("%d", air + it);
		air[it]--;
		pos[it] = air[it];
	}
	int goal = encode();
	for (int i = 0; i < N * N * N; i++) {
		for (int j = 0; j < (1 << p); j++) {
			dp[i][j] = inf;
		}
	}
	priority_queue<tuple<long long, int, int>> pq;
	dp[0][0] = 0;
	pq.emplace(0, 0, 0);
	while (!pq.empty()) {
		long long cost; int now, mask;
		tie(cost, now, mask) = pq.top(); pq.pop();
		cost = -cost;
		if (cost != dp[now][mask]) continue;
		if (now == goal && mask == 0) {
			cout << cost << endl;
			return 0;
		}
		decode(now);
		//printf("%d: ", mask); for (int i = 0; i < p; i++) printf("%d ", pos[i]); printf("\n");
		bool expand = 0;
		for (int it = 0; it < p; it++) {
			if ((mask & (1 << it)) == 0) {
				for (auto i : edge[it][pos[it]]) {
					int ori = pos[it];
					pos[it] = i.first;
					int to_now = encode();
					int to_mask = (mask | (1 << it));
					long long ncos = cost + i.second;
					if (dp[to_now][to_mask] > ncos) {
						dp[to_now][to_mask] = ncos;
						pq.emplace(-dp[to_now][to_mask], to_now, to_mask);
					}
					pos[it] = ori;
				}
				int to_now = now;
				int to_mask = (mask | (1 << it));
				long long ncos = cost + a[it][pos[it]];
				if (dp[to_now][to_mask] > ncos) {
					dp[to_now][to_mask] = ncos;
					pq.emplace(-dp[to_now][to_mask], to_now, to_mask);
				}

				expand = 1;
				break;
			}
		}
		if (!expand) {
			int to_now = now;
			int to_mask = 0;
			long long ncos = cost;
			if (dp[to_now][to_mask] > ncos) {
				dp[to_now][to_mask] = ncos;
				pq.emplace(-dp[to_now][to_mask], to_now, to_mask);
			}
		}
	}
	assert(0);
	return 0;
}