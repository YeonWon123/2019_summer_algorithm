#include <iostream>

using namespace std;
int output[3]; // -1,0,1�� ī��Ʈ�ϱ� ���� ũ�� 3�� int�� �迭 ����
int arr[2187][2187]; // n�� �ִ� 3^7 = 2187���� ������
void check(int x, int y, int n) // ���� ���� ����ִ��� Ȯ���ϴ� �Լ�
{// �Ű������� �����ϴ� x, y Ŀ����ǥ�� ������ n�� �� ���� ����
	int first = arr[x][y]; // ù��° Ŀ���� ����ִ� ���� ����
	bool same = true; // ���� ������ Ȯ���ϱ� ���� bool��������

	for (int i = x; i < x + n; i++) // n*n�� ���� Ȯ����
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != first) { // ���� �ٸ��ٸ�
				same = false; // false
				break; 
			}
		}
			if (same) // ���� ���ٸ�
			{
				output[first + 1]++; // first = Ŀ�� ���� +1�Ͽ� 0 / 1 / 2�� ġȯ�Ͽ� ��
			}
			else { // ���� �ʴٸ�
				for (int i = x; i < x + n; i += n / 3) // 3x3���� ���� �� Ŀ�� ��ġ��  check�� �ְ� ��
					for (int j = y; j < y + n; j += n / 3)
					{ 
						check(i, j, n / 3);
					}
			}
		}
int main()
{
	int n; // �Է¹޴� ����� ����
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	check(0, 0, n);
	cout << output[0] << "\n";
	cout << output[1] << "\n";
	cout << output[2] << "\n";

}