#include<iostream>
using namespace std;

int arr[45];

void init()
{
	for (int i = 1; i < 45; i++) {

		arr[i - 1] = i * (i + 1) / 2; //  �ﰢ���� �迭�� �����Ѵ�.
	}
}


bool find(int num) {   // ���� �ð��� 1���ε� 1�ʿ��� 1����� ������ �� �� �ִ�.  44 *44 *44�� 1��� �̳�
	               

	for (int a = 0; a < 44; a++) {
		for (int b = 0; b < 44; b++) {
			for (int c = 0; c < 44; c++) {

				if (num == arr[a] + arr[b] + arr[c])
					return  true;
				
			}
		}
	}

	return false;
}




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(false); cout.tie(false);

	

	int T;  int num;
	cin >> T;
	init();
	for (int i = 0; i < T; i++) {

		cin >> num;
		if (find(num))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

	}
	

	//system("pause");
	return 0;
}