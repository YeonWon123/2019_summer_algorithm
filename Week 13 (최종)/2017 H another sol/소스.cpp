#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 10000;



int N;

vector<int> v;



int maxProduct(void)

{

	//�ΰ�

	int case1 = v[0] * v[N - 1]; //�� ��

	int case2 = v[N - 1] * v[N - 2]; //�������� �� ���� ū �� �ΰ�

	int case3 = v[0] * v[1]; //�������� �� ���� ���� �� �ΰ�

	//����

	int case4 = v[N - 1] * v[N - 2] * v[N - 3]; //�������� �� ū �� ����

	int case5 = v[0] * v[1] * v[2]; //�������� �� ���� �� ����

	int case6 = v[0] * v[N - 1] * v[N - 2]; //���� ���� ��, ū �� �ΰ�

	int case7 = v[0] * v[1] * v[N - 1]; //���� �� �ΰ�, ���� ū ��



	return max({ case1, case2, case3, case4, case5, case6, case7 });

}



int main(void)

{

	cin >> N;



	for (int i = 0; i < N; i++)

	{

		int temp;

		cin >> temp;

		v.push_back(temp);

	}



	sort(v.begin(), v.end());



	cout << maxProduct() << endl;

	return 0;

}



