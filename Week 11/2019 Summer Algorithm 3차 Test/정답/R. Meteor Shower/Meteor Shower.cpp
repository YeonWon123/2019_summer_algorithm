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

#define MAXN 100005
#define MAXM 1000006
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;

int N;
bool vis[MAXN];

int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
	lld k = (lld)(bx - ax) * (cy - ay) - (lld)(cx - ax) * (by - ay);
	if (k > 0) return 1;
	if (k) return -1;
	return 0;
}

struct Z {
	int x, y;

	bool operator < (const Z& ot)const {
		int k = ccw(0, 0, x, y, ot.x, ot.y);
		if (k) return k > 0;
		return 0;
	}
	bool operator == (const Z& ot)const {
		return ccw(0, 0, x, y, ot.x, ot.y) == 0;
	}
} O;
int ccw(const Z& a, const Z& b, const Z& c) { return ccw(a.x, a.y, b.x, b.y, c.x, c.y); }
vector <Z> down[MAXN];
vector <int> downi[MAXN];

int now;
struct DOWN {
	int n;

	bool operator < (const DOWN& ot)const {
		int t1 = upper_bound(all(downi[n]), now) - downi[n].begin();
		int t2 = upper_bound(all(downi[ot.n]), now) - downi[ot.n].begin();
		Z a = down[n][t1 - 1], b = down[n][t1], p = down[ot.n][t2 - 1], q = down[ot.n][t2];
		if (downi[n][t1 - 1] <= downi[ot.n][t2 - 1])
			return ccw(a, b, p) < 0;
		else
			return ccw(p, q, a) > 0;
	}
};
vector <int> in[MAXM], out[MAXM];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int n; scanf("%d", &n);
		vector <Z> arr;
		for (int j = 0; j < n; j++) {
			int x, y; scanf("%d%d", &x, &y);
			arr.pb({ x, y });
		}
		int p = 0, q = 0;
		for (int j = 0; j < n; j++) {
			if (ccw(O, arr[p], arr[j]) > 0 || ccw(O, arr[p], arr[j]) == 0 && arr[p].y > arr[j].y)
				p = j;
			if (ccw(O, arr[q], arr[j]) < 0 || ccw(O, arr[q], arr[j]) == 0 && arr[q].y > arr[j].y)
				q = j;
		}
		for (int j = p;; j = (j + 1) % n) {
			down[i].pb(arr[j]);
			if (j == q) break;
		}
		reverse(all(down[i]));
	}
	vector <Z> arr;
	for (int i = 1; i <= N; i++) for (Z& t : down[i]) arr.pb(t);
	sort(all(arr)); arr.erase(unique(all(arr)), arr.end());
	for (int i = 1; i <= N; i++) {
		for (Z& t : down[i])
			downi[i].pb(lower_bound(all(arr), t) - arr.begin() + 1);
	}
	for (int i = 1; i <= N; i++) {
		in[downi[i][0]].pb(i);
		out[downi[i].back()].pb(i);
	}
	set <DOWN> S;
	for (int i = 1; i < sz(arr); i++) {
		// erase
		for (int j : out[i]) S.erase({ j });
		now = i;
		// inesrt
		for (int j : in[i]) S.insert({ j });
		if (!S.empty()) vis[S.begin()->n] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) if (!vis[i]) ans++;
	printf("%d\n", ans);
}


// 출처: https://blog.myungwoo.kr/111 [PS 이야기]