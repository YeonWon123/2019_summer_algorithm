#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
using namespace std;

string s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int cnt = 0;
	cin >> n;
	while (n) {
		if (n == 1000) {
			cnt = 144;
			break;
		}
		if (n < 100) {
			cnt++;
			n--;
		}
		else {
			s = to_string(n);
				int value1 = s[0] - '0';
				int value2 = s[1] - '0';
				int value3 = s[2] - '0';
				if ((value1 - value2) == (value2 - value3))
					cnt++;
				n--;
		}

	}
	cout << cnt;
	return 0;
}