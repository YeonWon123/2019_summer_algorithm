#include<iostream>
using namespace std;

int N;
char num;

int main(void)
{
	int sum = 0;
	int temp;
	cin >> N;
	cin.get(); //�������� "\n" �����ֱ� ����  // cin.get()�� ���� �ϳ��� �Է¹ޱ� ���� ���

	for (int i = 0; i < N; i++) {

		cin.get(num);
		temp = num - '0';
		sum += temp;
	}
	
	cout << sum;
	//system("pause");
	return 0;
}