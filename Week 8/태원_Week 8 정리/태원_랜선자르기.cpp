#include <iostream>
#include <limits.h>
using namespace std;
long long line[10001];
long long k,n;
long long maxValue = 0;
void Cutline()
{
	long long left = 0;
	long long right = LLONG_MAX;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long result = 0;

		for (int i = 0; i < k; i++)
		{
			result += line[i] / mid;
		}
		if (result >= n)
		{
			left = mid + 1;
			if (mid > maxValue)
				maxValue = mid;
		}
		else 
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
	}
	
	Cutline();

	cout << maxValue << "\n";

	return 0;
}