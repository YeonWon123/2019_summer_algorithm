#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, H, W, N;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		int a = N / H + 1;  // ���� ��Ÿ�� (x02, xx03) 
		int b = N % H;		// ���� ��Ÿ�� (4xx, 12xx)
		if (b == 0) {
			b = H;
			a = N / H;
		}
		cout << b;
		if (a < 10) {
			cout << 0;
		}
		cout << a << "\n";
	}
}