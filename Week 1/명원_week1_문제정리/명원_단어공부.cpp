#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//string s;
//vector<int>arr(26, 0);  // ���ĺ� A���� Z����
//
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(false); cout.tie(false);
//
//	cin >> s;
//	int max = -1;  int maxindex = -1;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		s[i] = toupper(s[i]);
//		if (++arr[s[i] - 'A'] > max) // ++�� �տ� ���ΰ��� �ٽ�  �ڿ����̸�  ������������� ���δ�.
//			max = arr[s[i] - 'A'];
//		maxindex = i;
//
//	}
//
//	// ���� ���� �ϸ�  ���ĺ��� ���� ������ ���Ϳ� ����ȴ�.  -> ������ ������
//
//	sort(arr.begin(), arr.end());
//
//	if (arr[24] == arr[25])
//		cout << "?" << "\n";
//	else
//		cout << s[25];
//
//	system("pause");
//
//	return 0;
//}

// ���� ���ô� STL�� ���� Ȱ������ �ʾ��� ���� �ڵ��̴�
// ���� �ڵ�� STL   map�� Ȱ�� �� �ڵ��̴�.


string s;
map<char, int>m;
map<char, int>::iterator it;

int main(void)
{
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		// �ҹ����� ��쿡�� �빮�ڷ� �ٲپ �־��ش�. �빮�ڰ� �ƽ�Ű �ڵ尪�� ��ũ��.
		if (s[i] >= 'a') {
			s[i] -= ('a' - 'A');
		}

		// ������ ���� �ϴ� ������  �˻�.
		it = m.find(s[i]);

		if (it != m.end()) // end�� ����Ű�� ���� ���ڿ��� �� �����κ�, ���� ������ +1
			m[it->first] += 1;
		else // ó�� ����Ű�� �Ÿ�  1�� ����
			m[s[i]] = 1;
	}
	

	//Ƚ���� ���� ���� ���� ����Ű�� �ݺ��ڸ� ã�´�.

	map<char, int>::iterator max_iter = m.begin();
	it = m.begin()++;
	for (; it != m.end(); it++) {
		
		if (max_iter->second < it->second) {
			max_iter = it;
		}

	}

	//max�� Ƚ���� ���� Ƚ���� �����ϰ�  �� ������ key�� �������� �˻��Ѵ�.

	for (it = m.begin(); it != m.end(); it++) {
		if (max_iter->second == it->second && max_iter->first != it->first) {

			cout << "?";
			return 0;
		}

	}

	cout << max_iter->first;

	//system("pause");
	return 0;
}
