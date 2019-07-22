#include<iostream>
using namespace std;

int arr[45];

void init()
{
	for (int i = 1; i < 45; i++) {

		arr[i - 1] = i * (i + 1) / 2; //  삼각수를 배열에 저장한다.
	}
}


bool find(int num) {   // 제한 시간이 1초인데 1초에는 1억번의 연산을 할 수 있다.  44 *44 *44는 1억번 이내
	               

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