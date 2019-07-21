#include <iostream>
using namespace std;

int main()
{
	int n;
	int k;
	cin >> n >> k;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	int money = 0;
	for (int j = n - 1; j >= 0; j--)
	{
		while (k > money)
		{
			if (k >= money + a[j]) {
				money += a[j];
				cnt++;
			}
			else
				break;
		}
	}
	cout << cnt << "\n";
	return 0;
}