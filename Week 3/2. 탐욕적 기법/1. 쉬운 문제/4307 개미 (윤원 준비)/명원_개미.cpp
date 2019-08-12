#include<iostream>
#include<algorithm>
using namespace std;


int length, n, number;



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {

		cin >> length >> n;

		int mintime = 0, maxtime = 0;

		for(int i=0; i < n;i++){


			cin >> number;

			int antMin = min(number, length - number);
			int antMax = max(number, length - number);

			mintime = max(antMin, mintime);
			maxtime = max(antMax, maxtime);

		}


		cout << mintime << " " << maxtime << "\n";

	}


	system("pause");
	return 0;
}