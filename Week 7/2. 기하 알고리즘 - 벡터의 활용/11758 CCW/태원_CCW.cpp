#include <iostream>
using namespace std;
int a[2];
int b[2];
int c[2];
void cross()
{
	int vec = 0.5 * ((a[0] * b[1]) - (a[1] * b[0]) + (b[0] * c[1]) - (c[0] * b[1]) + (c[0] * a[1]) - (a[0] * c[1]));
	if (vec > 0)
		cout << 1 << "\n";
	else if (vec < 0)
		cout << -1 << "\n";
	else 
		cout << 0 << "\n";

}

int main()
{
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

	cross();

	return 0;
}