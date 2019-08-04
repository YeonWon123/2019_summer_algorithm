#include<iostream>
#include<cstring>
using namespace std;


int N;
int arr[128][128];
int white = 0;  int blue = 0;

// �Ͼ���� 0  �Ķ����� 1   


void recursion(int x, int y, int N);


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	cin >> N;

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> arr[i][j];
		}
	}


	recursion(0, 0, N);

	cout << white << "\n";
	cout << blue << "\n";


	//system("pause");
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
				
				sw = 1; break;
			}
		}

		if (sw == 1) break;
	}

	

	if (sw == 1) { // ������ ���� �ʴٸ�

		int newN = N / 2;
		
		recursion(x, y, newN);  //cout << "recursion 1 ����" << "\n"; // ���� ��
		recursion(x + newN, y, newN); //cout << "recursion 2 ����" << "\n"; // ������ ��
		recursion(x, y + newN, newN);// cout << "recursion 3 ����" << "\n";// ���� �Ʒ�
		recursion(x + newN, y + newN, newN); //cout << "recursion 4 ����" << "\n"; // ������ �Ʒ�

		
	}

	else
	{
		
		if (arr[y][x] == 0)
		{
			white++;  //cout << "white �߰�" << "\n";
			return;
		}

		else
		{
			blue++;  //cout << "ble �߰�" << "\n";
			return;
		}
	}

}
