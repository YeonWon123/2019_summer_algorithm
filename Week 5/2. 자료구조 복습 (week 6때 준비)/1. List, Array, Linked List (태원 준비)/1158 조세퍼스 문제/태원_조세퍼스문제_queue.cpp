#include <iostream>
#include <queue>
using namespace std;
int n, k, save;
queue<int> q;
int josep[5001];
void josepus()
{
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int j = n;
	while (j > 0) {
		for (int i = 1; i < k; i++)
		{
			save = q.front();
			q.pop();
			q.push(save);
		}
		josep[n - j] = q.front();
		q.pop();
		j--;
	}
}
int main()
{
	cin >> n >> k;
	josepus();
	cout << "<" << josep[0];
	if (n > 1) {
		cout << ",";
		for (int i = 1; i < n - 1; i++)
			cout << " " << josep[i] << ",";
		cout << " " << josep[n - 1] << ">";
	}
	else
	{
		cout << ">";
	}
	return 0;
}

