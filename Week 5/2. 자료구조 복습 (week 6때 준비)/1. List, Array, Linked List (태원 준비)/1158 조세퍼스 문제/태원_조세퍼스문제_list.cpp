#include <iostream>
#include <list>
using namespace std;
int n, k, save;
list <int> l;
int josep[5001];
void josepus()
{
	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}
	int j = n;
	while (j > 0) {
		for (int i = 1; i < k; i++)
		{
			save = l.front();
			l.pop_front();
			l.push_back(save);
		}
		josep[n - j] = l.front();
		l.pop_front();
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

