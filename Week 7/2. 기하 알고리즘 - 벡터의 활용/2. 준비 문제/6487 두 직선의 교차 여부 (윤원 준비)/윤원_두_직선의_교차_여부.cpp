#include<cstdio>
int n, x[4], y[4];
int main() {
	for (scanf("%d", &n); n--;) {
		for (int i = 0; i < 4; i++) scanf("%d%d", x + i, y + i);
		double a = x[1] - x[0], b = y[1] - y[0], c = x[3] - x[2], d = y[3] - y[2];
		if (a * d - b * c) {
			double r = (d * (x[2] - x[0]) - c * (y[2] - y[0])) / (a * d - b * c);
			printf("POINT %.2lf %.2lf\n", a * r + x[0], b * r + y[0]);
		}
		else puts((x[2] - x[0]) * b - (y[2] - y[0]) * a ? "NONE" : "LINE");
	}
	return 0;
}