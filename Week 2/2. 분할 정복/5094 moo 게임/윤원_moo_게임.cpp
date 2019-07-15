#include <iostream>
using namespace std;

int N;
int counts = 0;

void moo(int now) {
	if (now == 1) {
		if (counts + 1 == N) {
			cout << "m";
			exit(0);
		}
		else if (counts + 2 == N || counts + 3 == N) {
			cout << "o";
			exit(0);
		}
		counts += 3;
		return;
	}
	
	moo(now - 1);

	if (counts + 1 == N) {
		cout << "m";
		exit(0);
	}

	counts++;

	for (int i = 0; i <= now; i++) {
		if (counts + 1 == N) {
			cout << "o";
			exit(0);
		}
		counts++;
	}

	moo(now - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	moo(30);
	return 0;
}