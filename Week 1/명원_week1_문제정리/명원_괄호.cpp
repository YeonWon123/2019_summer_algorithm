#include<iostream>
#include<string>
#include<stack>
using namespace std;


//int main(void)
//{
//	int T;  
//	cin >> T;
//	string str;
//
//	for (int i = 0; i < T; i++) // testcase T개 입력
//	{
//		int sum = 0;
//		int sw = 0;
//
//		cin >> str;
//
//		for (int j = 0; j < str.length(); j++)
//		{
//			if (str[j] == '(') sum++;
//			
//			else if (str[j] == ')')sum--;
//
//			if (sum < 0)
//				sw = 1;
//		}
//		
//
//		if (sw == 0 && sum == 0) {
//			cout << "YES" << "\n";
//		}
//		else
//			cout << "No" << "\n";
//	}
//
//	system("pause");
//	return 0;
//}


// 위에는 윤원이의 방식으로 푼 괄호 문제 구현이다.
// 인터넷을 찾아보니  stack을 써서 활용한 코드가 있어 가져와 본다.
// 만일 1. (가 쓰일 경우 stack에 push  2. stack내부에  여는 괄호가 있다. -> pop, 없다->false
// 3.문자열을 다 확인했는데  스택 내부에 여는 괄호가 있다 ->false


bool check(string str) {

	int len = (int)str.length(); // 문자열 길이
	stack<char>st;

	for (int i = 0; i < len; i++) {

		char c = str[i];

		if (c == '(') {
			st.push(str[i]);
		}

		else {  // 닫는 괄호일 때

			if (!st.empty()) // 비어 있지 않다면, 즉 여는 괄호가 스택에 들어있다면
				st.pop();
			else // 스택이 비어있다면
				return false;

		}
	}

	// 반복문이 끝나고 스택에 괄호가 남아있다면 false
	return st.empty();

}

int main(void)
{

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (check(str))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	//system("pause");
	return 0;
}