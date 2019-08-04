#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#define V 10002
#define E 10002

using namespace std;
int ans = 0;
int end_point = 0;
struct node
{
	int to;
	int value;
};
vector <node> EDGE_arr[E];
bool check[V];
int dist[V];
void dfs(int point, int length)
{
	if (check[point])
		return;
	check[point] = true;
	if (ans < length)
	{
		ans = length;
		end_point = point;
	}
	for (int i = 0; i < EDGE_arr[point].size(); i++)
	{
		dfs(EDGE_arr[point][i].to, length + EDGE_arr[point][i].value);
	}

}

int main()
{
	int n;

	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;

		EDGE_arr[a].push_back(node{ b, c });
		EDGE_arr[b].push_back(node{ a, c });
	}
	dfs(1, 0);
	ans = 0;
	memset(check, false,sizeof(check));
	dfs(end_point, 0);
	cout << ans << "\n";

	return 0;
}
