#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	int inDegree = 0;
	bool next[501] = { false, };
	Node() {}
};

void topologySort(Node node[], int n) {
	queue<int> q;
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if (node[i].inDegree == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		if (q.size() > 1) {
			//ť�� push�� �ѹ��� �ι��̻� �Ǿ��� -> �������� ���̽��� ��������� �Ҹ�
			//Ȯ���ϰ� ������ ã���� ����
			cout << "?" << endl;
			return;
		}
		int curIndex = q.front();
		ret.push_back(curIndex);
		q.pop();
		//���� ����Ǿ��ִ� ������� inDegree����
		for (int i = 1; i <= n; i++) {
			if (node[curIndex].next[i]) {
				if (--node[i].inDegree == 0) {
					q.push(i);
				}
			}
		}
	}
	if (ret.size() == n) {
		for (int it : ret) {
			cout << it << " ";
		}
		cout << '\n';
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {

	int tCase;
	cin >> tCase;
	while (tCase--) {
		int n;
		cin >> n;
		int nums[n + 1];
		Node node[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				//1���� 2,3,4,5�� ��κ��� ������ �տ� ��ġ
				//2���� 3,4,5�� ��κ��� ������ �տ���ġ -> ���� ������������Ѵ�.
				node[nums[i]].next[nums[j]] = true;
				node[nums[j]].inDegree++;
			}
		}
		int ch;
		cin >> ch;
		while (ch--) {
			int a, b;
			cin >> a >> b;
			if (!node[a].next[b]) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			//��� a�� ��� b���� �� ū��� �������
			//����
			node[a].next[b] = false;
			node[b].inDegree--;
			//�����⼳��
			node[b].next[a] = true;
			node[a].inDegree++;
		}
		//������ ������ ���������Ѵ�.
		topologySort(node, n);
	}

	return 0;
}

// �������� Ǯ�� : https://dev-jk.tistory.com/13, 
// �������� Ǯ�� : http://blog.naver.com/PostView.nhn?blogId=zmtn94&logNo=221398344205&parentCategoryNo=&categoryNo=11&viewDate=&isShowPopularPosts=false&from=postView