#include<iostream>
using namespace std;

int main(void)
{
	int nownum;
	int findnum;
	int changenum;
	int first;
	int a, b;  // a�� �ٲ� ������ ����   b�� �ٲٰ� ���� ���ǰ���

	cin >> nownum >> findnum >> changenum;

	a = (nownum + findnum) / changenum;
	b = (nownum + findnum) % changenum;

	first = a; // �ٲ� ������ ����

	while (a + b >= changenum)
	{
		a = (a + b) / changenum;
		b = (a + b) % changenum;
		first += a;
	}

	cout <<  first;
	//system("pause");
    
	return 0;
}