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
		// 새 차가 도로에 올라온 경우
		if (load_sum + input <= L) {
			//if (sw == 0) {
				times++;
			//}
			//sw = 0;
			load.push(input);
			load_sum += input;

			// 도로에 차가 몇대 있는지, 어디 가는지 표시
			i_count++;
			for (int i = i_start; i < i_count; i++) {
				i_arr[i]++;

				// 다 갔으면 빼주자
				if (i_arr[i] == w) {
					i_start++;
					int temp = load.front();
					load_sum -= temp;
					load.pop();
				}
			}
		}
		else {
			// 맨 앞 차가 다 갈때까지 times++를 한다.
//			cout << "no! times 증가" << w - i_arr[i_start] << endl;
			times += (long long)w - i_arr[i_start];
			i_start++;

			// 그러면 뒷차도 따라와야지
			for (int i = i_start; i < i_count; i++) {
				i_arr[i] += w - i_arr[i_start - 1];
			}

			// 맨 앞 차를 보낸다..
			int temp = load.front();
			load_sum -= temp;
			load.pop();
			//times++;
			//sw = 1;
			// 만약 이후 가능하다면 새 차를 도로에 올린다.
			// 만약 불가능하다면 else문구부터 다시 시행한다.
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