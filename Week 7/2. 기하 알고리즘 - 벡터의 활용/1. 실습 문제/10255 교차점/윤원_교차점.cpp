#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
struct POS {
	int x, y;
};
vector<int> ans;
set<pair<int, int> > chk;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	// ccw곱 홀수 + 사각형 내부 피하면 교차
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 < x3 && x1 < x4 && x2 < x3 && x2 < x4) ||
			(x3 < x1 && x3 < x2 && x4 < x1 && x4 < x2)) return false;
		if ((y1 < y3 && y1 < y4 && y2 < y3 && y2 < y4) ||
			(y3 < y1 && y3 < y2 && y4 < y1 && y4 < y2)) return false;
		return true;
	}
	return false;
}

bool isCross_rect_point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int line = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int rect = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (line == 0 && rect <= 0) return true;
	else return false;
}

bool isCross_rect_line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int line = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int rect = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (line < 0 && rect <= 0) return true;
	else return false;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int xmin, ymin, xmax, ymax;
	for (int i = 0; i < T; i++) {
		cin >> xmin >> ymin >> xmax >> ymax;
		POS r1 = { xmin, ymin };
		POS r2 = { xmin, ymax };
		POS r3 = { xmax, ymin };
		POS r4 = { xmax, ymax };

		POS l1, l2;
		int x1, y1, x2, y2;
		cin >> l1.x >> l1.y >> l2.x >> l2.y;
		if (l1.x > l2.x) swap(l1, l2);

		// 1. 교점이 없는 경우
		bool isNone = true;
		if (isCross(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y) ||
			isCross(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y) ||
			isCross(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y) ||
			isCross(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) isNone = false;
		if (isNone) {
			cout << 0 << '\n';
			continue;
		}

		// 2. 교점이 무수히 많은 경우 -> x 좌표 기준으로만 정렬했으므로,
		// y좌표는 뭐가 큰지를 모르니 두 경우를 다 고려한다.
		if (l1.x == l2.x && l1.x == xmin) {
			if ((l1.y < ymax) && (l2.y > ymin) || (l2.y < ymax) && (l1.y > ymin)) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (l1.x == l2.x && l1.x == xmax) {
			if ((l1.y < ymax) && (l2.y > ymin) || (l2.y < ymax) && (l1.y > ymin)) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (l1.y == l2.y && l1.y == ymax) {
			if ((l1.x < xmax) && (l2.x > xmin) || (l2.x < xmax) && (l1.x > xmin)) {
				cout << 4 << "\n";
				continue;
			}
		}
		else if (l1.y == l2.y && l1.y == ymin) {
			if ((l1.x < xmax) && (l2.x > xmin) || (l2.x < xmax) && (l1.x > xmin)) {
				cout << 4 << "\n";
				continue;
			}
		}

		int cnt_rect_line = 0, cnt_rect_point = 0;
		if (isCross_rect_line(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y)) cnt_rect_line++;
		if (isCross_rect_line(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y)) cnt_rect_line++;
		if (isCross_rect_line(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y)) cnt_rect_line++;
		if (isCross_rect_line(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) cnt_rect_line++;

		if (isCross_rect_point(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y)) cnt_rect_point++;
		if (isCross_rect_point(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y)) cnt_rect_point++;
		if (isCross_rect_point(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y)) cnt_rect_point++;
		if (isCross_rect_point(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) cnt_rect_point++;

		cout << cnt_rect_line + cnt_rect_point / 2 << "\n";
	}
	return 0;
}