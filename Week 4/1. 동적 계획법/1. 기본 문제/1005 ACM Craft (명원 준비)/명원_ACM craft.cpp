#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

int N; //�ִ� 1000
int cache[1001];
int delay[1001];  //�ǹ� ���µ� �ɸ��� �ð�
int order[1001][1001]; // �ǹ� ��������



int TotalTime(int destination) {

	int &result = cache[destination];

	if (result != -1)
		return result;

	int time = 0;

	for (int i = 1; i <= N; i++)
	{
		if (order[i][destination])
			time = max(time, TotalTime(i));
		
	}

	return result = time + delay[destination];
}





int main(void)
{


	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		int K, D, X, Y;

		cin >> N >> K;

		for (int j = 1; j <= N; j++)
			cin >> delay[j];

		memset(cache, -1, sizeof(cache));
		memset(order, 0, sizeof(order));

		for (int i = 0; i < K; i++) {

			cin >> X >> Y;

			order[X][Y] = 1;
		}

		cin >> D;

		cout << TotalTime(D) << "\n";
		


	}
	

	//system("pause");
	return 0;
}