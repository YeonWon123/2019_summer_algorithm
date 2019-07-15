#include <cstdio>
using namespace std;

int main(void)
{
	int N;
	int sum = 0;

	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
		sum += i;

	printf("%d\n", sum);
}