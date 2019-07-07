// 2019 Summer Algorithm Study Day 1 
// 노태원

// K번째 수
#include <iostream>
#include <algorithm>
using namespace std;
 
int a[5000000]; // 값이 너무커서 글로벌 변수로
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int k = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[k-1];
	
	return 0;
}