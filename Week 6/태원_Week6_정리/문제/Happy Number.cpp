//Happy number
#include <iostream>
#include <string>
using namespace std;
int a[13];
string s;
int n, sum, t;
void happy()
{
	for (int i = 0; i < s.length(); i++)
	{
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < s.length(); i++)
	{
		t = a[i];
		sum += t * t;
	}
	if (sum == 4 || sum == 16 || sum == 37 || sum == 58 || sum == 89 || sum == 145 || sum == 42 || sum == 20)
	{
		cout << "UNHAPPY" << "\n";
		return;
	}
	else
	{
		while (1)
		{
			s = to_string(sum);
			sum = 0;
			for (int i = 0; i < s.length(); i++)
			{
				a[i] = s[i] - '0';
			}
			for (int i = 0; i < s.length(); i++)
			{
				t = a[i];
				sum += t * t;
			}
			if (sum == 4 || sum == 16 || sum == 37 || sum == 58 || sum == 89 || sum == 145 || sum == 42 || sum == 20)
			{
				cout << "UNHAPPY" << "\n";
				return;
			}
			else if (sum == 1)
			{
				cout << "HAPPY" << "\n";
				return;
			}
		}
	}


}

int main()
{
	
	cin >> s;
	happy();

	return 0;

}
