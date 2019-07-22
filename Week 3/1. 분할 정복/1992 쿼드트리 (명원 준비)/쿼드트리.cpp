#include <iostream>
#include<string>
using namespace std;

void recursion(int y, int x, int length);


char input[64][64];



int main(void)
{
	int N;
	cin >> N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> input[i][j];
	}
	recursion(0, 0, N);
	// 메모리 용량  128
	return 0;
}


void recursion(int y, int x, int length)
{
	char num = input[y][x];
	int sw = 0;

	for (int i = y; i < y + length; i++)
	{
		for (int j = x; j < x + length; j++)
		{
			if (num != input[i][j])
			{
				sw = 1;
				break;
			}
		}

		if (sw == 1)
			break;

	}

	if (sw == 1)
	{
		int newlength = length / 2;
		cout << "(";
		recursion(y, x, newlength);
		recursion(y, x + newlength, newlength);
		recursion(y + newlength, x, newlength);
		recursion(y + newlength, x + newlength, newlength);
		cout << ")";
		return;
	}

	else
	{
		if (num == '0')
		{
			cout << "0";
			return;
		}
		else
		{
			cout << "1";
			return;
		}
	}




}
	


