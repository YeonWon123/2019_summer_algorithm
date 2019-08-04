#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

int start_node_num, V, E;

typedef struct Node{

	int end;
	int val;

};

vector<Node> Edge_arr[MAX_V]; // 각노드의 엣지를 저장하는 벡터

int dist[MAX_V] = { 0 }; // 출발 노드에서부터 각 엣지까지의 거리를 저장하는 배열 



void dijkstra() {


	// 우선순위 큐를 쓴다.

	priority_queue<pair<int, int>>pq;
	pq.push({ 0, start_node_num });

	while (!pq.empty())
	{

		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		// 현재 노드에서 주변에 있는 애들의 값을 갱신해 준다.

		for (int k = 0; k < Edge_arr[now_node].size(); k++) {

			int newval = dist[now_node] + Edge_arr[now_node][k].val;
			int before_bal = dist[Edge_arr[now_node][k].end];


			if (newval < before_bal) {

				dist[Edge_arr[now_node][k].end] = newval;
				pq.push({ -1 * newval, Edge_arr[now_node][k].end });

			}
		}
	}
 }



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	cin >> V >> E >> start_node_num;

	int from, to, cost;

	for (int i = 0; i < E; i++) {

		cin >> from >> to >> cost;

		Edge_arr[from].push_back(Node{ to,cost });  // 양방향이 아니므로 
	
	}

	for (int i = 1; i <= V; i++) {

		dist[i] = INF;
	}

	dist[start_node_num] = 0;


	dijkstra();


	// 출력을 해주자

	for (int i = 1; i <= V; i++) {

		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";

	}

	system("pause");
	return 0;
}