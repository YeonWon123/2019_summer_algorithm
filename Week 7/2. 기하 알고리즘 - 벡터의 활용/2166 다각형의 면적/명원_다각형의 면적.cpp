#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;
// �κ����� ������ ����纯���� ũ�⸦ �̿�


long double sum = 0;

int main(void)
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);  

	double x[10002];
	double y[10002];
	int n;  int cnt = 0;    cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	x[n] = x[0];
	y[n] = y[0];

	for (int i = 0; i < n; i++) {

		sum+= ((x[i] * y[i + 1]) / 2 - (x[i + 1] * y[i]) / 2);
	}

	cout << fixed;
	cout.precision(1);

	cout << fabs(sum);  // fabs �Ǽ��� �ڷ��� ���밪



	//system("pause");
	return 0;
}