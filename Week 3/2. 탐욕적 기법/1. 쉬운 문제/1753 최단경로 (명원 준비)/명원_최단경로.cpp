
//O(ElogV) �� �ð����⵵�� ������ ������ ���� �־��� ��� E���� Ž���� ��带 ����ִ� ��찡 �߻��ϰ� �Ǵµ�, �̷��� ��쿡 O(ElogE)�� �ð� ���⵵�� ������, �ߺ� ������ ������� �ʴ� �׷������ O(E) <= O(V2) �̹Ƿ� O(log E) <= O(log V2)�� ����.�̶� O(logV2) = O(2��logV) �̹Ƿ�, ����� �����ϸ� O(ElogV)�� �ȴ�.���� ���⼭ Ž���� �ҿ�Ǵ� �ð� O(V + E)�� O(ElogV)���� �����Ƿ� �����Ѵ�.
//
//�˰��� ������ Ǯ�ٰ� ����, V2�� 1���� �ѱ� ������ �˰��� ������ Ǯ�⿡ �������ߴ�.
//�켱���� ť�� �̿��ϸ� 300, 000 * log(20, 000) �̱� ������ ����� �ӵ��� ������ �ذ��� �� �ִ�.
//����, �� ������ �켱 ���� ť�� �̿��Ͽ� �����ؾ� �Ѵ�.






#include<iostream>
#include<vector>
#include<queue>
using namespace std;


#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

int start_node_num, V, E;


typedef struct NODE {

	int end;
	int val;

};

vector<NODE> EDGE_arr[MAX_V];
// �� ����� ������ �����ϴ� ����
// 0�� �ε����� ������.

int dist[MAX_V] = { 0 };  //��� ��忡�������� �Ÿ��� �����ϴ� �迭



void dijkstra() {

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start_node_num });


	while (!pq.empty()) {

		int now_node = pq.top().second;   // pq.top() �켱������ ������� ���Ҹ� �����Ѵ�.
		int cost = -1 * pq.top().first;
		pq.pop();



		// ���� ��忡������ �ֺ��� �ִ� �ֵ��� ���� �����Ѵ�.

		for (int k = 0; k < EDGE_arr[now_node].size(); k++) {

			int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
			int before_val = dist[EDGE_arr[now_node][k].end];



			//���� ���κ��� ����� ������ ���������� ���� �Ÿ��� ������ �Ÿ��� ���Ͽ�
			// ������ ���� �� ũ�� ���� �����Ѵ�.


			if (new_val < before_val) {

				dist[EDGE_arr[now_node][k].end] = new_val;
				pq.push({ -1 * new_val,EDGE_arr[now_node][k].end });

			}
		}
	}

}







int main(void)
{

	cin >> V >> E >> start_node_num;

	int from, to, val;
	// ���� ����

	for (int i = 0; i < E; i++) {

		cin >> from >> to >> val;
		EDGE_arr[from].push_back(NODE{ to,val });
	}

	// �������� �Ÿ� �ʱ�ȭ
	for (int i = 1; i <= V; i++) {

		dist[i] = INF;
	}
	dist[start_node_num] = 0; // �ڱ��ڽ����κ��� ����ϴ� ���� 0�̴ϱ�

	dijkstra();

	// ���� ����Ѵ�.

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";

	}

	//system("pause");
	return 0;
}