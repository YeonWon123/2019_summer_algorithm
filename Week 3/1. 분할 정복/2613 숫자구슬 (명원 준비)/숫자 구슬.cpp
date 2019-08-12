#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int input[301];
int ans;



int possible(int value)
{
	int i, sum, cnt;

	for (i = 0, sum = 0, cnt = 1; i < N - 1; i++) {

		sum += input[i];
		if (sum > value) {

			cnt++;
			sum = input[i];

		}
	}
	
	if (sum + input[i] > value)   cnt++;

	if (cnt <= M) return 1;
	else return 0;
}



void bsearch()  // 그룹의 최댓값의 최솟값
{
	int left = 0, right = N * 100, middle;
	ans = right;

	while (left <= right) {

		middle = (left + right) / 2;
		if (possible(middle)) {

			right = middle - 1;
			if (middle < ans) ans = middle;

		}
		else
			left = middle + 1;


	}


}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, sum, cnt;

	cin >> N >> M;

	for (i = 0; i < N; i++) cin >> input[i];  // 입력

	bsearch();

	cout << ans << "\n";

	for (i = 0, sum = 0, cnt = 0; i < N; i++) {

		sum += input[i];
		if (sum > ans) {

			cout << cnt;
			sum = input[i];
			cnt = 0;

		}
		cnt++;
	}

	cout << cnt;
	system("pause");
	return 0;
}