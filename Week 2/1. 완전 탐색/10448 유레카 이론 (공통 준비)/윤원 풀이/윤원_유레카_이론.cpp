#include <iostream>
using namespace std;

// 삼각수를 저장하는 배열과 삼각수의 개수를 저장하는 정수
int arr[1000];
int index = 0;

// 삼각수를 구하는 함수
void getThreeNum() {
	int number = 1;
	while (number <= 1000) {
		arr[index] = number;
		number += index + 2;
		index++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 삼각수를 구하는 부분
	getThreeNum();

	// 입력받는 부분
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;

		int sw = 0;
		// 숫자가 삼각수인지 아닌지 판단
		for (int i = 0; i < index && sw == 0; i++) {
			for (int j = 0; j < index && sw == 0; j++) {
				for (int k = 0; k < index && sw == 0; k++) {
					if (arr[i] + arr[j] + arr[k] == num) {
						sw = 1;
						break;
					}
				}
			}
		}

		if (sw == 1)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}