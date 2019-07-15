#include <cstdio>
using namespace std;

int main(void)
{
	int N;
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		int sw = 0;
		char a[51];

		scanf("%s", a);

		int j = 0;
		while(1) {
			if (a[j] == '(')
				sum++;
			else if (a[j] == ')')
				sum--;
			else // 엔터키나 종료키
				break;

			j++;

			if (sum < 0) {
				sw = 1;
				break;
			}
		}

		if (sw == 0 && sum == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}