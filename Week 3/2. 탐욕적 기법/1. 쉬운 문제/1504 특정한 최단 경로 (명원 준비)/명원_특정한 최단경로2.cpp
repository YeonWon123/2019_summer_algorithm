#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define Max_N 801
#define Max_E 200001
#define INF 987654321
int N, E;

typedef struct Node {

	int end;
	int val;

};

vector<Node>Edge_arr[Max_N];

int dist[Max_N];



int dijkstra(int start, int last) {

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });

	for (int i = 1; i <= N; i++) {

		dist[i] = INF;
	}
	dist[start] = 0;

	while (!pq.empty()) {
		
		int nownum = pq.top().second;
		int nowcost = pq.top().first;
		pq.pop();

		for (int i = 0; i < Edge_arr[nownum].size(); i++) {

			int newdist = dist[nownum] + Edge_arr[nownum][i].val;
			int predist = dist[Edge_arr[nownum][i].end];

			if (newdist < predist)
			{
				dist[Edge_arr[nownum][i].end] = newdist;
				pq.push({ -1 * newdist,Edge_arr[nownum][i].end });
			}
		}
	}


	return dist[last];
}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	cin >> N >> E;

	int from, to, cost, first, second;

	for (int i = 0; i < E; i++) {

		cin >> from >> to >> cost;

		Edge_arr[from].push_back(Node{ to,cost });
		Edge_arr[to].push_back(Node{ from,cost });

	}

	cin >> first >> second;


	

	int firstroute = dijkstra(1, first) + dijkstra(first, second) + dijkstra(second, N);
	int secondroute = dijkstra(1, second) + dijkstra(second, first) + dijkstra(first, N);
	
	if (firstroute < secondroute) cout << firstroute;
	else if (secondroute < firstroute) cout << secondroute;
	else
		cout << "-1";


	//system("pause");
	return 0;
}