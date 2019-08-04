#include <iostream>
#include <algorithm>
#define INF 98
using namespace std;
int d[501]; // 들어온 값
int m[501][501]; // 곱셈배열
int n; // 개수
int func(int i, int j)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int k = i;
	cout << m[i][j] << "\n";
	int minvalue = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
	cout << m[i][j] << "\n";

		for (; k < j - 1; k++) {
			if(minvalue > m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j])
			 minvalue = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
		}
		return minvalue;
}
int minmult() 
{
	int i, j, k, diagonal;
	for (i = 1; i <= n; i++)
	{
		m[i][i] = 0; // 인덱스 x,y가 같은 배열끼리는 곱해도 0
	}
	for (diagonal = 1; diagonal <= n - 1; diagonal++) // 1에서 n-1까지 포문을 돌림
	{
		for (i = 1; i <= n - diagonal; i++) // 1에서  k 만큼 차이나는 값이 가능할 값을 설정
		{
			j = i + diagonal;
			m[i][j]= func(i, j);
		}
	}
	return m[1][n];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i - 1] >> d[i];
	}
	cout << minmult() << "\n";
	return 0;
}
