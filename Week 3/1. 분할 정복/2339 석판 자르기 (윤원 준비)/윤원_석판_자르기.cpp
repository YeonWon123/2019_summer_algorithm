#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// �ڷ��� ����
// pair<int, int> : ���� ����ü ����, �Ҽ��� ����
// vector<pair<int, int>> : �Ҽ��� ��ǥ
typedef pair<pair<int, int>, vector< pair<int, int> > > piiii;

// ��������
int n;				// ������ ũ��
int map[22][22];	// ����

// ���ǿ��� ���� ����ü ����, �Ҽ����� ������ �Ҽ����� ��ǥ�� �̾Ƴ��� �Լ�
inline piiii cnt(int sx, int sy, int ex, int ey) {
	int gold = 0, stone = 0;
	vector< pair<int, int> > v;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (map[i][j] == 1) {
				stone++;
				v.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)
				gold++;
		}
	}
	return make_pair(make_pair(gold, stone), v);
}

// �Ҽ����� �������� ������ ������ �Լ�
// ������ ������, ����, �ڸ� ������ �Ķ���ͷ� �Ѱ���
// �ش� ���ǿ��� ������ ���ǿ� �´� ���� ������ ����� ������ �ڸ��� ����� ��ȯ���ִ� �Լ� ����
// �ش� �Լ��� ��������� ȣ��
int recur(int sx, int sy, int ex, int ey, int vert) {
	piiii check;
	piiii temp;
	check = cnt(sx, sy, ex, ey);
	if (check.first.first == 1 && check.first.second == 0) return 1;
	else if (check.first.first > 1 && check.first.second == 0) return 0;
	else if (check.first.first == 0) return 0;
	else if (check.first.second > 0) {
		int res = 0;
		for (int i = 0; i < check.first.second; i++) {
			int xx, yy;
			xx = check.second[i].first;
			yy = check.second[i].second;

			if (vert) {
				temp = cnt(sx, yy, ex, yy);
				if (temp.first.first > 1) continue;
				if (yy - sy < 1 || ey - yy < 1) continue;
				res += recur(sx, sy, ex, yy - 1, !vert) * recur(sx, yy + 1, ex, ey, !vert);
			}
			else {
				temp = cnt(xx, sy, xx, ey);
				if (temp.first.first > 1) continue;
				if (xx - sx < 1 || ex - xx < 1) continue;
				res += recur(sx, sy, xx - 1, ey, !vert) * recur(xx + 1, sy, ex, ey, !vert);
			}
		}
		return res;
	}
	return 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	piiii check = cnt(1, 1, n, n);
	if (check.first.first == 1 && check.first.second == 0) printf("1\n");
	else {
		int res = recur(1, 1, n, n, false) + recur(1, 1, n, n, true);
		if (res == 0) res = -1;
		printf("%d\n", res);
	}
}

int main()
{
	solve();
	return 0;
}