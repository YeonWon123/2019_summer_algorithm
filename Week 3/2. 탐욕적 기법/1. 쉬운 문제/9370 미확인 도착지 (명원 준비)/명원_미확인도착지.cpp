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




//기본적으로 한 지점에서 다른 지점으로 가는 최단경로가 필요한데 어떤 두 정점을 방문해야 하거나 한 간선을 들려야 한다면
//
//다익스트라 3번으로 최단경로를 구할 수 있다.
//
//
//
//
//start >> n1 -- n2 >> end
//
//
//
//
//는 ①(start->n1) + (n1->n2) + (n2->end) 최단경로와 ②(start->n2) + (n2->n1) + (n1->end) 최단경로를 구할 수 있다.
//
//
//
//
//s를 기준으로 다익스트라 할 경우 s->end 까지 최소비용을 알 수 있다.
//
//그 값이 ① 또는 ② 둘중 하나와 같다면 end 후보지를 만족한다고 볼 수 있다.
//
//
//
//
//※ 그런데, 더 획기적인 방법이 있다!!(시간이 엄청 짧은 사람의 풀이를 보다가 발견하였다.)
//
//
//
//
//만약 가중치가 모두 정수일때 모든 간선의 가중치들을 * 2 해주고 n1 - n2 사이의 가중치를 - 1 해줘서 홀수로 만든다.
//
//이후 다익스트라를 한번해주면 후보지의 가중치가 홀수일때 무조건 n1 - n2를 지난 것으로 손쉽게 확인할 수 있다.
//
//
//
//
//-1을 해줄경우 만약 원래 간선기준으로 n1 - n2를 지나던 안지나던 최단경로가 같을 경우 무조건 n1 - n2 경로를 지나게
//
//할 수 있어 중복경로를 걸러낼 수 있다는 장점이 있다.






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

		vector<int>target; // 후보 목적지 저장

		while (m--) {

			int a, b, d;
			cin >> a >> b >> d;
			d *= 2;

			if ((a == g && b == h) || (a == h && b == g)) d -= 1;

			vertex[a].next.push_back(make_pair(d, b));
			vertex[b].next.push_back(make_pair(d, a));   // 양방향 그래프이니까

		}

		while (t--) {

			int ta;
			cin >> ta;
			target.push_back(ta);

		}

		priority_queue<Vertex> pq;

		vertex[s].dist = 0;  //출발지에서 출발지까지는 0이니까
		pq.push(vertex[s]);

		while (!pq.empty()) {

			Vertex curVertex = pq.top();
			pq.pop();

			for (pair<int, int>pa : curVertex.next) {

				int w = pa.first;  // 가중치
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