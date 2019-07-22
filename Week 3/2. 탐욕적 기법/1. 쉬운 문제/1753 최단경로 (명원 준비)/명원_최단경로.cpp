
//O(ElogV) 의 시간복잡도를 가지는 이유는 힙에 최악의 경우 E번의 탐색한 노드를 집어넣는 경우가 발생하게 되는데, 이러한 경우에 O(ElogE)의 시간 복잡도가 나오며, 중복 간선을 허용하지 않는 그래프라면 O(E) <= O(V2) 이므로 O(log E) <= O(log V2)와 같다.이때 O(logV2) = O(2×logV) 이므로, 상수를 제거하면 O(ElogV)가 된다.물론 여기서 탐색에 소요되는 시간 O(V + E)는 O(ElogV)보다 작으므로 무시한다.
//
//알고리즘 문제를 풀다가 보니, V2은 1억이 넘기 때문에 알고리즘 문제를 풀기에 부적절했다.
//우선순위 큐를 이용하면 300, 000 * log(20, 000) 이기 때문에 충분한 속도로 문제를 해결할 수 있다.
//따라서, 이 문제는 우선 순위 큐를 이용하여 구현해야 한다.






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
// 각 노드의 엣지를 저장하는 벡터
// 0번 인덱스는 버린다.

int dist[MAX_V] = { 0 };  //출발 노드에서부터의 거리를 저장하는 배열



void dijkstra() {

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start_node_num });


	while (!pq.empty()) {

		int now_node = pq.top().second;   // pq.top() 우선순위가 가장높은 원소를 리턴한다.
		int cost = -1 * pq.top().first;
		pq.pop();



		// 현재 노드에서부터 주변에 있는 애들의 값을 갱신한다.

		for (int k = 0; k < EDGE_arr[now_node].size(); k++) {

			int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
			int before_val = dist[EDGE_arr[now_node][k].end];



			//현재 노드로부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 비교하여
			// 기존의 것이 더 크면 값을 갱신한다.


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
	// 간선 연결

	for (int i = 0; i < E; i++) {

		cin >> from >> to >> val;
		EDGE_arr[from].push_back(NODE{ to,val });
	}

	// 간선간의 거리 초기화
	for (int i = 1; i <= V; i++) {

		dist[i] = INF;
	}
	dist[start_node_num] = 0; // 자기자신으로부터 출발하는 것은 0이니까

	dijkstra();

	// 값을 출력한다.

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";

	}

	//system("pause");
	return 0;
}