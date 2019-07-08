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
		if (n <= 10) // 10이하의 값이면 n이 n번째 감소하는 수
			cout << n << "\n";
		else if (n == 1022)
			cout << 9876543210 << "\n";
		else if (n >= 1023) // 9876543210 이후에는 감소하는수를 만들 수 없다.
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
					q.push(temp * 10 + j); // 감소하는 수에 10을 곱하고 끝자리에 숫자를 더해서 새로운 수를 만듬
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