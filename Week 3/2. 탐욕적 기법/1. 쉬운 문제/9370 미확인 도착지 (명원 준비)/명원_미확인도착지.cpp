#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 200000000

using namespace std;

struct Vertex {

	int dist = INF, idx;

	vector<int>post;
	vector<pair<int, int>>next;
	bool operator <	(const Vertex &v)const 
	{ return dist > v.dist; }
};




//�⺻������ �� �������� �ٸ� �������� ���� �ִܰ�ΰ� �ʿ��ѵ� � �� ������ �湮�ؾ� �ϰų� �� ������ ����� �Ѵٸ�
//
//���ͽ�Ʈ�� 3������ �ִܰ�θ� ���� �� �ִ�.
//
//
//
//
//start >> n1 -- n2 >> end
//
//
//
//
//�� ��(start->n1) + (n1->n2) + (n2->end) �ִܰ�ο� ��(start->n2) + (n2->n1) + (n1->end) �ִܰ�θ� ���� �� �ִ�.
//
//
//
//
//s�� �������� ���ͽ�Ʈ�� �� ��� s->end ���� �ּҺ���� �� �� �ִ�.
//
//�� ���� �� �Ǵ� �� ���� �ϳ��� ���ٸ� end �ĺ����� �����Ѵٰ� �� �� �ִ�.
//
//
//
//
//�� �׷���, �� ȹ������ ����� �ִ�!!(�ð��� ��û ª�� ����� Ǯ�̸� ���ٰ� �߰��Ͽ���.)
//
//
//
//
//���� ����ġ�� ��� �����϶� ��� ������ ����ġ���� * 2 ���ְ� n1 - n2 ������ ����ġ�� - 1 ���༭ Ȧ���� �����.
//
//���� ���ͽ�Ʈ�� �ѹ����ָ� �ĺ����� ����ġ�� Ȧ���϶� ������ n1 - n2�� ���� ������ �ս��� Ȯ���� �� �ִ�.
//
//
//
//
//-1�� ���ٰ�� ���� ���� ������������ n1 - n2�� ������ �������� �ִܰ�ΰ� ���� ��� ������ n1 - n2 ��θ� ������
//
//�� �� �־� �ߺ���θ� �ɷ��� �� �ִٴ� ������ �ִ�.






int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {

		int n, m, t, s, g, h;

		cin >> n >> m >> t >> s >> g >> h;

		Vertex vertex[2001];
		for (int i = 1; i <= n; i++) {

			vertex[i].idx = i;
		}

		vector<int>target; // �ĺ� ������ ����

		while (m--) {

			int a, b, d;
			cin >> a >> b >> d;
			d *= 2;

			if ((a == g && b == h) || (a == h && b == g)) d -= 1;

			vertex[a].next.push_back(make_pair(d, b));
			vertex[b].next.push_back(make_pair(d, a));   // ����� �׷����̴ϱ�

		}

		while (t--) {

			int ta;
			cin >> ta;
			target.push_back(ta);

		}

		priority_queue<Vertex> pq;

		vertex[s].dist = 0;  //��������� ����������� 0�̴ϱ�
		pq.push(vertex[s]);

		while (!pq.empty()) {

			Vertex curVertex = pq.top();
			pq.pop();

			for (pair<int, int>pa : curVertex.next) {

				int w = pa.first;  // ����ġ
				int nIdx = pa.second;

				if (vertex[nIdx].dist > curVertex.dist + w) {

					vertex[nIdx].dist = curVertex.dist + w;
					pq.push(vertex[nIdx]);

				}
			}
		}

		sort(target.begin(), target.end());
		for (int tIdx : target) {
			if (vertex[tIdx].dist % 2 != 0)
				cout << tIdx << " ";	
		}
		cout << "\n";
	}




	//system("pause");
	return 0;
}