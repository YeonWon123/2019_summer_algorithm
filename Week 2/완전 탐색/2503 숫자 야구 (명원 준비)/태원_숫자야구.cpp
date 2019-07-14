#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s, na, nb;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	int cnt = 0;
	int strike = 0;
	int ball = 0;
	bool a[1000];
	int value;
	memset(a, true, sizeof(a));
		for (int j = 123; j < 1000; j++)
		{
			string t = to_string(j);
			if (t[0] == t[1] || t[1] == t[2] || t[2] == t[0])
				a[j] = false;
			if (t[0] - '0' == 0 || t[1] - '0' == 0 || t[2] - '0' == 0)
				a[j] = false;
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> value >> strike >> ball;
			for (int j = 123; j < 1000; j++)
			{
				na = to_string(value);
				nb = to_string(j);
				int strike_count = 0;
				int ball_count = 0;
				for(int x = 0; x < 3; x++)
					for (int y = 0; y < 3; y++)
					{
						if (x == y && na[x] == nb[y])
							strike_count++;
						if (x != y && na[x] == nb[y])
							ball_count++;
					}
				if (ball_count != ball || strike_count != strike)
					a[j] = false;
			}
		}
		for (int i = 123; i < 1000; i++)
		{
			if (a[i])
				cnt++;
		}
		cout << cnt << "\n";
		return 0;
}