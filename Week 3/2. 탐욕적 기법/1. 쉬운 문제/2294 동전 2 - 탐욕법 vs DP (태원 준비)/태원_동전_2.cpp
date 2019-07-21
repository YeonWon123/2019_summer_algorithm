#include <iostream>
#include <algorithm>
using namespace std;

int n;
int k;
int a[101];
int b[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fill_n(b, 10001, 10001);
	b[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= k; j++)
		{
			b[j] = min(b[j], b[j - a[i]] + 1);
		}
	}
	if (b[k] == 10001)
	{
		cout << -1 << "\n";
	}
	else
	cout << b[k] << "\n";
	return 0;
	
}
