#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


// ���� x�� y�� ����

double dot(double x1, double y1, double x2, double y2) {

	return x1 * x2 + y1 * y2;

}

//  ���� x�� y�� ����

double cross(double x1, double y1, double x2, double y2) {
	
	return x1 * y2 - x2 * y1;
}

// ���� 12�� �� 3���� ������ ���� ���� �� ������ ������ ���� �ƴϸ� -1

double perpendicular(double x1, double y1, double x2, double y2, double x3, double y3) {

	double dot1 = dot(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
	double dot2 = dot(x1 - x2, y1 - y2, x3 - x2, y3 - y2);

	// �� 3��  ���� 12�� ���� 2���� �̷�� ������ ���� �� ����

	if (dot1*dot2 >= 0)
		return abs(cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1)) / distance(x1, y1, x2, y2);

	return -1;

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	double yx[4000], yy[4000], result = -1;

	cin >> N >> M;

	//������ �����Է�

	for (int i = 0; i < N * 2; i++) {

		cin >> yx[i] >> yy[i];

	}


	//�Ⱦ��� �����Է�

	for (int i = 0; i < M; i++) {

		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x3 >> y3 >> x4 >> y4;

		//�Է¹��� ���� ������ ��� ���ε�� �Ÿ��� ���.

		for (int j = 0; j < N; j++) {

			//������ �ѵ��� 12, �Ⱦ��� �ѵ��� 34

			x1 = yx[j * 2]; x2 = yx[j * 2 + 1];
			y1 = yy[j * 2]; y2 = yy[j * 2 + 1];

			// ��� �� �� ������ �Ÿ���  �ĺ��� �� �� �ִ�.

			double dist = distance(x1, y1, x3, y3); double temp;

			dist = min(dist, distance(x1, y1, x4, y4));
			dist = min(dist, distance(x2, y2, x3, y3));
			dist = min(dist, distance(x2, y2, x4, y4));



			// ��� ������  �ٸ� ���п� ������ ���� �� ������  ������ ���̵� �ĺ�

			temp = perpendicular(x1, y1, x2, y2, x3, y3);

			if (temp >= 0) dist = min(dist, temp);

			temp = perpendicular(x1, y1, x2, y2, x4, y4);

			if (temp >= 0) dist = min(dist, temp);

			temp = perpendicular(x3, y3, x4, y4, x1, y1);

			if (temp >= 0) dist = min(dist, temp);

			temp = perpendicular(x3, y3, x4, y4, x2, y2);

			if (temp >= 0) dist = min(dist, temp);


			if (result < 0) result = dist;
			else result = min(result, dist);
		}
	}

	cout << fixed;

	cout.precision(16);

	cout << result;


	//system("pause");   // ���� ����Ʈ http://m.blog.naver.com/kks227/220614612111#
	return 0;
}