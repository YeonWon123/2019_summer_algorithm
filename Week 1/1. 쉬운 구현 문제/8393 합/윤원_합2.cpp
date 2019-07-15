#include <cstdio>
using namespace std;
 
int main(void)
{
	int N, sum;
	scanf("%d", &N);
	sum = N * (N + 1) / 2;
	printf("%d\n", sum);
}