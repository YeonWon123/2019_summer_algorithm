#include <iostream>
using namespace std;
int arr[8]; // 수열을 저장
bool check[8] = { false }; // true 사용했다.  false 사용안했다.
int N, M;   // N이하의 숫자중 중복없이  M개를 선택

void go(int k, int n, int m) {

	// 현재 수열의 길이가 k가 M이 되면 수열을 출력한다.

	if (k == m) {

		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//1부터 쓰이지 않은  숫자를 확인하여 arr에 넣고  다음 함수를 호출하는 반복문

	for (int i = 1; i <= n; i++) {

		//check[i]가 true 면 쓰였다는 뜻이기 때문에 continue
		if (check[i] == true)
			continue;

		// 위의 조건문을 통과했으면 아직 안쓰였다는 의미

		arr[k] = i;
		check[i] = true;
		go(k + 1, n, m);

		// 재귀 호출에서 return 으로 돌아오면  다시 셋팅
		// 1 2 3 다음에  1 2 4 가 올 수 있도록 

		check[i] = false; // 썼던 수를 다시 false로  셋팅
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