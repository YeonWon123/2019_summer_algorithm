#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int min = 9999999;
		int max = -9999999;
		int l, n, temp;
		cin >> l >> n;
		double mid = l / 2;
		int mids = 9999999;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (min > temp) min = temp;
			if (max < temp) max = temp;
			if (abs(mid-temp) <= abs(mid-mids)) mids = temp;
		}

#ifdef DEBUG
		cout << "------------------------------\n";
		cout << "min : " << min << endl;
		cout << "max : " << max << endl;
		cout << "mids : " << mids << endl;
		cout << "------------------------------\n";
#endif

		// 중심과 가장 가까운 값이 왼쪽 맨 끝으로 가는 것 vs 중심과 가장 가까운 값이 오른쪽 맨 끝으로 가는 것
		if (l - mids < mids)
			cout << l - mids << " ";
		else
			cout << mids << " ";

		// 가장 작은 값이 오른쪽 맨 끝으로 가는 것 vs 가장 큰 값이 왼쪽 맨 끝으로 가는 것
		if (l - min > max)
			cout << l - min << "\n";
		else
			cout << max << "\n";
	}
	return 0;
}