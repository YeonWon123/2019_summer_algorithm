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
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const double pi = 3.1415926535;

int n; ll l;
vector<p> v, hull;

int ccw(p a, p b, p c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= b.x * a.y + c.x * b.y + a.x * c.y;
	if (res > 0) return 1;
	if (res) return -1;
	return 0;
}

double dist(p a, p b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

ll dot(p a, p b) { //백터 내적
	return a.x * b.x + a.y * b.y;
}

int main() {
	cin >> n >> l; v.resize(n);
	for (int i = 0; i < n; i++) scanf("%lld %lld", &v[i].x, &v[i].y);

	swap(v[0], *max_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), [&](p& a, p& b) {
		int cw = ccw(v[0], a, b);
		if (cw) return cw > 0;
		return dist(v[0], a) < dist(v[0], b);
		});

	for (auto i : v) {
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), i) <= 0) hull.pop_back();
		hull.push_back(i);
	}

	n = hull.size();
	double ans = 0;

	for (int i = 0; i < n; i++) {
		p prv = hull[(i + n - 1) % n], now = hull[i], nxt = hull[(i + 1) % n];
		double dist1 = dist(now, nxt);
		ans += dist1;
		double dist2 = dist(prv, now);

		ll inner = dot({ prv.x - now.x, prv.y - now.y }, { nxt.x - now.x, nxt.y - now.y }); //now->prv 벡터와 now->nxt 벡터의 내적
		double theta = acos((double)inner / dist1 / dist2); //사잇각 구하기
		theta = pi - theta; //180 - theta
		ans += l * theta; //호의 길이
	}

	printf("%.0lf", ans);
}