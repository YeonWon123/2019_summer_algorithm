// 13460 ���� Ż�� 2
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
				start_rx = i, start_ry = j; // R ��ǥ ����
			}
			else if (board[i][j] == 'B') {
				start_bx = i, start_by = j; // B ��ǥ ����
			}
			else if (board[i][j] == 'O') {
				fx = i, fy = j; // o ��ǥ ����
			}
		}
	}
	queue<Node>q;
	q.push({ 0,start_rx,start_ry,start_bx,start_by }); // ť�� ������ǥ����
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
			while (board[nrx][nry] != '#') {//R�� ��������.
				remove++;
				if (nrx == bx && nry == by) blue = remove;//���� �濡 B�� �ִ�.
				if (board[nrx][nry] == 'O') rex = remove;//���� �濡 ������ �ִ�.
				nrx += dx[k];
				nry += dy[k];
			}
			int bex = 0;
			int red = 0;
			int bmove = 0;
			int nbx = bx + dx[k];
			int nby = by + dy[k];
			while (board[nbx][nby] != '#') {//B�� ��������.
				bmove++;
				if (nbx == rx && nby == ry) red = bmove;//���� �濡 R�� �ִ�.
				if (board[nbx][nby] == 'O') bex = bmove;//���� �濡 ������ �ִ�.
				nbx += dx[k];
				nby += dy[k];
			}
			if (!blue && !red) {//R�� ������ �� �տ� B�� ����, B�� ������ �� �տ� R�� ���� ��
				if (rex) {//R�� �������µ� �տ� ������ �־��ٸ�
					ans = cnt + 1;
					cout << ans << '\n';
					return 0;//����
				}
				else if (bex) {//B�� �������µ� �տ� ������ �־��ٸ�
					continue;
				}
				else {//�Ѵ� �ƴϸ� ť�� �־��༭ while�� ��� ���ư��� �ϱ�
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
			else if (blue) {//R�� ������ �� �տ� B�� �־��ٸ�
				if (rex) {//R�� �������µ� �տ� ������ �־��ٸ�
					if (rex < blue) {//������ B���� �� �տ� �ִٸ�
						ans = cnt + 1;
						cout << ans << '\n';
						return 0;//����
					}
					continue;
				}
				else {//R�� �������µ� �տ� ������ �����ٸ�
					remove--;//�Ķ� ������ �ִ��� �������� ���� ������ �Ķ� �������� ��ĭ �� �̵�
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
			else {//B�� �������µ� �տ� R�� �־��ٸ�
				if (rex) {//������ �ִ� ���
					continue;
				}
				else {//������ ���� ���
					bmove--;//���� ������ �ִ��� �̵��ϰ�, �Ķ� ������ ���� �������� ��ĭ �� �̵�
					q.push({ cnt + 1,rx + dx[k] * remove,ry + dy[k] * remove,bx + dx[k] * bmove,by + dy[k] * bmove });
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
// ��ó : https://blog.naver.com/jjujju31/221577135079
// �������..
