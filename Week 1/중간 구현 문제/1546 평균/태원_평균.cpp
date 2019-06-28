#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int b[1000];
	double value = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];

	}
	int max = b[0];
	for (int j = 1; j < n; j++)
	{
		if (max < b[j])
			max = b[j];
	}
	for (int k = 0; k < n; k++) {
		value += (((double)b[k] / max) * 100);
	}
	cout << (value / n);
	return 0;
}
