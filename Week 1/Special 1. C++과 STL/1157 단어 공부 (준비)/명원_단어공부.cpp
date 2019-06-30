#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<int>arr(26, 0);  // 알파벳 A 부터  Z까지   알파벳 개수 26개

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int max = -1;
	int maxindex = -1;

	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);
		if (++arr[s[i] - 'A'] > max) {
			max = arr[s[i] - 'A'];
			maxindex = i;
		}

	}

	sort(arr.begin(), arr.end());

	if (arr[24] == arr[25]) cout << "?" << endl;
	else cout << s[maxindex] << endl;

	//system("pause");
	return 0;
}