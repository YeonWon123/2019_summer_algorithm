#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 10000;



int N;

vector<int> v;



int maxProduct(void)

{

	//두개

	int case1 = v[0] * v[N - 1]; //양 끝

	int case2 = v[N - 1] * v[N - 2]; //정렬했을 때 제일 큰 수 두개

	int case3 = v[0] * v[1]; //정렬했을 때 제일 작은 수 두개

	//세개

	int case4 = v[N - 1] * v[N - 2] * v[N - 3]; //정렬했을 때 큰 수 세개

	int case5 = v[0] * v[1] * v[2]; //정렬했을 때 작은 수 세개

	int case6 = v[0] * v[N - 1] * v[N - 2]; //제일 작은 수, 큰 수 두개

	int case7 = v[0] * v[1] * v[N - 1]; //작은 수 두개, 제일 큰 수



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



