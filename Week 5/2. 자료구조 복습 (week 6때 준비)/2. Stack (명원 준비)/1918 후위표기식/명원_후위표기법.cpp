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

			case'/':  // �켱���� ���� �����Ƿ� ���� ��ȣ�� pop

				while (!s.empty() && (s.top() == '*' || s.top() == '/')) // (�� ���ÿ� ������ 
				{                                            // �ƹ��� ���ϱ� ������� (�Ⱥ��� �ؾ��Ѵ�
					result += s.top();                       // ���� ( �� ���ÿ� ������  *�� /�� ����push
					s.pop();

				}
				s.push(object[i]);
				break;


			case '+':
			case '-':

				while (!s.empty() && s.top() != '(') // �켱������ �����Ƿ� ���ÿ�  * / + - �� ���� ����ص� 
					                                 // �������. �� ���� top �� ���ΰ� ���� ��� ���ξ���
					                                 // ������� �����ؾ� �Ѵ�.
				{

					result += s.top();
					s.pop();
				}
				s.push(object[i]);
				break;



			case')':  while (!s.empty() && s.top() != '(') { // )ǥ�ô� �ٳ����ٴ� �ǹ��̹Ƿ�  �� push �ؼ� 
				                                             // result �� �ִ´�.
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