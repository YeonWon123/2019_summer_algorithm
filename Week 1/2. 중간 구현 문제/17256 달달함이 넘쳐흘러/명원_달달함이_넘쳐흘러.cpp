#include<iostream>
using namespace std;


int main(void)
{
	int a[3], c[3], b[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> c[i];
	}

	b[0] = c[0] - a[2];
	b[1] = c[1] / a[1];
	b[2] = c[2] - a[0];


	for (int i = 0; i < 3; i++)
	{
		cout << b[i] << " ";
	}



	//system("pause");
	return 0;
}