#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	long long a;
	cin >> a;

	// 점화식 : n + (n+1)*(n+1)*(n+2)/2 범위 안에 속할 경우 리턴
	int n = 1;
	while (1) {
		long long temp = n;
		for (int i = 0; i <= n; i++) {
			temp += pow(2, i) * (n+1);
		}

		if (temp >= a) {
			cout << n;
			return 0;
		}
		n++;
	}
}