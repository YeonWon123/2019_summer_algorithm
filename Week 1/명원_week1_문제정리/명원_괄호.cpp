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
//	for (int i = 0; i < T; i++) // testcase T�� �Է�
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


// ������ �������� ������� Ǭ ��ȣ ���� �����̴�.
// ���ͳ��� ã�ƺ���  stack�� �Ἥ Ȱ���� �ڵ尡 �־� ������ ����.
// ���� 1. (�� ���� ��� stack�� push  2. stack���ο�  ���� ��ȣ�� �ִ�. -> pop, ����->false
// 3.���ڿ��� �� Ȯ���ߴµ�  ���� ���ο� ���� ��ȣ�� �ִ� ->false


bool check(string str) {

	int len = (int)str.length(); // ���ڿ� ����
	stack<char>st;

	for (int i = 0; i < len; i++) {

		char c = str[i];

		if (c == '(') {
			st.push(str[i]);
		}

		else {  // �ݴ� ��ȣ�� ��

			if (!st.empty()) // ��� ���� �ʴٸ�, �� ���� ��ȣ�� ���ÿ� ����ִٸ�
				st.pop();
			else // ������ ����ִٸ�
				return false;

		}
	}

	// �ݺ����� ������ ���ÿ� ��ȣ�� �����ִٸ� false
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