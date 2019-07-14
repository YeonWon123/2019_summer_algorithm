#include <iostream>
char arr[3072][6143];
using namespace std;

// n : 줄 수 / x,y : 좌표
void star(int n, int x, int y) 
{
	if (n == 3) // 높이가 3이면
	{
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	} // 별을 만들어 출력
	star(n / 2, x, y); // 위의 삼각형 높이와 맨 위 꼭대기 좌표를 보낸다.
	star(n / 2, x - (n/2), y + (n/2)); // 왼쪽 하단 삼각형 높이와 맨 위 꼭대기 좌표를 보낸다.
	star(n / 2, x + (n / 2), y + (n / 2)); // 오른쪽 하단 삼각형 높이와 맨 위 꼭대기 좌표를 보낸다.

	}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2 * n - 1; j++)
		{
				arr[i][j] = ' '; 
		}
	}

	star(n, n - 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}