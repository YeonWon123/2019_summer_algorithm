#include <iostream>

using namespace std;

int n, r, c;
int cnt;
void Z(int size, int y, int x)
{
	if (size == 2)
	{
		if (y == r && x == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;
		if (y == r && x + 1 == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;
		if (y + 1 == r && x == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;
		return;
	}
	Z(size / 2, y, x); // 1사분면
	Z(size / 2, y, x + (size / 2)); // 2사분면
	Z(size / 2, y + (size / 2), x); // 3사분면
	Z(size / 2, y + (size / 2), x + (size / 2)); // 4사분면

}
int main()
{
	
	cin >> n >> r >> c;
	int temp = 1;
	for (int i = 0; i < n; i++)
		temp = temp * 2;
	Z(temp, 0, 0);
	return 0;

}