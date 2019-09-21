// https://www.weeklyps.com/entry/BOJ-8901-%ED%99%94%ED%95%99-%EC%A0%9C%ED%92%88

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

void solve() {
	int a, b, c, ab, bc, ca;
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &ab, &bc, &ca);

	int ans = 0;
	for (int i = 0; i <= min(a, b); i++)
		for (int j = 0; j <= min(b - i, c); j++) {
			int k = min(a - i, c - j);
			ans = max(ans, ab * i + bc * j + ca * k);
		}
	printf("%d\n", ans);
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}