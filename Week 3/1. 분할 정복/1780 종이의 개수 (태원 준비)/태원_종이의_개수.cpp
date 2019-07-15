#include <iostream>

using namespace std;
int output[3]; // -1,0,1을 카운트하기 위한 크기 3의 int형 배열 선언
int arr[2187][2187]; // n은 최대 3^7 = 2187까지 가능함
void check(int x, int y, int n) // 같은 값이 들어있는지 확인하는 함수
{// 매개변수는 시작하는 x, y 커서좌표가 들어오고 n은 값 비교할 범위
	int first = arr[x][y]; // 첫번째 커서에 들어있는 값을 저장
	bool same = true; // 같은 수인지 확인하기 위해 bool변수선언

	for (int i = x; i < x + n; i++) // n*n의 값을 확인함
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != first) { // 만약 다르다면
				same = false; // false
				break; 
			}
		}
			if (same) // 만약 같다면
			{
				output[first + 1]++; // first = 커서 값에 +1하여 0 / 1 / 2로 치환하여 비교
			}
			else { // 같지 않다면
				for (int i = x; i < x + n; i += n / 3) // 3x3으로 나눈 각 커서 위치를  check에 넣고 비교
					for (int j = y; j < y + n; j += n / 3)
					{ 
						check(i, j, n / 3);
					}
			}
		}
int main()
{
	int n; // 입력받는 행렬의 개수
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	check(0, 0, n);
	cout << output[0] << "\n";
	cout << output[1] << "\n";
	cout << output[2] << "\n";

}