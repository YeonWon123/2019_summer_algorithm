#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cnt += a[i];
		if (cnt < i * (i + 1) / 2)
		{
			cout << -1 << "\n";
			return 0;
		}
	}
	if (cnt == n * (n - 1) / 2)
		cout << 1 << "\n";
	else
		cout << -1 << "\n";
	return 0;

}