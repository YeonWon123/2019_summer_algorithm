#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
// √÷¥Î 44
int num[45];

void makeEureka()
{
	for (int i = 1; i < 45; i++)
	{
		num[i-1] = (i * (i + 1)) / 2;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int m = 0;
	makeEureka();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		bool t = false;
		for (int a = 0; a < 44; a++) {
			for (int b = 0; b < 44; b++) {
				for (int c = 0; c < 44; c++) {
					if (num[a] + num[b] + num[c] == m)
					{
						t = true;
					}
				}
			}
		}
		if (t)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;

}

