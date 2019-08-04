#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[10001]; // 카드 값 저장
int r[10001]; // 최대값 저장
void Search_max_value();
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	Search_max_value();
	cout << r[n] << "\n";

	return 0;
}

void Search_max_value()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			r[i] = max(r[i], a[j] + r[i - j]);
		}
	}

}