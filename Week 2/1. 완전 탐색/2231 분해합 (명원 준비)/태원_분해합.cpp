#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int k = 1;
	string s;
	for(int j = 0; j < n; j++)
	{
		s = to_string(k);
		int sum = k;
		for (int i = 0; i < s.length(); i++)
		{
			sum += s[i] - '0';
		}
		if (sum == n) {
			cout << k << "\n";
			return 0;
		}
		k++;
	}
	cout << 0 << "\n";
	return 0;
}