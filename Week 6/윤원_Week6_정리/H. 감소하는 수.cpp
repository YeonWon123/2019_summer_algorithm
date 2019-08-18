#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int pp = 1; pp <= 1023; pp++) {
		queue<int> q;

		int cnt = 0;
		int temp, m;

		string file_name_in = to_string(pp) + ".in";
		string file_name_out = to_string(pp) + ".out";

		ofstream out(file_name_in);
		out << pp;
		out.close();

		ofstream out2(file_name_out);
		if (pp <= 10) // 10이하의 값이면 n이 n번째 감소하는 수
			out2 << pp;
		else if (pp == 1022)
			out2 << 9876543210;
		else if (pp >= 1023) // 9876543210 이후에는 감소하는수를 만들 수 없다.
			out2 << "-1";
		else {
			for (int i = 1; i < 10; i++) {
				q.push(i);
				cnt++;
			}
			while (cnt < pp) {
				temp = q.front();
				q.pop();
				m = temp % 10;
				for (int j = 0; j < m; j++)
				{
					q.push(temp * 10 + j); // 감소하는 수에 10을 곱하고 끝자리에 숫자를 더해서 새로운 수를 만듬
					cnt++;
					if (cnt == pp) {
						out2 << temp * 10 + j;
						break;
					}
				}
			}
		}

		out2.close();
	}

	return 0;
}