#include <iostream>
#include <iomanip>
using namespace std;

int d[501];

int** minmult(int n, int *d); // P�� �����迭�� ����
int minimum(int i, int j, int **M, int *d, bool bo);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	// �� ����� �� ������ �Է¹޴´�.
	// ��, ù ��° ����� ��� �� ������ �Է¹޴´�.
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

	// Mfinal 2���� �迭(=���� ������)�� n+1�� ũ�⸸ŭ �����Ҵ�
	int **arrs = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		arrs[i] = new int[n + 1];

   	arrs = minmult(n, d);
	cout << arrs[1][n];
}

// Algorithm 3.6 Minimum Multiplications (�ּ� ����)
// ���� : ��� n���� ���ϴµ� �ʿ��� ���Ҵ��� ������ �ּ� Ƚ���� 
//        �ּ� Ƚ���� ��� ������ �ϴ� ������ ���Ͻÿ�.
// �Է� : n(����� ����), �ε����� ������ 0���� n������ ���� �迭 d, ���⼭ d[i-1]*d[i]��
//	      i��° ����� ũ�Ⱑ �ȴ�.
// ��� : minmult(n�� ����� ���ϴµ� �ʿ��� ���Ҵ��� ������ �ּ� Ƚ��)
//        P(������ ������ ���� �� �ִ� ������ �迭)
//       ���⼭ P�� ���� �ε����� 1���� n-1�����̰�, ���� �ε����� 1���� n�����̴�.
//       P[i][j]�� ���� i���� j���� ����� ���� �� ������ ������ �������� ������ ��Ÿ����.
int** minmult(int n, int *d) // P�� �����迭�� ����
{
	int i, j, k, diagonal;

	// 0���� n������ ���� �迭 ����, ���� ����� 1���� n������ ����� ����
	int **M = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		M[i] = new int[n + 1];

	// 1���� n���� i�� ������ �ְ�, M[i][i]�� ���� 0���� �����.
	for (i = 1; i < n + 1; i++)
		M[i][i] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++)  // diagonal-1�� �� �밢����
		for (i = 1; i <= n - diagonal; i++) {		   // �ٷ� ���� �ִ�
			j = i + diagonal;						   // �밢���� �ǹ��Ѵ�.
			M[i][j] = minimum(i, j, M, d, true);       // i <= k <= j-1
		}

	return M;
}

// minimum �Լ� : Algorithm 3.6 Minimum Multiplications (�ּ� ����) �� ȣ��Ǵ� �Լ�
int minimum(int i, int j, int **M, int *d, bool bo)
{
	int k = i;
	int k_min = i;

	/* Ȯ�ο� �ڵ�
	cout << "k_min�� ���� " << k << endl;
	cout << "M[i][k]�� ��: " << M[i][k] << endl;
	cout << "M[k+1][j]�� ��: " << M[k+1][j] << endl;
	cout << "d[i]d[k]d[j]�� ��: " << d[i - 1] * d[k] * d[j] << endl;
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