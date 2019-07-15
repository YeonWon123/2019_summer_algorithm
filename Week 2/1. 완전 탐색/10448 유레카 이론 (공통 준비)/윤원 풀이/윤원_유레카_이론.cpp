#include <iostream>
using namespace std;

// �ﰢ���� �����ϴ� �迭�� �ﰢ���� ������ �����ϴ� ����
int arr[1000];
int index = 0;

// �ﰢ���� ���ϴ� �Լ�
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

	// �ﰢ���� ���ϴ� �κ�
	getThreeNum();

	// �Է¹޴� �κ�
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;

		int sw = 0;
		// ���ڰ� �ﰢ������ �ƴ��� �Ǵ�
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