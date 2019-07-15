#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	int m = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++)
	{
		m += s[i] - '0';
 	}
	cout << m;
	return 0;
}