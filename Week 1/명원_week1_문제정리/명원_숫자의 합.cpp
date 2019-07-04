#include<iostream>
using namespace std;



int main(void)
{
	int N; // 숫자의 개수
	char num;
	int temp;  int sum = 0;

	cin >> N;
	cin.get(); // cin을 하고 엔터를 누름으로써 버퍼에 남는다.  따라서 버퍼제거용
	           // 만일 scanf로 쓸 경우 getchar()로 버퍼를 제거 해주면 된다.
	// 아니면 char 배열을 선언해주어 입력을 받아도 된다.

	for (int i = 0; i < N; i++)
	{
		cin.get(num);
		temp =   num - '0';// char형의 num을 int형으로 바꾸기 위해
		sum += temp;
	}


	cout << sum;

	//system("pause");
	return 0;
}