#include <cstdio>

int main(void)
{
	int N;
	int sum = 0;
	char input;
	scanf("%d", &N);
	getchar(); // ���� ���ſ�

	for (int i = 0; i < N; i++) {
		scanf("%c", &input);
		sum += input - '0';
	}

	printf("%d", sum);
}