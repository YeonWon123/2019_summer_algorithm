#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nownum;
	int findnum;
	int changenum;
	int first;
	int a, b;  // a�� �ٲ� ������ ����   b�� �ٲٰ� ���� ���ǰ���

	cin >> nownum >> findnum >> changenum;

	a = (nownum + findnum) / changenum;
	b = (nownum + findnum) % changenum;

	first = a; // �ٲ� ������ ����

	while (b >= changenum)
	{
		int temp1, temp2;
		temp1 = (a + b) / changenum;
		temp2 = (a + b) % changenum;
		a = temp1; b = temp2;			
		first += a;
	}

	cout << first;
	//system("pause");
    
	return 0;
}