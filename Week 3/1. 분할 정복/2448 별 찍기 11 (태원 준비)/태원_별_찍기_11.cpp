#include <iostream>
char arr[3072][6143];
using namespace std;

// n : �� �� / x,y : ��ǥ
void star(int n, int x, int y) 
{
	if (n == 3) // ���̰� 3�̸�
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
	} // ���� ����� ���
	star(n / 2, x, y); // ���� �ﰢ�� ���̿� �� �� ����� ��ǥ�� ������.
	star(n / 2, x - (n/2), y + (n/2)); // ���� �ϴ� �ﰢ�� ���̿� �� �� ����� ��ǥ�� ������.
	star(n / 2, x + (n / 2), y + (n / 2)); // ������ �ϴ� �ﰢ�� ���̿� �� �� ����� ��ǥ�� ������.

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