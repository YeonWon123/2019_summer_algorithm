#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > point;
pair<long long, long long> origin;

long long SignArea(pair<int, int> p1, pair<int, int> p2) {
	return (long long)p1.first * p2.second - (long long)p2.first * p1.second;
}

long long CCW(pair<long long, long long> p1, 
	pair<long long, long long> p2, pair<long long, long long> p3) {
		long long area = SignArea(p1, p2) + SignArea(p2, p3) + SignArea(p3, p1);
		return area;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// 입력받음
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

	origin = point[0];

	// 삼각형 넓이 누적, 단, 1/2은 하지 않은 상태로 진행
	long long result = 0;
	for (int i = 1; i < N - 1; i++) {
		long long ccw_result = CCW(origin, point[i], point[i + 1]);
		result += ccw_result;
	}

	// 몫을 먼저 출력, 단, CCW 결과가 음수이면 양수로 만들어줌
	if (result < 0) result *= -1;

	// CCW의 결과를 삼각형의 면적으로 나눠줌
	cout << result / 2;

	// 나머지를 그 다음에 출력
	if (result % 2 == 0) cout << ".0";
	else cout << ".5";
}