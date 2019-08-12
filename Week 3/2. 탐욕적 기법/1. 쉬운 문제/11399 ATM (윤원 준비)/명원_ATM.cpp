#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	int N;
	int arr[1000] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];  
	}

	sort(arr, arr + N);



	int sum[1000] = { 0 };  int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {

			sum[i] = sum[i] + arr[j];
		}
		answer += sum[i];
	}




	
	cout << answer;

	//system("pause");
	return 0;
}