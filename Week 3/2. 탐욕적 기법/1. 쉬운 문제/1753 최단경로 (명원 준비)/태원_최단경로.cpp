#include <iostream>
#include <queue>
#include <vector>
#define MAX_V 20001
#define MAX_E 300001
#define INF 987654321

using namespace std;
int v, e, start_node_num;

typedef struct node
{
	int end;
	int val; // 노드의 길이
};

// 각 노드의 엣지를 저장하는 벡터
// 0번 인덱스는 버린다.
vector<node> EDGE_arr[MAX_E];

// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_V];

void dijkstra()
{

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start_node_num });

	//노드의 거리 갱신은 v-1번 만큼 하면 된다.
	while (!pq.empty())
	{
		int now_node = pq.top().second; // 노드의 번호
		int cost = -1 * pq.top().first; // 노드와 start 노드의 거리
		pq.pop();
		// 현재 노드에서부터 주변에 있는 노드들의 값을 갱신한다.
		for (int i = 0; i < EDGE_arr[now_node].size(); i++)
		{
			int new_val = dist[now_node] + EDGE_arr[now_node][i].val;
			int before_val = dist[EDGE_arr[now_node][i].end];
			// 현재 노드로 부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 //비교하여 기존의 것이 더 크면 값을 갱신한다.
			if (new_val < before_val)
			{
				dist[EDGE_arr[now_node][i].end] = new_val;
				pq.push({ -1*new_val, EDGE_arr[now_node][i].end });
			}
		}
	}
}

int main()
{
	cin >> v >> e;
	cin >> start_node_num;

	int from, to, val;

	//간선 연결
	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> val;
		EDGE_arr[from].push_back(node{ to, val });
	}
	// 간선간의 거리 초기화
	for (int i = 1; i <= v; i++)
	{
		if (i != start_node_num)
			dist[i] = INF;
	}
	dist[start_node_num] = 0;
	dijkstra();
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";
	}
	return 0;

}

