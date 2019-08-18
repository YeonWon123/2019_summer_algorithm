#include<iostream>
#include<stack>
#include<string>

using namespace std;

string object;
stack<char>s;
string result;

int cnt = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	cin >> object;

	for (int i = 0; i < object.size(); i++) {

		if ('A' <= object[i] && object[i] <= 'Z')
			result += object[i];

		else {

			switch (object[i]) {


			case '(': s.push(object[i]);
				break;

			case '*':

			case'/':  // 우선순위 제일 높으므로 같은 기호들 pop

				while (!s.empty() && (s.top() == '*' || s.top() == '/')) // (가 스택에 있으면 
				{                                            // 아무리 곱하기 나누기라도 (안부터 해야한다
					result += s.top();                       // 따라서 ( 가 스택에 있으면  *나 /를 스택push
					s.pop();

				}
				s.push(object[i]);
				break;


			case '+':
			case '-':

				while (!s.empty() && s.top() != '(') // 우선순위가 낮으므로 스택에  * / + - 다 먼저 계산해도 
					                                 // 상관없다. 단 스택 top 에 가로가 있을 경우 가로안의
					                                 // 연산부터 수행해야 한다.
				{

					result += s.top();
					s.pop();
				}
				s.push(object[i]);
				break;



			case')':  while (!s.empty() && s.top() != '(') { // )표시는 다끝났다는 의미이므로  다 push 해서 
				                                             // result 에 넣는다.
				result += s.top();
				s.pop();
			}
					  s.pop();
					  break;
			}
		}


	}
	



	while (!s.empty()) {

		result += s.top();
		s.pop();
	}



	cout << result << "\n";



	//system("pause");
	return 0;
}