#include<iostream>
#include<string>
using namespace std;

int arr[1000000] = { 0 };
int findnum(int num);

int main(void)
{
	int N; int answer;
	cin >> N;

	for (int i = 1; i <= N; i++) { // ���� ���� �����ڸ� ���ϴ� ��

		if (findnum(i) == N)
		{
			answer = i;
			break;
		}

		else
			answer = 0;
	}
   
	
		cout << answer;
	
	//system("pause");
	return 0;
}



int  findnum(int num)
{
	int sum = 0; // �� �ڸ����� ��
	string object = to_string(num);

	for (int i = 0; i < object.length(); i++) {

		arr[i] = object[i] - '0';
		sum += arr[i];
	}

	return sum + num;

}
