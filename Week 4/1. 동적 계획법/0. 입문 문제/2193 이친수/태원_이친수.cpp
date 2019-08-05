#include <iostream>
using namespace std;
int n;
long long zero = 1;
long long one = 0;
int main()
{
	cin >> n;
	long long save = 0;
	if (n == 1 || n == 2) {
		cout << 1 << "\n";
	}
	else
	{
		int k = n - 2;
		while (k) {
			save = zero;
			zero += one;
			one = save;
			k--;
		}
		cout << zero + one << "\n";
		}
}