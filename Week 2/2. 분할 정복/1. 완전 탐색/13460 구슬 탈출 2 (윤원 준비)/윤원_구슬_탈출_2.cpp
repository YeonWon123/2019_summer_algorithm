#include <iostream>
#include <queue>
using namespace std;

// ������
char **board;

// ��ǥ�� �Է¹��� �� �ִ� Ŭ����(����ü)
class Point {
public:
	int red_y;
	int red_x;
	int blue_y;
	int blue_x;
	int direction; // 0 : ó�� �Ǵ� bfs���� ������ ���̿� �ִ� �� ��带 ��Ÿ��
				   // 1 : ����, 2 : ������, 3 : ��, 4 : �Ʒ�
};

// ���� ������ ������ ����� ��ǥ�� �����ϴ� ����
// ���� ������ �����Ͽ� �Լ� ȣ�� �� �Ű� ������ �������� �ʾƵ� �ǰԲ� ����
vector<Point> store;

// ������ �̵� Ƚ��
int moves = 1;

// �Լ� ����
void leftmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end);
void rightmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end);
void upmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end);
void downmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end);
void ending(int &true_end, int &bad_end);

int main()
{
	int N, M;
	cin >> N >> M;

	board = new char*[N];
	for (int i = 0; i < N; i++)
		board[i] = new char[M];

	// y : ����, x : ����
	int red_y, red_x;	// ���� ������ ��ġ
	int blue_y, blue_x;	// �Ķ� ������ ��ġ
	int o_y, o_x;		// ������ ��ġ

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			switch (board[i][j])
			{
			case 'O':
				o_y = i; o_x = j; break;
			case 'R':
				red_y = i; red_x = j; break;
			case 'B':
				blue_y = i; blue_x = j; break;
			default:
				break;
			}
		}

	// �ʺ� �켱 Ž��(BFS) �̿�

	// �� ������ ����� ��ǥ �� ���� Ž������ ���� ��ǥ�� �����ϴ� ť
	queue<Point> RB_point;
	RB_point.push({ red_y, red_x, blue_y, blue_x, 0 });	 // ���� ������ ���� ��ǥ�� ����

	int true_end, bad_end;
	true_end = 0; // ���� ���� ���ۿ� ���� ���
	bad_end = 0;  // �Ķ� ���� ���ۿ� ���� ���

	while (!RB_point.empty() && moves < 11) {
		Point RB_now = RB_point.front();	// ���� ��ǥ�� ������ ����� ��ǥ ����Ʈ�� ����
		RB_point.pop();

		// ����, ������, ��, �Ʒ� �� ���⿡ ���� ��� �˻��Ѵ�.
		// ��, ������ �湮�� ������ �ٽ� �˻����� �ʴ´�. (���� -> ���� X)
		// �̵� �Ұ��ϰų�, �̵����� �� ������ ����� ��ǥ�̸� �� ��ǥ�� ���� �߰����� �ʴ´�.
		// ���� ������ ���ۿ� ���� ��� ������ Ƚ���� ����ϰ� �����Ѵ�. (ending �Լ����� �̷����)
		if (RB_now.direction != 1 && RB_now.red_x != -1)
		{
			leftmove(RB_now, RB_point, true_end, bad_end);
			ending(true_end, bad_end);
		}
		if (RB_now.direction != 2 && RB_now.red_x != -1)
		{
			rightmove(RB_now, RB_point, true_end, bad_end);
			ending(true_end, bad_end);
		}
		if (RB_now.direction != 3 && RB_now.red_x != -1)
		{
			upmove(RB_now, RB_point, true_end, bad_end);
			ending(true_end, bad_end);
		}
		if (RB_now.direction != 4 && RB_now.red_x != -1)
		{
			downmove(RB_now, RB_point, true_end, bad_end);
			ending(true_end, bad_end);
		}

		// 0�� ó�� �Ǵ� bfs���� ������ ����(depth)�� �ִ� �� ��带 ��Ÿ��
		// ���� direction�� 0�� ��� bfs���� �� ����(depth)�� ���������� ǥ���ϱ� ���� ��带 �߰���
		if (RB_now.direction == 0)
		{
			RB_point.push({ -1, -1, -1, -1, 0 });
			moves++;
		}

	}
	
	// 10�� �̳��� ����� �� ���� ���
	cout << -1 << "\n";
	return 0;
}

void leftmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end)
{
	// ���� ���� �̵�
	int i = 1;	// ���� ������ �̵��ϴ� �Ÿ�
	int block = 0;
	do
	{
		switch (board[RB_now.red_y][RB_now.red_x - i])
		{
		case 'O':
			true_end = 1; break;
		case '#':
			block = 1; i--; break;
		default:
			i++; break;
		}
	} while (true_end != 1 && block != 1);

	// �Ķ� ���� �̵�
	int j = 1;	// �Ķ� ������ �̵��ϴ� �Ÿ�
	block = 0;
	do
	{
		switch (board[RB_now.blue_y][RB_now.blue_x - j])
		{
		case 'O':
			bad_end = 1; break;
		case '#':
			block = 1; j--;  break;
		default:
			j++; break;
		}
	} while (bad_end != 1 && block != 1);

	// ���� ���� �����̳� �Ķ� ������ ���ۿ� �� ���, �Լ��� �����Ѵ�.
	if (true_end == 1 || bad_end == 1)	return;

	// �׷��� �ʰ�, ���� ������ �Ķ� ������ ��ġ�� ���� ���, �� �����ʿ� �ִ� ������ ������ �ְ� �Ѵ�.
	if (RB_now.red_y == RB_now.blue_y)
	{
		if (RB_now.red_x - i == RB_now.blue_x - j)
		{
			if (i < j)
				j--;
			else
				i--;
		}
	}

	// ���� ���� ������ �Ķ� ���� ��� �̵����� �ʾ��� ���, �Լ��� �����Ѵ�.
	if (i == 0 && j == 0) return;

	// ���� ������ ���� ��ǥ�� �Ķ� ������ ���� ��ǥ�� ������ ���� ���� �ִ��� �����Ѵ�.
	// �̵����� �ʾ��� ���� store ť���� �� �������� �ִ� ��ǥ�� �Ȱ����Ƿ� �Լ��� �����Ѵ�.
	for (unsigned int k = 0; k < store.size(); k++)
	{
		if ((RB_now.red_y == store[k].red_y) && ((RB_now.red_x - i) == store[k].red_x))
			if ((RB_now.blue_y == store[k].blue_y) && ((RB_now.blue_x - j) == store[k].blue_x))
				return;
	}

	// �׷��� �ʴٸ�, �� ������ ���� ��ǥ��, ���� Ž������ ���� ��ǥ�� �����ϴ� ť�� �����Ѵ�. (�����̹Ƿ� ���� 1)
	// ���� ������ ������ ����� ��ǥ�� �����ϴ� vector���� �����Ѵ�.
	// cout << "���� �� : " << RB_now.red_y << " " << RB_now.red_x - i << " ���� 1 " << endl;
	RB_point.push({ RB_now.red_y, RB_now.red_x - i, RB_now.blue_y, RB_now.blue_x - j, 1 });
	store.push_back({ RB_now.red_y, RB_now.red_x - i, RB_now.blue_y, RB_now.blue_x - j, 1 });

	// �Լ� ����
	return;

}

void rightmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end)
{
	// ���� ���� �̵�
	int i = 1;	// ���� ������ �̵��ϴ� �Ÿ�
	int block = 0;
	do
	{
		switch (board[RB_now.red_y][RB_now.red_x + i])
		{
		case 'O':
			true_end = 1; break;
		case '#':
			block = 1; i--; break;
		default:
			i++; break;
		}
	} while (true_end != 1 && block != 1);

	// �Ķ� ���� �̵�
	int j = 1;	// �Ķ� ������ �̵��ϴ� �Ÿ�
	block = 0;
	do
	{
		switch (board[RB_now.blue_y][RB_now.blue_x + j])
		{
		case 'O':
			bad_end = 1; break;
		case '#':
			block = 1; j--;  break;
		default:
			j++; break;
		}
	} while (bad_end != 1 && block != 1);

	// ���� ���� �����̳� �Ķ� ������ ���ۿ� �� ���, �Լ��� �����Ѵ�.
	if (true_end == 1 || bad_end == 1)	return;

	// �׷��� �ʰ�, ���� ������ �Ķ� ������ ��ġ�� ���� ���, �� �����ʿ� �ִ� ������ ������ �ְ� �Ѵ�.
	if (RB_now.red_y == RB_now.blue_y)
	{
		if (RB_now.red_x + i == RB_now.blue_x + j)
		{
			if (i < j)
				j--;
			else
				i--;
		}
	}

	// ���� ���� ������ �Ķ� ���� ��� �̵����� �ʾ��� ���, �Լ��� �����Ѵ�.
	if (i == 0 && j == 0) return;

	// ���� ������ ���� ��ǥ�� �Ķ� ������ ���� ��ǥ�� ������ ���� ���� �ִ��� �����Ѵ�.
	// �̵����� �ʾ��� ���� store ť���� �� �������� �ִ� ��ǥ�� �Ȱ����Ƿ� �Լ��� �����Ѵ�.
	for (unsigned int k = 0; k < store.size(); k++)
	{
		if ((RB_now.red_y == store[k].red_y) && ((RB_now.red_x + i) == store[k].red_x))
			if ((RB_now.blue_y == store[k].blue_y) && ((RB_now.blue_x + j) == store[k].blue_x))
				return;
	}

	// �׷��� �ʴٸ�, �� ������ ���� ��ǥ��, ���� Ž������ ���� ��ǥ�� �����ϴ� ť�� �����Ѵ�. (�������̹Ƿ� ���� 2)
	// ���� ������ ������ ����� ��ǥ�� �����ϴ� vector���� �����Ѵ�.
	// cout << "���� �� : " << RB_now.red_y << " " << RB_now.red_x + i << " ���� 2 " << endl;
	RB_point.push({ RB_now.red_y, RB_now.red_x + i, RB_now.blue_y, RB_now.blue_x + j, 2 });
	store.push_back({ RB_now.red_y, RB_now.red_x + i, RB_now.blue_y, RB_now.blue_x + j, 2 });

	// �Լ� ����
	return;

}

void upmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end)
{
	// ���� ���� �̵�
	int i = 1;	// ���� ������ �̵��ϴ� �Ÿ�
	int block = 0;
	do
	{
		switch (board[RB_now.red_y - i][RB_now.red_x])
		{
		case 'O':
			true_end = 1; break;
		case '#':
			block = 1; i--; break;
		default:
			i++; break;
		}
	} while (true_end != 1 && block != 1);

	// �Ķ� ���� �̵�
	int j = 1;	// �Ķ� ������ �̵��ϴ� �Ÿ�
	block = 0;
	do
	{
		switch (board[RB_now.blue_y - j][RB_now.blue_x])
		{
		case 'O':
			bad_end = 1; break;
		case '#':
			block = 1; j--;  break;
		default:
			j++; break;
		}
	} while (bad_end != 1 && block != 1);

	// ���� ���� �����̳� �Ķ� ������ ���ۿ� �� ���, �Լ��� �����Ѵ�.
	if (true_end == 1 || bad_end == 1)	return;

	// �׷��� �ʰ�, ���� ������ �Ķ� ������ ��ġ�� ���� ���, �� �����ʿ� �ִ� ������ ������ �ְ� �Ѵ�.
	if (RB_now.red_y - i == RB_now.blue_y - j)
	{
		if (RB_now.red_x == RB_now.blue_x)
		{
			if (i < j)
				j--;
			else
				i--;
		}
	}

	// ���� ���� ������ �Ķ� ���� ��� �̵����� �ʾ��� ���, �Լ��� �����Ѵ�.
	if (i == 0 && j == 0) return;

	// ���� ������ ���� ��ǥ�� �Ķ� ������ ���� ��ǥ�� ������ ���� ���� �ִ��� �����Ѵ�.
	// �̵����� �ʾ��� ���� store ť���� �� �������� �ִ� ��ǥ�� �Ȱ����Ƿ� �Լ��� �����Ѵ�.
	for (unsigned int k = 0; k < store.size(); k++)
	{
		if (((RB_now.red_y - i) == store[k].red_y) && (RB_now.red_x == store[k].red_x))
			if (((RB_now.blue_y - j) == store[k].blue_y) && (RB_now.blue_x == store[k].blue_x))
				return;
	}

	// �׷��� �ʴٸ�, �� ������ ���� ��ǥ��, ���� Ž������ ���� ��ǥ�� �����ϴ� ť�� �����Ѵ�. (�����̹Ƿ� ���� 3)
	// ���� ������ ������ ����� ��ǥ�� �����ϴ� vector���� �����Ѵ�.
	// cout << "���� �� : " << RB_now.red_y - i << " " << RB_now.red_x << " ���� 3 " << endl;
	RB_point.push({ RB_now.red_y - i, RB_now.red_x, RB_now.blue_y - j, RB_now.blue_x, 3 });
	store.push_back({ RB_now.red_y - i, RB_now.red_x, RB_now.blue_y - j, RB_now.blue_x, 3 });

	// �Լ� ����
	return;

}

void downmove(Point RB_now, queue<Point>& RB_point, int &true_end, int &bad_end)
{
	// ���� ���� �̵�
	int i = 1;	// ���� ������ �̵��ϴ� �Ÿ�
	int block = 0;
	do
	{
		switch (board[RB_now.red_y + i][RB_now.red_x])
		{
		case 'O':
			true_end = 1; break;
		case '#':
			block = 1; i--; break;
		default:
			i++; break;
		}
	} while (true_end != 1 && block != 1);

	// �Ķ� ���� �̵�
	int j = 1;	// �Ķ� ������ �̵��ϴ� �Ÿ�
	block = 0;
	do
	{
		switch (board[RB_now.blue_y + j][RB_now.blue_x])
		{
		case 'O':
			bad_end = 1; break;
		case '#':
			block = 1; j--;  break;
		default:
			j++; break;
		}
	} while (bad_end != 1 && block != 1);

	// ���� ���� �����̳� �Ķ� ������ ���ۿ� �� ���, �Լ��� �����Ѵ�.
	if (true_end == 1 || bad_end == 1)	return;

	// �׷��� �ʰ�, ���� ������ �Ķ� ������ ��ġ�� ���� ���, �� �����ʿ� �ִ� ������ ������ �ְ� �Ѵ�.
	if (RB_now.red_y + i == RB_now.blue_y + j)
	{
		if (RB_now.red_x == RB_now.blue_x)
		{
			if (i < j)
				j--;
			else
				i--;
		}
	}

	// ���� ���� ������ �Ķ� ���� ��� �̵����� �ʾ��� ���, �Լ��� �����Ѵ�.
	if (i == 0 && j == 0) return;

	// ���� ������ ���� ��ǥ�� �Ķ� ������ ���� ��ǥ�� ������ ���� ���� �ִ��� �����Ѵ�.
	// �̵����� �ʾ��� ���� store ť���� �� �������� �ִ� ��ǥ�� �Ȱ����Ƿ� �Լ��� �����Ѵ�.
	for (unsigned int k = 0; k < store.size(); k++)
	{
		if (((RB_now.red_y + i) == store[k].red_y) && (RB_now.red_x == store[k].red_x))
			if (((RB_now.blue_y + j) == store[k].blue_y) && (RB_now.blue_x == store[k].blue_x))
				return;
	}

	// �׷��� �ʴٸ�, �� ������ ���� ��ǥ��, ���� Ž������ ���� ��ǥ�� �����ϴ� ť�� �����Ѵ�. (�Ʒ����̹Ƿ� ���� 4)
	// ���� ������ ������ ����� ��ǥ�� �����ϴ� vector���� �����Ѵ�.
	// cout << "���� �� : " << RB_now.red_y + i << " " << RB_now.red_x << " ���� 3 " << endl;
	RB_point.push({ RB_now.red_y + i, RB_now.red_x, RB_now.blue_y + j, RB_now.blue_x, 4 });
	store.push_back({ RB_now.red_y + i, RB_now.red_x, RB_now.blue_y + j, RB_now.blue_x, 4 });

	// �Լ� ����
	return;

}

void ending(int &true_end, int &bad_end)
{
	if (bad_end == 1)
	{
		bad_end = 0;
		true_end = 0;
		return;
	}
	else if (true_end == 1)
	{
		cout << moves << "\n";
		exit(0);
	}
	else
	{
		bad_end = 0;
		true_end = 0;
	}
}