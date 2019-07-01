#include <iostream>
using namespace std;
int arr[8]; // ������ ����
bool check[8] = { false }; // true ����ߴ�.  false �����ߴ�.
int N, M;   // N������ ������ �ߺ�����  M���� ����

void go(int k, int n, int m) {

	// ���� ������ ���̰� k�� M�� �Ǹ� ������ ����Ѵ�.

	if (k == m) {

		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//1���� ������ ����  ���ڸ� Ȯ���Ͽ� arr�� �ְ�  ���� �Լ��� ȣ���ϴ� �ݺ���

	for (int i = 1; i <= n; i++) {

		//check[i]�� true �� �����ٴ� ���̱� ������ continue
		if (check[i] == true)
			continue;

		// ���� ���ǹ��� ��������� ���� �Ⱦ����ٴ� �ǹ�

		arr[k] = i;
		check[i] = true;
		go(k + 1, n, m);

		// ��� ȣ�⿡�� return ���� ���ƿ���  �ٽ� ����
		// 1 2 3 ������  1 2 4 �� �� �� �ֵ��� 

		check[i] = false; // ��� ���� �ٽ� false��  ����
	}
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	go(0, N, M);

	//system("pause");
	return 0;
}