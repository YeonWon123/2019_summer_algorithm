#include <iostream>
using namespace std;

// 8393��  10871�� 

int main(void)
{
	int n;
	cin >> n;
	int a = 0;
	for (int i = 1; i < n+1; i++)
	{
		a += i;
	}

	cout << a;
	return 0;
}