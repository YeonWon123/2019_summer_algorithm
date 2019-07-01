#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a = 0;
	int n = 0;
	int m = 0;
	string s;
	cin >> a;
	vector<string> v;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		v.push_back(s);
		n = count(v.begin(), v.end(), "(");
		m = count(v.begin(), v.end(), ")");
		cout << n <<" " << m;
		if (n == m)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
