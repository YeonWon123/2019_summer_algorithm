#include <iostream>
#include <iomanip>
using namespace std;

int d[501];

int** minmult(int n, int *d); // P는 전역배열로 선언
int minimum(int i, int j, int **M, int *d, bool bo);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	// 각 행렬의 열 수만을 입력받는다.
	// 단, 첫 번째 행렬의 경우 행 수까지 입력받는다.
	for (int i = 0, j = 0; j < 2*n; ) {
		if (i == 0) {
			cin >> d[i];
			i++;
			cin >> d[i];
		}
		else {
			int temp;
			cin >> temp >> d[i];
		}
		i++;
		j = j + 2;
	}

	// Mfinal 2차원 배열(=이중 포인터)에 n+1의 크기만큼 동적할당
	int **arrs = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		arrs[i] = new int[n + 1];

   	arrs = minmult(n, d);
	cout << arrs[1][n];
}

// Algorithm 3.6 Minimum Multiplications (최소 곱셈)
// 문제 : 행렬 n개를 곱하는데 필요한 원소단위 곱셈의 최소 횟수와 
//        최소 횟수로 행렬 곱셈을 하는 순서를 구하시오.
// 입력 : n(행렬의 개수), 인덱스의 범위가 0부터 n까지인 정수 배열 d, 여기서 d[i-1]*d[i]는
//	      i번째 행렬의 크기가 된다.
// 출력 : minmult(n개 행렬을 곱하는데 필요한 원소단위 곱셈의 최소 횟수)
//        P(최적의 순서를 구할 수 있는 이차원 배열)
//       여기서 P의 행의 인덱스는 1부터 n-1까지이고, 열의 인덱스는 1부터 n까지이다.
//       P[i][j]의 값은 i부터 j까지 행렬을 곱할 떄 최적의 순서로 갈라지는 기점을 나타낸다.
int** minmult(int n, int *d) // P는 전역배열로 선언
{
	int i, j, k, diagonal;

	// 0부터 n까지의 동적 배열 생성, 실제 사용은 1부터 n까지만 사용할 예정
	int **M = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		M[i] = new int[n + 1];

	// 1부터 n까지 i의 범위에 넣고, M[i][i]의 값을 0으로 만든다.
	for (i = 1; i < n + 1; i++)
		M[i][i] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++)  // diagonal-1은 주 대각선의
		for (i = 1; i <= n - diagonal; i++) {		   // 바로 위에 있는
			j = i + diagonal;						   // 대각선을 의미한다.
			M[i][j] = minimum(i, j, M, d, true);       // i <= k <= j-1
		}

	return M;
}

// minimum 함수 : Algorithm 3.6 Minimum Multiplications (최소 곱셈) 중 호출되는 함수
int minimum(int i, int j, int **M, int *d, bool bo)
{
	int k = i;
	int k_min = i;

	/* 확인용 코드
	cout << "k_min의 값은 " << k << endl;
	cout << "M[i][k]의 값: " << M[i][k] << endl;
	cout << "M[k+1][j]의 값: " << M[k+1][j] << endl;
	cout << "d[i]d[k]d[j]의 값: " << d[i - 1] * d[k] * d[j] << endl;
	*/

	int min = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
	for (; k < j - 1; k++)
	{
		if (min > M[i][k + 1] + M[k + 2][j] + d[i - 1] * d[k + 1] * d[j])
		{
			min = M[i][k + 1] + M[k + 2][j] + d[i - 1] * d[k + 1] * d[j];
			k_min = k + 1;
		}
	}
	if (bo == true)
		return min;
	else
		return k_min;
}