#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, R;
vector<int>arr;

void print_array() {

	for (int i = 0; i < R; ++i) {

		cout << arr[i] << " ";
	}
	cout << "\n";
}



int main(void)
{

	cin >> N >> R;
	for (int i = 1; i <= N; ++i) {
		arr.push_back(i);
	}

	do {
		print_array();
		reverse(arr.begin() + R, arr.end());  // 주의  
	} while (next_permutation(arr.begin(), arr.end())); // next_permutation은 지금 수의 다음순열 
	                                                    // 마지막 순열이면 false 반환
	//system("pause");
	return 0;
}