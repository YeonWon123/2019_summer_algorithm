#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int b[1000];
	int max = 0;
	double value = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];

	}
	for (int j = 0; j < n; j++)
	{
		if (b[j] < b[j + 1])
			max = b[j + 1];
	}
	for (int k = 0; k < a; k++) {
		value += ((b[k] / max) * 100);
	}
	cout << (value / n);
	return 0;
}
