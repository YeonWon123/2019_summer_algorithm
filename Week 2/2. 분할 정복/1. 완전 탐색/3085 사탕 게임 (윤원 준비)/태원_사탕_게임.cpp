#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
using namespace std;

string s[50];

int candy_count(int n)
{
	int cnt = 1;
	for (int j = 0; j < n; j++) {
		int temp = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[j][i] == s[j][i + 1])
				temp++;
			else
			{
				cnt = max(cnt, temp);
				temp = 1;
			}
			cnt = max(cnt, temp);
		}
		temp = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i][j] == s[i + 1][j])
				temp++;
			else
			{
				cnt = max(cnt, temp);
				temp = 1;
			}
			cnt = max(cnt, temp);
		}
	}
	return cnt;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int result = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n-1; j++)
		{
			
			swap(s[i][j], s[i][j + 1]);
			result = max(result, candy_count(n));
			swap(s[i][j], s[i][j + 1]);
			result = max(result, candy_count(n));
			swap(s[j][i], s[j + 1][i]);
			result = max(result, candy_count(n));
			swap(s[j][i], s[j + 1][i]);

		}
	cout << result << "\n";
	return 0;
}