#include <iostream>
#include <algorithm>
#define INF 98
using namespace std;
int d[501]; // ���� ��
int m[501][501]; // �����迭
int n; // ����
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
		m[i][i] = 0; // �ε��� x,y�� ���� �迭������ ���ص� 0
	}
	for (diagonal = 1; diagonal <= n - 1; diagonal++) // 1���� n-1���� ������ ����
	{
		for (i = 1; i <= n - diagonal; i++) // 1����  k ��ŭ ���̳��� ���� ������ ���� ����
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
