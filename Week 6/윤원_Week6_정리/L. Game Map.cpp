#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int dfs(vector<vector<int>>& graph, vector<int>& neighbor, vector<int>& dp, int cur) {
    if (dp[cur]) return dp[cur];//이미 계산한 경우예요
    int cnt = 1;//나 자신
    for (auto& next : graph[cur]) {//탐색해요
        if (neighbor[cur] < neighbor[next]) {
            cnt = max(1 + dfs(graph, neighbor, dp, next), cnt);
        }//이웃이 더 많다면 최댓값을 갱신해요
    }
    return dp[cur] = cnt;//값을 저장해요
}
 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> neighbor(n);
    vector<int> dp(n);
    for (int edge = 0, i, j; edge < m; edge++) {
        cin >> i >> j;
        //graph를 갱신해요
        graph[i].push_back(j);
        graph[j].push_back(i);
        //이웃을 증가시켜줘요
        neighbor[i]++;
        neighbor[j]++;
    }
    
    int biggest = 0;//최댓값을 찾아요
    for (int i = 0; i < n; i++) {
        biggest = max(biggest, dfs(graph, neighbor, dp, i));
    }
    cout << biggest << '\n';
 
    return 0;
}

// 출처 : https://tiger1710.tistory.com/46