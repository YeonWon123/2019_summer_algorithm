#include<iostream>
using namespace std;



int main(void)
{
	int N; // ������ ����
	char num;
	int temp;  int sum = 0;

	cin >> N;
	cin.get(); // cin�� �ϰ� ���͸� �������ν� ���ۿ� ���´�.  ���� �������ſ�
	           // ���� scanf�� �� ��� getchar()�� ���۸� ���� ���ָ� �ȴ�.
	// �ƴϸ� char �迭�� �������־� �Է��� �޾Ƶ� �ȴ�.

	for (int i = 0; i < N; i++)
	{
		cin.get(num);
		temp =   num - '0';// char���� num�� int������ �ٲٱ� ����
		sum += temp;
	}


	cout << sum;

	//system("pause");
	return 0;
}