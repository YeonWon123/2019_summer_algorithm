#include <cstdio>
using namespace std;

int main(void)
{
	int e, f, c;
	scanf("%d %d %d", &e, &f, &c);

	int empty = e + f;
	int answer = 0;
	answer = empty / c;

	int now = answer + empty % c;
	while (now >= c) {
		answer += now / c;
		now = now / c + now % c;
	}

	printf("%d", answer);
}