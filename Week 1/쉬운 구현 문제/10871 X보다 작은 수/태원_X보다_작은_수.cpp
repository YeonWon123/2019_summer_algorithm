#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, X;
	cin >> N >> X;

	int a[10000];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		if (a[i] < X)
		{
			cout << a[i] << " ";
		}

	}
	return 0;
}
