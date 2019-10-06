#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			i--;
			n--;
		}
	}

	// j´Â arrÀÇ index
	int sw = 0;
	int k = 0;
	for (k = 0; k <= n; k++) {
		int p_counts = 0;
		int m_counts = 0;

		for (int j = 0; j < n; j++) {
			if (arr[j] >= k) {
				p_counts++;
			}
			
			if (arr[j] <= k) {
				m_counts++;
			}
		}

	//	cout << k << " " << p_counts << " " << m_counts << endl;

		if (p_counts >= k && (n - k <= m_counts))
			break;
	}

	cout << k;
	return 0;
}