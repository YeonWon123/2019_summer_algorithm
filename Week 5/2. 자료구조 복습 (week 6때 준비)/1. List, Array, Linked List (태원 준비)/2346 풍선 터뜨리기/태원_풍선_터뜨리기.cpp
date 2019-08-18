#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;
int n, k, save, count;
list<int> l;
int inputValue[1001];
void ballun()
{

	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}

	cout << l.front() << " ";
	save = inputValue[l.front()];
	l.erase(l.begin());
	while (l.empty() != true)
	{
		//cout << *l.begin() << "\n";
		if (save > 0)
		{
			for (int i = 0; i < save - 1; i++)
			{
				l.push_back(l.front());
				l.erase(l.begin());
			}
		}
		else
		{
			for (int i = 0; i < abs(save) ; i++)
			{
				l.push_front(l.back());
				l.erase(--l.end());
			}
		}
		cout << l.front() << " ";
		save = inputValue[l.front()];
		l.erase(l.begin());
	}
}
int main()
{

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> inputValue[i];

	ballun();

	return 0;
}

