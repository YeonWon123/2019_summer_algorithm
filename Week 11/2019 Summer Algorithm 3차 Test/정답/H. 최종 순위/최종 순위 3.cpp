// 2차원 배열을 이용하여 풀기
// https://justicehui.github.io/icpc/2019/08/31/BOJ3665/
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

// #include <bits/stdc++.h>
// using namespace std;

vector<int> v;
int g[555][555];

void solve() {
	memset(g, 0, sizeof g);
	int n; cin >> n; v.resize(n);
	for (auto& i : v) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			g[v[i]][v[j]] = 1;
		}
	}
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		swap(g[a][b], g[b][a]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (g[v[j]][v[i]]) swap(v[i], v[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (g[v[j]][v[i]]) {
				cout << "IMPOSSIBLE\n"; return;
			}
		}
	}
	for (auto i : v) cout << i << " "; cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
