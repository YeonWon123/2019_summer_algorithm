#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<int>arr(26, 0); 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	int max = -1;
	int maxIndex = -1;
	for (int i = 0; i < s.length(); i++)
	{
		 s[i] = toupper(s[i]);
		 ++arr[s[i] - 'A'];
		 if (arr[s[i] - 'A'] > max) {
			 max = arr[s[i] - 'A'];
			 maxIndex = i;
		 }
	}
	sort(arr.begin(), arr.end());
	if (arr[24] == arr[25])
	{
		cout << "?";
	}
	else
		cout << s[maxIndex];
	return 0;
}