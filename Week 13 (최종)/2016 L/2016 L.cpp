#include <iostream>
#include <queue>
using namespace std;

queue<int> load;
int load_sum = 0;
long long times = 0;
int i_arr[1000000] = { 0, };
int i_start = 0;
int i_count = 0;
int sw = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, w, L;
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

THIS:
		// �� ���� ���ο� �ö�� ���
		if (load_sum + input <= L) {
			//if (sw == 0) {
				times++;
			//}
			//sw = 0;
			load.push(input);
			load_sum += input;

			// ���ο� ���� ��� �ִ���, ��� ������ ǥ��
			i_count++;
			for (int i = i_start; i < i_count; i++) {
				i_arr[i]++;

				// �� ������ ������
				if (i_arr[i] == w) {
					i_start++;
					int temp = load.front();
					load_sum -= temp;
					load.pop();
				}
			}
		}
		else {
			// �� �� ���� �� �������� times++�� �Ѵ�.
//			cout << "no! times ����" << w - i_arr[i_start] << endl;
			times += (long long)w - i_arr[i_start];
			i_start++;

			// �׷��� ������ ����;���
			for (int i = i_start; i < i_count; i++) {
				i_arr[i] += w - i_arr[i_start - 1];
			}

			// �� �� ���� ������..
			int temp = load.front();
			load_sum -= temp;
			load.pop();
			//times++;
			//sw = 1;
			// ���� ���� �����ϴٸ� �� ���� ���ο� �ø���.
			// ���� �Ұ����ϴٸ� else�������� �ٽ� �����Ѵ�.
			goto THIS;
		}

//		for (int i = i_start; i < i_count; i++) {
//			cout << "i_start : " << i_start << ", i_count : " <<
//				i_count << ", i_arr[ " << i << "] : " << i_arr[i] << endl;
//		}

//		cout << i << " " << times << endl;
	}
	times += w;
	cout << times;
	return 0;
}