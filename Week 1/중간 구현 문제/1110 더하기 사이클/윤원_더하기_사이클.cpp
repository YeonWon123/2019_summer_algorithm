#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input;
	int answer = 0;
	cin >> input;
	int original = input;

	while (!(original == input && answer != 0)) {
		int temp = input % 10 * 10;
		input = input / 10 + input % 10;
		input = temp + input % 10;
		answer++;
	}
	cout << answer;
	return 0;
}