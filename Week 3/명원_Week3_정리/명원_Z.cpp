#include<iostream>
#include<math.h>
using namespace std;



int N, r, c;
int cun = 0;
bool findanswer = false;


// 방향을 나타내는 배열

int ny[4] = { 0,0,1,0 };
int nx[4] = { 0,1,-1,1 };

void recursion(int x, int y, int N);

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> r >> c;


	recursion(0, 0, pow(2,N));



	system("pause");
	return 0;

}

void recursion(int x, int y, int N)
{
	if (findanswer == true)
		return;

	int py = y;
	int px = x;


	if (N == 2) {

		for (int i = 0; i < 4; i++) {

			py = py + ny[i];
			px = px + nx[i];

			if (py == r && px == c) {

				cout << cun;
				findanswer = true;
				return;

			}

			cun++;
		}

		return;
	}

	else {

		int newN = N / 2;

		recursion(x, y, newN);
		recursion(x + newN, y, newN);
		recursion(x, y + newN, newN);
		recursion(x + newN, y + newN, newN);
	}
}