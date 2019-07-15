#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	int score;
	double average = 0;
	int max = -1;
	for (int i = 0; i < N; i++) {
		cin >> score;
		average += score;
		if (max < score)
			max = score;
	}

	average = average / max * 100;
	average = average / N;

	cout << average;
	return 0;
}