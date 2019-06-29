#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int a = 0;
	cin >> n;
	a = (n * (n + 1)) / 2;
	cout << a;
	return 0;
}