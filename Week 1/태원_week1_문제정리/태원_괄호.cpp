#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a = 0;
	string s;
	cin >> a;
	while (a--)
	{
		int n = 0;
		int m = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				n++;
			else if (s[i] == ')')
				n--;
			if (n < 0)
				m++;
		}
		if (n == 0 && m == 0)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		
	}
	return 0;
}
