#include <iostream>
#include <set>
#include <string>
using namespace std;
set <pair<long, string>> s;
set <pair<long, string>>::iterator iter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s.insert(make_pair(str.length(), str));
	}
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		cout << iter->second << "\n";
	}
	return 0;
}