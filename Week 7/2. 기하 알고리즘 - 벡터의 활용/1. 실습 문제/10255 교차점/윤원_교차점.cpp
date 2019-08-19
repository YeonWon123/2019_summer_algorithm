#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct POINT {
	int x;
	int y;

	bool operator != (const POINT &a) const {
		return (x != a.x || y != a.y);
	}

} point;

point X, Y, A, B, C, D;

int CCW(point a, point b, point c) {
	int area = (a.x * b.y) - (b.x * a.y) + (b.x * c.y) - (c.x * b.y) + (c.x * a.y) - (c.y * a.x);
	if (area > 0)		return 1; // �ݽð� ����
	else if (area < 0)	return -1; // �ð� ����
	else return 0;
}

bool Between(point a, point b, point c) {
	if (CCW(a, b, c) == 0 &&
		(min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) &&
		(min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y))) {
		return true; // �������� ����
	}
	else 
		return false; // �������� �������� ����
}

int Intersect(point a, point b, point c, point d) {

	// XY������ �簢���� ���ԵǴ��� ���� ���� (�ϵ��ڵ�)

	// �̰� �ƴϸ� �ؿ��� ���
	if (Between(a, b, c) || Between(a, b, d) || Between(c, d, a) || Between(c, d, b))
		return 1;
	else {
		// �̺κ��� CCW���� �������� 0���� �и��ؼ� �Ǵ�
		if ((CCW(a, b, c) * CCW(a, b, d) <= 0) && (CCW(c, d, a) * CCW(c, d, b) <= 0))
			return 1;
	}
	return 0;
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
		cin >> X.x >> X.y >> Y.x >> Y.y;

		A.x = xmin; A.y = ymax;
		B.x = xmin; B.y = ymin;
		C.x = xmax; C.y = ymax;
		D.x = xmax; D.y = ymin;

		int minus = 0;
		if (Between(X, Y, A)) minus++;
		if (Between(X, Y, B)) minus++;
		if (Between(X, Y, C)) minus++;
		if (Between(X, Y, D)) minus++;

		int counts1 = Intersect(X, Y, A, B);
		int counts2 = Intersect(X, Y, A, C);
		int counts3 = Intersect(X, Y, B, D);
		int counts4 = Intersect(X, Y, C, D);

		if (counts1 == 4 || counts2 == 4 || counts3 == 4 || counts4 == 4)
			// ������ �������� ���
			cout << 4 << "\n";
		else {
			int counts = counts1 + counts2 + counts3 + counts4;

			// ������ ���� ���
			if (counts == 0)
				cout << 0 << "\n";

			// ������ 1���� ���
			else if (counts == 1)
				cout << 1 << "\n";

			// ������ 2���� ���
			else
				cout << 2 << "\n";
			/*
			else if (counts == 2)
				cout << 2 - minus << "\n";
			else
				cout << 4 - minus/2 << "\n";
			*/
		}
	}
	return 0;
}