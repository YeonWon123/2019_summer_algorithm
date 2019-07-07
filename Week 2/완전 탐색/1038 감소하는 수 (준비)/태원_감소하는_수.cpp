#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		int cnt = 0;
		int n = 0;
		int temp, m;
		cin >> n;
		if (n <= 10) // 10������ ���̸� n�� n��° �����ϴ� ��
			cout << n << "\n";
		else if (n == 1022)
			cout << 9876543210 << "\n";
		else if (n >= 1023) // 9876543210 ���Ŀ��� �����ϴ¼��� ���� �� ����.
			cout << "-1" << "\n";
		else {
			for (int i = 1; i < 10; i++) {
				q.push(i);
				cnt++;

			}
			while (cnt < n) { 
				temp = q.front();
				q.pop();
				m = temp % 10;
				for (int j = 0; j < m; j++)
				{
					q.push(temp * 10 + j); // �����ϴ� ���� 10�� ���ϰ� ���ڸ��� ���ڸ� ���ؼ� ���ο� ���� ����
					cnt++;
					if (cnt == n) {
						cout << temp * 10 + j << "\n";
						break;
					}
				}
			}
		}
		return 0;


}