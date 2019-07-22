#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


//  v1���� v2��带 �� ������ �Ѵ�.
//  1->v1->v2->N
//  1->v2->v1->N    ���ͽ�Ʈ�� �˰����� ��� �����ѵ�  1���� 2���� �ּҸ�  ���

// ��ΰ� ���� ���� ���� ��� -1 ����ؾ� �ϴµ�  ansewer �� Inf �̻��̰ų�  0�̸��϶��� -1�� ����Ѵ�.


struct graph {

	int node, cost;
	bool operator <(const graph t) const { return cost > t.cost; }

};

int n, m, x, y;
const int INF = 1e9;

int dijkstra(vector<graph>v[], int dist[], int depart, int arrive) {

	priority_queue<graph> pq;

	pq.push({ depart,0 });
	fill(dist, dist + n, INF); // �ʱ�ȭ
	dist[depart] = 0; // �ʱ�ȭ 
	
	while (!pq.empty()) {

		int now = pq.top().node, cost = pq.top().cost;
		pq.pop();

		if (dist[now] < cost) continue;

		for (auto k : v[now]) {
			int next = k.node, ncost = cost + k.cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ next,ncost });

			}
		}
	}


	return dist[arrive];
}







int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vector<graph> v[800];
	int dist[800];

	while (m--) {

		int a, b, c;
		cin >> a >> b >> c;

		v[a - 1].push_back({ b - 1,c });  // ����� �׷��� �̹Ƿ� ���ʿ� �� �־��ش�.
		v[b - 1].push_back({ a - 1,c });
	}

	cin >> x >> y;
	//1->x->y->N
	int path1 = dijkstra(v, dist, 0, x - 1) + dijkstra(v, dist, x - 1, y - 1) + 
		        dijkstra(v, dist, y - 1, n-1);

	int path2 = dijkstra(v, dist, 0, y - 1) + dijkstra(v, dist, y - 1, x - 1) +
		        dijkstra(v, dist, x - 1, n - 1);


	if (path1 < path2 &&path1 < INF) cout << path1 << "\n";
	else if (path1 > path2 && path2 < INF) cout << path2 << "\n";
	else cout << "-1\n";

	//system("pause");
	return 0;
}