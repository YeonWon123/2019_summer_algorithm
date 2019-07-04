#include <iostream>
#include <set>
#include <string>
using namespace std;

int N;
set<pair<long, string>>s;
set<pair<long, string>>::iterator iter;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;
	string str;

	for (int i = 0; i < N; i++) {

		cin >> str;
		s.insert(make_pair(str.length(), str)); // 길이와 문자열을 set에 저장한다.
		                                        // 1.길이가 짧은 것부터 2.길이가 같으면 사전순
		// bsT 이므로  먼저 길이를 비교하고  길이가 같으면 사전순으로 bst순으로 정렬을 한다.
	}

	for (iter = s.begin(); iter != s.end(); iter++) {

		cout << iter->second << "\n";
	}



	//system("pause");
	return 0;
}
// 1.set안에  pair을 사용했단 점
// 2. set을 써서  <숫자,이름> 해줌으로써 숫자를 우선순위 비교로 두고 다음이 문자열의 길이로 했다는 점
// 3. pair을 생성할 때는 make_pair<변수,변수> 인점
// 4. set의 iterator 을 사용한다는 점      등등을 익히는데 도움이 되는 문제인 것 같다.
// pair<int, int> p1;
// p1 = make_pair(10, 20);


