#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//string s;
//vector<int>arr(26, 0);  // 알파벳 A부터 Z까지
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
//		if (++arr[s[i] - 'A'] > max) // ++을 앞에 붙인것이 핵심  뒤에붙이면  연산순서때문에 꼬인다.
//			max = arr[s[i] - 'A'];
//		maxindex = i;
//
//	}
//
//	// 여기 까지 하면  알파벳이 쓰인 개수가 벡터에 저장된다.  -> 정렬을 해주자
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

// 위의 예시는 STL을 많이 활용하지 않았을 때의 코드이다
// 다음 코드는 STL   map을 활용 한 코드이다.


string s;
map<char, int>m;
map<char, int>::iterator it;

int main(void)
{
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		// 소문자인 경우에는 대문자로 바꾸어서 넣어준다. 대문자가 아스키 코드값이 더크다.
		if (s[i] >= 'a') {
			s[i] -= ('a' - 'A');
		}

		// 기존에 존재 하는 값인지  검사.
		it = m.find(s[i]);

		if (it != m.end()) // end가 가리키는 곳은 문자열의 끝 다음부분, 만약 있으면 +1
			m[it->first] += 1;
		else // 처음 가리키는 거면  1로 셋팅
			m[s[i]] = 1;
	}
	

	//횟수가 가장 많은 값을 가리키는 반복자를 찾는다.

	map<char, int>::iterator max_iter = m.begin();
	it = m.begin()++;
	for (; it != m.end(); it++) {
		
		if (max_iter->second < it->second) {
			max_iter = it;
		}

	}

	//max인 횟수와 같은 횟수가 존재하고  그 인자의 key가 동일한지 검사한다.

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
