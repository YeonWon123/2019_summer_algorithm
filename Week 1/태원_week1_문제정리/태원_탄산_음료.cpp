#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int d = 0;
	int r = 0;
	int f = 0;
	int e = 0;
	cin >> a >> b >> c;
	d = (a + b) / c;
	r = (a + b) % c;
	f += d;
	d = d + r;
	while (d >= c)
	{
		r = d % c;
		d = d / c;
		f += d;
		d = d + r;
	}
	cout << f;
	return 0;
}
