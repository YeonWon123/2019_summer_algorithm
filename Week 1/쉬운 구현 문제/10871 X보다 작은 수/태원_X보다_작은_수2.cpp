#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	int x = 0;

	int a = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < x)
		{
			cout << a;
			cout << " ";
		}
	}
	return 0;
}