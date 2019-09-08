#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
int n;
int a, b;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
float fraction(int a, int b)
{
	float temp = (float)a / (float)b;
	return temp;
}
void henly(int a, int b)
{
	while (a != 1)
	{
		int temp = fraction(b, a);
		int x = temp + 1;
		a = x * a - b;
		b = x * b;
		int g = gcd(a, b);
		a = a / g;
		b = b / g;
	}
	cout << b << "\n";
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		henly(a, b);
	}
	return 0;
}