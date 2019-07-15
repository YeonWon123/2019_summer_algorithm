// 13460 구슬 탈출 2
#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int d, rx, ry, bx, by;
};
char board[10][10];
int n, m;
int fx, fy;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int start_rx, start_ry, start_bx, start_by;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				start_rx = i, start_ry = j; // R 좌표 투입
			}
			else if (board[i][j] == 'B') {
				start_bx = i, start_by = j; // B 좌표 투입
			}
			else if (board[i][j] == 'O') {
				fx = i, fy = j; // o 좌표 투입
			}
		}
	}
	queue<Node>q;
	q.push({ 0,start_rx,start_ry,start_bx,start_by }); // 큐에 시작좌표투입
	int ans = -1;
	while (!q.empty()) {
		int cnt = q.front().d;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		q.pop();
		if (cnt == 10) {
			break;
		}
		for (int k = 0; k < 4; k++) {
			int rex = 0;
			int blue = 0;
			int remove = 0;
			int nrx = rx + dx[k];
			int nry = ry + dy[k];
			while (board[nrx][nry] != '#') {//R이 굴러간다.
				remove++;
				if (nrx == bx && nry == by) blue = remove;//가는 길에 B가 있다.
				if (board[nrx][nry] == 'O') rex = remove;//가는 길에 구멍이 있다.
				nrx += dx[k];
				nry += dy[k];
			}
			int bex = 0;
			int red = 0;
			int bmove = 0;
			int nbx = bx + dx[k];
			int nby = by + dy[k];
			while (board[nbx][nby] != '#') {//B가 굴러간다.
				bmove++;
				if (nbx == rx && nby == ry) red = bmove;//가는 길에 R이 있다.
				if (board[nbx][nby] == 'O') bex = bmove;//가는 길에 구멍이 있다.
				nbx += dx[k];
				nby += dy[k];
			}
			if (!blue && !red) {//R이 굴러갈 때 앞에 B가 없고, B가 굴러갈 때 앞에 R이 없을 때
				if (rex) {//R이 굴러가는데 앞에 구멍이 있었다면
					ans = cnt + 1;
					cout << ans << '\n';
					return 0;//종료
				}
				else if (bex) {//B가 굴러가는데 앞에 구멍이 있었다면
					continue;
				}
				else {//둘다 아니면 큐에 넣어줘서 while문 계속 돌아가게 하기
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
			else if (blue) {//R이 굴러갈 때 앞에 B가 있었다면
				if (rex) {//R이 굴러가는데 앞에 구멍이 있었다면
					if (rex < blue) {//구멍이 B보다 더 앞에 있다면
						ans = cnt + 1;
						cout << ans << '\n';
						return 0;//종료
					}
					continue;
				}
				else {//R이 굴러가는데 앞에 구멍이 없었다면
					remove--;//파란 구슬은 최대한 굴러가고 빨간 구슬은 파란 구슬보다 한칸 덜 이동
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
			else {//B가 굴러가는데 앞에 R이 있었다면
				if (rex) {//구멍이 있는 경우
					continue;
				}
				else {//구멍이 없는 경우
					bmove--;//빨간 구슬은 최대한 이동하고, 파란 구슬은 빨간 구슬보다 한칸 덜 이동
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
// 출처 : https://blog.naver.com/jjujju31/221577135079
// 어려워서..
