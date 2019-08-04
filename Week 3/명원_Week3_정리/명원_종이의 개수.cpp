#include<iostream>
#include<cstring>
using namespace std;

int arr[2187][2187];
int N;
int mis = 0; int zero = 0; int plu = 0;



void recursion(int x, int y, int N);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			cin >> arr[i][j];
		}
	}


	recursion(0, 0, N);

	cout << mis << "\n";
	cout << zero << "\n";
	cout << plu << "\n";

	//system("puase");
	return 0;
}

void recursion(int x, int y, int N)
{
	int sw = 0;
	int first = arr[y][x];

	for (int i = y; i < y + N; i++) {

		for (int j = x; j < x + N; j++) {

			if (first != arr[i][j])
			{
				sw = 1;  break;
			}
		}

		if (sw == 1) break;
	}


	if (sw == 1) {

		int newN = N / 3;

		recursion(x, y, newN);
		recursion(x + newN, y, newN);
		recursion(x + newN * 2, y, newN);
		recursion(x, y + newN, newN);
		recursion(x + newN, y + newN, newN);
		recursion(x + newN * 2, y + newN, newN);
		recursion(x, y + newN * 2, newN);
		recursion(x + newN, y + newN * 2, newN);
		recursion(x + newN * 2, y + newN * 2, newN);

	}

	else {

		if (first == -1)
		{
			mis++;  return;
		}

		else if (first == 0) {

			zero++;  return;
		}

		else
		{
			plu++; return;
		}
	}

}