#include<iostream>
using namespace std;

int N;
char num;

int main(void)
{
	int sum = 0;
	int temp;
	cin >> N;
	cin.get(); //마지막에 "\n" 지워주기 위해  // cin.get()는 문자 하나를 입력받기 위해 사용

	for (int i = 0; i < N; i++) {

		cin.get(num);
		temp = num - '0';
		sum += temp;
	}
	
	cout << sum;
	//system("pause");
	return 0;
}