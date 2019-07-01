#include<iostream>
using namespace std;

int main(void)
{
	int nownum;
	int findnum;
	int changenum;
	int first;
	int a, b;  // a는 바꾼 새병의 개수   b는 바꾸고 남은 병의개수

	cin >> nownum >> findnum >> changenum;

	a = (nownum + findnum) / changenum;
	b = (nownum + findnum) % changenum;

	first = a; // 바꾼 새병의 개수

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