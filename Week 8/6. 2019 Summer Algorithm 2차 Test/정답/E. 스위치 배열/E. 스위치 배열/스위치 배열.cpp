#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		char digit = '0';
		long long ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != digit) {
				ans += 1LL << (s.size() - i - 1);
			}
			digit = '0' + (digit != s[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}