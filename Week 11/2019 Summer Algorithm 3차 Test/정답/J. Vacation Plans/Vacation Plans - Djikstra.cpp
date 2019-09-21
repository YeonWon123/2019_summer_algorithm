// Djikstra를 이용한 풀이
// 출처: https://blog.myungwoo.kr/121?category=629879 [PS 이야기]
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

//#include <bits/stdc++.h>
//using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;

int P, N[3], T[3];
lld D[51][51][51][3];
vector <int> con[3][51], conv[3][51];

int main()
{
	scanf("%d", &P);
	for (int i = 0; i < P; i++) {
		int m; scanf("%d%d", N + i, &m);
		for (int j = 1; j <= N[i]; j++) {
			int v; scanf("%d", &v);
			con[i][j].pb(j); conv[i][j].pb(v);
		}
		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			con[i][a].pb(b); conv[i][a].pb(c);
		}
		scanf("%d", T + i);
	}
	for (int i = P; i < 3; i++) {
		con[i][1].pb(1); conv[i][1].pb(0);
		N[i] = T[i] = 1;
	}
	for (int i = 1; i <= N[0]; i++) for (int j = 1; j <= N[1]; j++) for (int k = 1; k <= N[2]; k++) for (int l = 0; l < 3; l++) D[i][j][k][l] = 1e18;
	struct Z {
		int a, b, c, d; lld v;
		bool operator < (const Z& ot)const { return v > ot.v; }
	};
	priority_queue <Z> que;
	D[1][1][1][0] = 0; que.push({ 1, 1, 1, 0, 0 });
	while (!que.empty()) {
		Z q = que.top(); que.pop();
		int t = q.d;
		vector <int> a = { q.a, q.b, q.c };
		for (int i = sz(con[t][a[t]]); i--;) {
			auto b = a;
			b[t] = con[t][a[t]][i]; int v = conv[t][a[t]][i];
			lld& d = D[b[0]][b[1]][b[2]][(q.d + 1) % 3];
			if (d > q.v + v)
				d = q.v + v, que.push({ b[0], b[1], b[2], (q.d + 1) % 3, q.v + v });
		}
	}
	printf("%lld\n", D[T[0]][T[1]][T[2]][0]);
}