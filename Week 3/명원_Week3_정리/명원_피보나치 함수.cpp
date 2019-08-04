#include<iostream>
using namespace std;

int arr[2][41];

int main(void)
{
	

	arr[0][0] = 1; arr[1][0] = 0;  arr[0][1] = 0; arr[1][1] = 1;

	for (int i = 2; i <= 40; i++) {

		arr[0][i] = arr[0][i - 1] + arr[0][i - 2];
		arr[1][i] = arr[1][i - 1] + arr[1][i - 2];
	}

	int N, T;
	cin >> T;

	for(int i=0;i<T;i++)
	{

		cin >> N;
		cout << arr[0][N] << " " << arr[1][N] << "\n";

	}


	system("pause");
	return  0;
}