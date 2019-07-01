#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;

	char number[110];
	cin >> number;

	for (int i = 0; i < N; i++)
	{
		sum = sum + (number[i] - 48);
	}

	cout << sum << "\n";
	return 0;
}