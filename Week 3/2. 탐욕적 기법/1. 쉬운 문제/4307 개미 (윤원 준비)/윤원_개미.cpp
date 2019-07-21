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

		// �߽ɰ� ���� ����� ���� ���� �� ������ ���� �� vs �߽ɰ� ���� ����� ���� ������ �� ������ ���� ��
		if (l - mids < mids)
			cout << l - mids << " ";
		else
			cout << mids << " ";

		// ���� ���� ���� ������ �� ������ ���� �� vs ���� ū ���� ���� �� ������ ���� ��
		if (l - min > max)
			cout << l - min << "\n";
		else
			cout << max << "\n";
	}
	return 0;
}