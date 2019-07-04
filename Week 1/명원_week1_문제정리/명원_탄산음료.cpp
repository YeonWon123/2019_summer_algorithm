#include<iostream>
using namespace std;


int main(void)
{


	ios_base::sync_with_stdio(false);
	cin.tie(false); cout.tie(false);


	int e, f, c;  // e는 가지고 있는 빈병의수  ,f는  그날 발견한 빈병의수 ,c는 새병으로 바꾸는데 필요한병
	int a, b; // a는 바꾼 새병의수   b는 바꾸고 남은 병의수 ;
	int all = 0;// 결과적으로 총 바꾼 탄산음료 수

	cin >> e >> f >> c;

	a = (e + f) / c; // 바꾼 탄산음료 수
	b = (e + f) % c; // 남은 빈병의 개수 

	all = a;

	while (a + b >= c) {

		int temp1 = (a + b) / c;
		int temp2 = (a + b) % c;

		a = temp1; b = temp2;
		all += a;

	}


	cout << all;

	//system("pause");
	return 0;
}


// 우리가 나갈  대회의 기출 문제 1번
//  함정은  바꾸어서 얻은 탄산음료를 다시 빈병으로 활용 가능 하다는 점과 
//  바꾸고 남은 나머지 병들도 계속 보관하면서  바꾼 탄산음료수를  고려해주어야 한다는 점이 포인트