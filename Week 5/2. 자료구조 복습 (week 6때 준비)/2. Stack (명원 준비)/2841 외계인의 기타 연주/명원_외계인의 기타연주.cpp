// ���� ���� �� ��    ** �ܰ����� �հ����� ���Ѱ��̴�.  ���� �ٸ� ���� ĥ�� �ٸ� �հ����� ����ϸ� �ȴ�.  

//7 15 
//1 5 = > 1ȸ 
//2 3 = > 1ȸ 
//2 5 = > 1ȸ 
//2 7 = > 1ȸ 
//2 4 = > 3ȸ = > 3��, 5�� �÷� ���� 4�� �÷� ���� 
//1 5 = > 1ȸ = > ��������. 
//1 3 = > 2ȸ = > 5�� �÷� ���� 3�� �÷� ����


// �˰���     ******  1.  ���� �ε������ϴ� ��Ÿ ������ �����
                    //  2.  ���� �ٿ��� �������� �÷��� ������������ �״´�.  
                     //   ���� �ٿ��� ������ ���� �� ���� ��� �׾��ְ�  ������ ���ð�� pop���ش�
                      // ���� �� ���� ���� �����ص� ����. 



#include<iostream>
#include<stack>

using namespace std;

int N, P;
stack<int>s[7]; // �� 1-6
int result = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P;

	for (int i = 0; i < N; i++) {


		pair<int, int> T;  // �� , �÷���ȣ
		cin >> T.first >> T.second;

		if (s[T.first].empty())
		{
			result++;	 s[T.first].push(T.second);
		}

		else
		{
			if (T.second > s[T.first].top())  // ���� �÷��� �� ũ�ٸ�
			{
				s[T.first].push(T.second);
				result++;  // �հ��� �ѹ� �����δ�.
			}

			else if (T.second == s[T.first].top()) // �̹� ������ �߰��� �ʿ� ����
				continue;

			else  // ���� �÷��� �۴ٸ� 
			{
				while (!s[T.first].empty() && T.second < s[T.first].top())
				{
					s[T.first].pop();  // ���� �÷��� ���� ���� �÷����� �����ش�.
					result++; //   ������ �� �հ����� �����̹Ƿ� ++
				}


				if (!s[T.first].empty() && T.second == s[T.first].top())  // ���� ���� �÷��� ������ 
					continue;



				s[T.first].push(T.second);
				result++;
			}

		}
	}

	cout << result;



	system("pause");
	return 0;
}