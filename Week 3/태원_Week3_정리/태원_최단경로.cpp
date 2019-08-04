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
	int val; // ����� ����
};

// �� ����� ������ �����ϴ� ����
// 0�� �ε����� ������.
vector<node> EDGE_arr[MAX_E];

// ��� ��忡�������� �Ÿ��� �����ϴ� �迭
int dist[MAX_V];

void dijkstra()
{

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start_node_num });

	//����� �Ÿ� ������ v-1�� ��ŭ �ϸ� �ȴ�.
	while (!pq.empty())
	{
		int now_node = pq.top().second; // ����� ��ȣ
		int cost = -1 * pq.top().first; // ���� start ����� �Ÿ�
		pq.pop();
		// ���� ��忡������ �ֺ��� �ִ� ������ ���� �����Ѵ�.
		for (int i = 0; i < EDGE_arr[now_node].size(); i++)
		{
			int new_val = dist[now_node] + EDGE_arr[now_node][i].val;
			int before_val = dist[EDGE_arr[now_node][i].end];
			// ���� ���� ���� ����� ������ ���������� ���� �Ÿ��� ������ �Ÿ��� //���Ͽ� ������ ���� �� ũ�� ���� �����Ѵ�.
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

	//���� ����
	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> val;
		EDGE_arr[from].push_back(node{ to, val });
	}
	// �������� �Ÿ� �ʱ�ȭ
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

