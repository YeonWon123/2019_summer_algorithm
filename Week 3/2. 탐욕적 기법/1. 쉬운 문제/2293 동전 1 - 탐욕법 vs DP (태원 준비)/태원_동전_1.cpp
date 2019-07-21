// µ¿Àü 1

#include <iostream>
using namespace std;

int a[101];
int b[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	b[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= k; j++)
		{
			if (a[i] <= k)
				b[j] += b[j - a[i]];
		}
	}
	cout << b[k] << "\n";
	return 0;
}


