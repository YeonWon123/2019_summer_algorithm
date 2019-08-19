#include<iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int signarea = 0;

	int a1, a2, b1, b2, c1, c2;

	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

	signarea = ((a1*b2 - a2 * b1) + (b1*c2 - b2 * c1) + (c1*a2 - c2 * a1)) / 2;

     
	if (signarea > 0) cout << 1;
	else if (signarea < 0) cout << -1;
	else cout << 0;


	//system("pause");
	return 0;
}