#include <iostream>
#define ll long long

using namespace std;

struct node {
	ll x = 0, y = 0;
	ll p = 0, q = 0;

	node operator - (const node& p) {
		return { x - p.x, y - p.y, 0, 0 };
	}

	ll cross(const node& p) {
		return x * p.y - y * p.x;
	}

	bool operator < (const node& p) {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

node black[105];
node white[105];

bool comp(node p1, node p2) {
	if (p1.q * p2.p != p1.p * p2.q) return p1.q * p2.p < p1.p * p2.q;
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

void qsort(node* p, int left, int right) {
	if (left >= right) return;
	int l = left - 1;
	int r = right + 1;
	node mid = p[(l + r) / 2];
	while (1) {
		while (comp(p[++l], mid));
		while (comp(mid, p[--r]));
		if (l >= r) break;
		node tmp = p[l];
		p[l] = p[r];
		p[r] = tmp;
	}
	qsort(p, left, l - 1);
	qsort(p, r + 1, right);
}

struct STACK {
	int stack[105];
	int size = 0;

	void push(int n) {
		stack[size++] = n;
	}

	void pop() {
		size--;
	}

	int top() {
		return stack[size - 1];
	}
};

int ccw(node p1, node p2, node p3) {
	ll ans = (p2 - p1).cross(p3 - p2);
	if (ans > 0) ans = 1;
	else if (ans < 0) ans = -1;
	return ans;
}

bool isCross(node p1, node p2, node p3, node p4) {
	int ab = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int cd = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (ccw(p1, p2, p3) == 0 && ccw(p1, p2, p4) == 0) {
		if (p2 < p1) swap(p1, p2);
		if (p4 < p3) swap(p3, p4);
		return !(p2 < p3 || p4 < p1);
	}
	return ab <= 0 && cd <= 0;
}

//점 a가 b안에 있는지 검사
bool isPointInside(STACK& s, node* a, node* b) {
	if (s.size <= 2) return false;

	int prevDir = ccw(b[s.stack[0]], b[s.stack[1]], a[0]);

	for (int i = 1; i < s.size; i++) {
		int nowDir = ccw(b[s.stack[i]], b[s.stack[(i + 1) % s.size]], a[0]);
		if (prevDir != nowDir) return false;
	}
	return true;
}

void sortCCW(node* point, int num) {
	qsort(point, 0, num - 1);
	for (int i = 1; i < num; i++) {
		point[i].p = point[i].x - point[0].x;
		point[i].q = point[i].y - point[0].y;
	}
	qsort(point, 1, num - 1);
}

void convexHull(STACK& s, node* point, int num) {
	if (num > 0) s.push(0);
	if (num > 1) s.push(1);
	int next = 2;
	while (next < num) {
		while (s.size >= 2) {
			int second = s.top();
			s.pop();
			int first = s.top();

			if (ccw(point[first], point[second], point[next]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
}

bool polygonIntersects(STACK& a, STACK& b) {
	if (isPointInside(b, black, white) || isPointInside(a, white, black)) return true;

	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < b.size; j++) {
			if (isCross(black[a.stack[i]], black[a.stack[(i + 1) % a.size]], white[b.stack[j]], white[b.stack[(j + 1) % b.size]]))
				return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < 105; ++i) {
			black[i].p = black[i].q = white[i].p = white[i].q = 0;
		}

		for (int i = 0; i < n; i++) {
			cin >> black[i].x >> black[i].y;
		}
		for (int i = 0; i < m; i++) {
			cin >> white[i].x >> white[i].y;
		}
		if (n <= 1 && m <= 1) {
			cout << "YES\n";
			continue;
		}
		STACK bs;
		sortCCW(black, n);
		convexHull(bs, black, n);

		STACK ws;
		sortCCW(white, m);
		convexHull(ws, white, m);

		if (polygonIntersects(bs, ws)) cout << "NO\n";
		else cout << "YES\n";
	}
}