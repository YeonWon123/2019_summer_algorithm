#include <iostream>

using namespace std;
char a[64][64];
void cut(int n, int x, int y)
{
	bool same = true;
	char first = a[x][y];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[x + i][y + j] != first) {
				same = false;
				break;
			}
		}
	}
		if (same) {
			cout << first;
		
		}
		else
		{
			cout << "(";
			cut(n / 2, x, y);
			cut(n / 2, x, y + n / 2);
			cut(n / 2, x + n / 2, y);
			cut(n / 2, x + n / 2, y + n / 2);
			cout << ")";
		}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cut(n, 0, 0);
	return 0;
}