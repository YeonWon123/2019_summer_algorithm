#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int n, k;
int coin[101], cache[10001];



int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	memset(cache, 10001, sizeof(cache));
	cache[0] = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];

		for (int j = coin[i]; j <= k; j++) {

			cache[j] = min(cache[j], cache[j - coin[i]] + 1);

		}

	}

	if (cache[k] == 10001)  cout << -1;

	else
		cout << cache[k];



	system("pause");
	return 0;


}