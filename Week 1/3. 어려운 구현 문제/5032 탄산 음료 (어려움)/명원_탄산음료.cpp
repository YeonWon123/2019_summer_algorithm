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
	int a, b;  // a는 바꾼 새병의 개수   b는 바꾸고 남은 병의개수

	cin >> nownum >> findnum >> changenum;

	a = (nownum + findnum) / changenum;
	b = (nownum + findnum) % changenum;

	first = a; // 바꾼 새병의 개수

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