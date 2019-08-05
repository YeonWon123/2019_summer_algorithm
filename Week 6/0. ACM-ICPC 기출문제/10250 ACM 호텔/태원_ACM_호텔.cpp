#include <iostream>
using namespace std;
int t, h, w, n;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int start = 101;
		int cnt = 1;
		int cnth = 1;
		int cntw = 1;
		cin >> h >> w >> n;
		while (1) {
			if (cnt != n)
			{
				cnt++;
				if (cnth < h) {
					cnth++;
					start += 100;
				}
				else if (cnth == h)
				{
					start -= 100 * (cnth - 1);
					cnth = 1;
					start++;
				}
			}
			else 
			{
				cout << start << "\n";
				break;
			}
		}
	}
}