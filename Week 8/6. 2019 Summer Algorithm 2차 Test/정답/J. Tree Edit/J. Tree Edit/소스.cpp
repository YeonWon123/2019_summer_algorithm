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

int T;
char buf[9999];

struct NODE {
	NODE(char c) : c(c), child(), size(1) {}
	char c; int size;
	vector <NODE*> child;
} *A, * B;

NODE* input(char* str)
{
	NODE* ret = new NODE(str[1]);
	int lvl = 0;
	for (int i = 2; str[i]; i++) {
		if (str[i] == '(') {
			lvl++;
			if (lvl == 1) {
				NODE* tmp = input(str + i);
				ret->size += tmp->size;
				ret->child.pb(tmp);
			}
		}
		else if (str[i] == ')') {
			lvl--;
		}
		if (lvl < 0) break;
	}
	return ret;
}

int dy(NODE* a, NODE* b)
{
	int ret = (a->c != b->c);
	int n = sz(a->child), m = sz(b->child);
	vector <vector<int>> dp(n + 1, vector<int>(m + 1, 2e9));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
		if (i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a->child[i]->size);
		if (j < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + b->child[j]->size);
		if (i < n && j < m)
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dy(a->child[i], b->child[j]));
	}
	ret += dp[n][m];
	return ret;
}

int main()
{
	for (scanf("%d", &T); T--;) {
		scanf("%s", buf);
		A = input(buf);
		scanf("%s", buf);
		B = input(buf);
		printf("%d\n", dy(A, B));
	}
}