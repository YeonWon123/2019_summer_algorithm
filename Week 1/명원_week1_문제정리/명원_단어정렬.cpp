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
		s.insert(make_pair(str.length(), str)); // ���̿� ���ڿ��� set�� �����Ѵ�.
		                                        // 1.���̰� ª�� �ͺ��� 2.���̰� ������ ������
		// bsT �̹Ƿ�  ���� ���̸� ���ϰ�  ���̰� ������ ���������� bst������ ������ �Ѵ�.
	}

	for (iter = s.begin(); iter != s.end(); iter++) {

		cout << iter->second << "\n";
	}



	//system("pause");
	return 0;
}
// 1.set�ȿ�  pair�� ����ߴ� ��
// 2. set�� �Ἥ  <����,�̸�> �������ν� ���ڸ� �켱���� �񱳷� �ΰ� ������ ���ڿ��� ���̷� �ߴٴ� ��
// 3. pair�� ������ ���� make_pair<����,����> ����
// 4. set�� iterator �� ����Ѵٴ� ��      ����� �����µ� ������ �Ǵ� ������ �� ����.
// pair<int, int> p1;
// p1 = make_pair(10, 20);


