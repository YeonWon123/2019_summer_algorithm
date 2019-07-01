#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int d = 0;
	int f = 0;
	cin >> a >> b >> c;
		d = (a + b) / c;
		f += d;
	while (d >= c) {
		d = d / c;
		f += d;
	}
	cout << f;
	return 0;
}
