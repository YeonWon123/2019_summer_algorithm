#include <iostream>
using namespace std;

int arr[1000] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int end = 0;
	int testcase = T;

	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ax, ay, az; // 백의 자리, 십의 자리, 일의 자리
		ax = a / 100;
		ay = (a - a / 100 * 100) / 10;
		az = a % 10;

		// 1. 0s 0b
		if (b == 0 && c == 0) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;
				if (ix != ax && iy != ax && iz != ax &&
					ix != ay && iy != ay && iz != ay &&
					ix != az && iy != az && iz != az) {
					arr[i]++;
					continue;
				}
			}
		}
		// 2. 0s 1b
		else if (b == 0 && c == 1) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;
				if ((ix != ax && (iy == ax || iz == ax)) &&
					(ix != ay && iy != ay && iz != ay) &&
					(ix != az && iy != az && iz != az)) {
					arr[i]++;
					continue;
				}

				if ((ix != ax && iy != ax && iz != ax) &&
					(iy != ay && (ix == ay || iz == ay)) &&
					(ix != az && iy != az && iz != az)) {
					arr[i]++;
					continue;
				}

				if ((ix != ax && iy != ax && iz != ax) &&
					(ix != ay && iy != ay && iz != ay) &&
					((ix == az || iy == az) && iz != az)) {
					arr[i]++;
					continue;
				}
			}
		}
		// 3. 0s 2b
		else if (b == 0 && c == 2) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;
				if ((ix != ax && (iy == ax || iz == ax)) &&
					((ix == ay || iz == ay) && iy != ay) &&
					(ix != az && iy != az && iz != az)) {
					arr[i]++;
					continue;
				}

				if ((ix != ax && (iy == ax || iz == ax)) &&
					(ix != ay && iz != ay && iy != ay) &&
					((ix == az || iy == az) && iz != az)) {
					arr[i]++;
					continue;
				}

				if ((ix != ax && iy != ax && iz != ax) &&
					((ix == ay || iz == ay) && iy != ay) &&
					((ix == az || iy == az) && iz != az)) {
					arr[i]++;
					continue;
				}
			}

		}
		// 4. 0s 3b
		else if (b == 0 && c == 3) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;

				if ((ix != ax && (iy == ax || iz == ax)) &&
					((ix == ay || iz == ay) && iy != ay) &&
					((ix == az || iy == az) && iz != az)) {
					arr[i]++;
					continue;
				}
			}
		}
		// 5. 1s 0b
		else if (b == 1 && c == 0) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;

				if ((ix == ax && iy != ax && iz != ax) ||
					(ix != ay && iy == ay && iz != ay) ||
					(ix != az && iy != az && iz == az)) {
					arr[i]++;
					continue;
				}
			}
		}
		// 6. 1s 1b
		else if (b == 1 && c == 1) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;

				if (ix == ax) {
					if (iy == az && iz != ay) {
						arr[i]++;
						continue;
					}

					if (iy != az && iz == ay) {
						arr[i]++;
						continue;
					}
				}

				if (iy == ay) {
					if (ix == az && iz != ax) {
						arr[i]++;
						continue;
					}

					if (ix != az && iz == ax) {
						arr[i]++;
						continue;
					}
				}

				if (iz == az) {
					if (ix == ay && iy != ax) {
						arr[i]++;
						continue;
					}

					if (ix != ay && iy == ax) {
						arr[i]++;
						continue;
					}
				}
			}
		}
		// 7. 1s 2b
		else if (b == 1 && c == 2) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;

				if (ix == ax) {
					if (iy == az && iz == ay) {
						arr[i]++;
						continue;
					}
				}

				if (iy == ay) {
					if (ix == az && iz == ax) {
						arr[i]++;
						continue;
					}
				}

				if (iz == az) {
					if (ix == ay && iy == ax) {
						arr[i]++;
						continue;
					}
				}
			}
		}
		// 8. 2s 0b
		else if (b == 2 && c == 0) {
			for (int i = 123; i <= 987; i++) {
				int ix, iy, iz; // 백의 자리, 십의 자리, 일의 자리
				ix = i / 100;
				iy = (i - i / 100 * 100) / 10;
				iz = i % 10;

				if (ix == 0 || iy == 0 || iz == 0) continue;

				if (ix == iy || ix == iz || iy == iz) continue;

				if (ix == ax && iy == ay && iz != az) {
					arr[i]++;
					continue;
				}

				if (ix == ax && iy != ay && iz == az) {
					arr[i]++;
					continue;
				}

				if (ix != ax && iy == ay && iz == az) {
					arr[i]++;
					continue;
				}
			}
		}
		// 9. 3s 0b
		else if (b == 3) {
			end = 1;
		}
	}

	if (end == 1) {
		cout << 1;
		return 0;
	}

	int answer = 0;
	for (int i = 123; i <= 987; i++) {
		if (testcase == arr[i]) {
		//	cout << i << endl;
			answer++;
		}
	}

	cout << answer;
}