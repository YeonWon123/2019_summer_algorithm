#include<iostream>
using namespace std;


int main(void)
{


	ios_base::sync_with_stdio(false);
	cin.tie(false); cout.tie(false);


	int e, f, c;  // e�� ������ �ִ� ���Ǽ�  ,f��  �׳� �߰��� ���Ǽ� ,c�� �������� �ٲٴµ� �ʿ��Ѻ�
	int a, b; // a�� �ٲ� �����Ǽ�   b�� �ٲٰ� ���� ���Ǽ� ;
	int all = 0;// ��������� �� �ٲ� ź������ ��

	cin >> e >> f >> c;

	a = (e + f) / c; // �ٲ� ź������ ��
	b = (e + f) % c; // ���� ���� ���� 

	all = a;

	while (a + b >= c) {

		int temp1 = (a + b) / c;
		int temp2 = (a + b) % c;

		a = temp1; b = temp2;
		all += a;

	}


	cout << all;

	//system("pause");
	return 0;
}


// �츮�� ����  ��ȸ�� ���� ���� 1��
//  ������  �ٲپ ���� ź�����Ḧ �ٽ� ������ Ȱ�� ���� �ϴٴ� ���� 
//  �ٲٰ� ���� ������ ���鵵 ��� �����ϸ鼭  �ٲ� ź���������  ������־�� �Ѵٴ� ���� ����Ʈ