#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[501][501];
int result[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// ют╥б
	cin >> N;

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= i; j++) {

			cin >> arr[i][j];

		}
	}


	for (int i = 2; i <= N; i++) {

		for (int j = 1; j <= i; j++) {


			if (j == 1)
				arr[i][j] = arr[i][j] + arr[i - 1][j];

			else if (j == i)
				arr[i][j] = arr[i][j] + arr[i - 1][j - 1];


			else
				arr[i][j] = arr[i][j] + max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
   }


	for (int i = 1; i <= N; i++)
	{
		result[i] = arr[N][i];
		
	}

	sort(result + 1, result + N+1);

	

	cout << result[N];



    //system("pause");
	return 0;
}