#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int temp = N;
	int N2;
	int count = 0;

	do
	{
		N2 = temp / 10 + temp % 10;
		temp = temp % 10 * 10 + N2 % 10;
		count++;
	} while (temp != N);

	printf("%d\n", count);

	return 0;
}