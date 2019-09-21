// Bellmanford 풀이
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

#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;

int P, N[3], T[3];
lld D[3][51];

struct EDGE {
	int a, b, c;
};
vector <EDGE> E[3];

int main()
{
	scanf("%d", &P);
	for (int i = 0; i < P; i++) {
		int m; scanf("%d%d", N + i, &m);
		for (int j = 1; j <= N[i]; j++) {
			int v; scanf("%d", &v);
			E[i].pb({ j, j, v });
		}
		while (m--) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			E[i].pb({ a, b, c });
		}
		scanf("%d", T + i);
	}
	for (int i = P; i < 3; i++) {
		E[i].pb({ 1, 1, 0 });
		N[i] = T[i] = 1;
	}
	for (int i = 0; i < 3; i++) for (int j = 2; j <= N[i]; j++) D[i][j] = 1e18;
	const int MAX_MOVE = N[0] * N[1] * N[2];
	lld ans = 1e18;
	for (int i = 0; i < MAX_MOVE; i++) {
		lld sum = 0;
		for (int j = 0; j < 3; j++) sum += D[j][T[j]];
		if (ans > sum) ans = sum;
		for (int j = 0; j < 3; j++) {
			vector <lld> t(N[j] + 1, 1e18);
			for (const auto& e : E[j])
				t[e.b] = min(t[e.b], D[j][e.a] + e.c);
			for (int k = 1; k <= N[j]; k++) D[j][k] = t[k];
		}
	}
	printf("%lld\n", ans);
}