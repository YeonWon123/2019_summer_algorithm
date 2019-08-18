#include <iostream>
#include <vector>
using namespace std;

vector<int> save;

int main(void)
{
	int a;
	cin >> a;
	save.push_back(a);

	while (1) {

		int size = save.size();
		a = save[size - 1];

		int b = 0;

		while (1) {
			if (a == 0) break;
			else {
				b += (a % 10) * (a % 10);
				a = a / 10;
			}
		}

		if (b == 1) {
			cout << "HAPPY";
			return 0;
		}
		else {
			for (int i = 0; i < save.size(); i++) {
				if (save[i] == b) {
					cout << "UNHAPPY";
					return 0;
				}
			}
			save.push_back(b);
		}
	}

	return 0;
}