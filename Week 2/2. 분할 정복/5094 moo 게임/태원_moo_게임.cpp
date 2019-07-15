#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;

string moo(string s, int n)
{
	string s1 = "m";
	for (int i = 0; i < n + 2; i++) {
		s1 += "o";
	}
	string plus = s + s1 + s;

	return plus;

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	s = "moo";
	int i = 0;
	cin >> n;
	while (n > s.length()) {
		s = moo(s, i+1);
		i++;
	}
	cout << s[n-1] << "\n";
		return 0;


}
