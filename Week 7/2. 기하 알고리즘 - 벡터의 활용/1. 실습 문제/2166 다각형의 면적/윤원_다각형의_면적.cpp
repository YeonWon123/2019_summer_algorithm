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

	// �Է¹���
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

	origin = point[0];

	// �ﰢ�� ���� ����, ��, 1/2�� ���� ���� ���·� ����
	long long result = 0;
	for (int i = 1; i < N - 1; i++) {
		long long ccw_result = CCW(origin, point[i], point[i + 1]);
		result += ccw_result;
	}

	// ���� ���� ���, ��, CCW ����� �����̸� ����� �������
	if (result < 0) result *= -1;

	// CCW�� ����� �ﰢ���� �������� ������
	cout << result / 2;

	// �������� �� ������ ���
	if (result % 2 == 0) cout << ".0";
	else cout << ".5";
}