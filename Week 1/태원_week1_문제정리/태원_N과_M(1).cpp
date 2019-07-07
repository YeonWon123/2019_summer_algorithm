#include <iostream>
#include <vector>
using namespace std;
#define maxValue 8 // �ִ� 8���� �迭 index ����
int n, m; // n : 1~n���� �ڿ��� , m : ������ ����
bool Select[maxValue];
vector<int> v; // ������ ����ؾ� �Ǽ� �������

void Print() // ���Ϳ� ����� ������ ����Ѵ�.
{
	for (int i = 0; i < v.size(); i++) { // ������ ������ ��ŭ ������ ������.
		cout << v[i] << " ";
	}
		cout << "\n";

}

void Search(int Cnt) // ������ ����.
// Cnt : ī��Ʈ �� ����
{
	if (Cnt == m) // m���� ������ �� ���������� 
	{
		Print(); // ���
		return;
	}

	for (int i = 0; i < n; i++) // i�� ������ ���� ������ index
	{
		if (Select[i] == true) continue; // select[i]��  �̹� ���õǾ��ٸ� ���� ������
		Select[i] = true; // �������� �ʾҴٸ� ���� index�� ����
		v.push_back(i + 1); // ������ ����ؾ��ϱ� ������ ������ ������� ���Ϳ� �־��ش�.
		Search(Cnt + 1); // ī��Ʈ�� �Ǿ����� ī���͸� +1���ְ� ��������� ���ο� ���� ã�´�.
		v.pop_back(); // ����� �Ǿ����� ���� ���߿� ���� ���� ���Ϳ��� ���ش�.
		Select[i] = false; // ���ŵ� ���� index�� false��
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;


	Search(0); 

	return 0;
}

// ���� https://yabmoons.tistory.com/99