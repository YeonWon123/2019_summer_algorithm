
#include <iostream>
#include <vector>
using namespace std;

vector <int> sum[501]; // 원래 배열
int maxvalue = 0;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a = i + 1;
		int k;
		while (a)
		{
			cin >> k;
			sum[i].push_back(k);
			a--;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < sum[i].size(); j++)
		{
			if (j == 0)
				sum[i][j] += sum[i - 1][j];
			else if (i == j)
				sum[i][j] += sum[i - 1][j - 1];
			else
			{
				if (sum[i - 1][j] < sum[i - 1][j - 1])
					sum[i][j] += sum[i - 1][j - 1];
				else
					sum[i][j] += sum[i - 1][j];
			}
		}

	}



	for (int i = 0; i < sum[n-1].size(); i++)
	{
		if (maxvalue < sum[n - 1][i])
			maxvalue = sum[n - 1][i];
	}
	cout << maxvalue << "\n";

	return 0;
}
