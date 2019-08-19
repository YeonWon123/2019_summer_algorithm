#include <iostream>
using namespace std;
#define maxValue 10001
#define lli long long int
int n;
lli result;
pair<lli, lli> p[maxValue], origin;

lli ccw(pair<lli, lli> r, pair<lli, lli> p, pair<lli, lli> q)
{
	//lli first = (p.first - r.first) * (q.second - r.second);
	//lli second = (p.second - r.second) * (q.first - r.first);
	//lli result = first - second;
	lli result = (r.first * p.second) - (r.second * p.first)
				+ (p.first * q.second) - (q.first * p.second)
				+ (q.first * r.second) - (r.first * q.second);
	return result;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	origin = p[1];
	for (int i = 2; i <= n - 1; i++)
	{
		lli ccw_result = ccw(origin, p[i], p[i + 1]);
		result += ccw_result;
	}
	if (result < 0) result *= -1;

	cout << fixed;
	cout.precision(1);
	cout << 0.5 * result ;

	return 0;
}