#include <iostream>
using namespace std;

int main(void)
{
	int N; int a, b;  
	int count = 0;
	int object;
	cin >> N;

	int Y = N; 

	if (N < 10)
		N = N * 10;

	do
	{
		a = N / 10;
		b = N % 10;
       
		object = a + b;

		if (object >= 10)
			object = object % 10;

		N = b * 10 + object;

		count++;

	} while (Y != N);
	
	 
	cout << count;


	
	return 0;
}