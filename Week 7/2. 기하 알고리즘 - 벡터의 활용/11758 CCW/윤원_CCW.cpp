#include <iostream>
using namespace std;

double SignArea(pair<int, int> p1, pair<int, int> p2) {
	return (double)p1.first * p2.second - (double)p2.first * p1.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pair<int, int> p1, p2, p3;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;

	double area = 0.5 * (SignArea(p1, p2) + SignArea(p2, p3) + SignArea(p3, p1));

	if (area > 0)
		cout << 1;
	else if (area < 0)
		cout << -1;
	else
		cout << 0;

	return 0;
}