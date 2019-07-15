#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool arr[1000];
string num, one, two;
int n,input, strike, ball;

int strike_cnt, ball_cnt = 0;

int answer = 0;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(arr, true, sizeof(arr)); // 초기화를 시켜주자 
	
	for (int i = 123; i < 1000; i++) { // 같은 숫자가 있거나 0이 있거나 하면 false;

		num = to_string(i); // i를 string 으로 변환

		if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) {

			arr[i] = false;
		}

		if (num[0] - '0' == 0 || num[1] - '0' == 0 || num[2] - '0' == 0) {

			arr[i] = false;
		}
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> input >> strike >> ball;

		for (int i = 123; i < 1000; i++) {

			strike_cnt = 0;
			ball_cnt = 0;

			{

				one = to_string(input);
				two = to_string(i);

				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {

						if (x == y && one[x] == two[y])
							strike_cnt++;
						if (x != y && one[x] == two[y])
							ball_cnt++;

						
					}
				}


				if (ball_cnt != ball || strike_cnt != strike)
					arr[i] = false;
			}
		}
	}


	for (int i = 123; i < 1000; i++) {

		if (arr[i])
			answer++;
	}

	cout << answer;

	//system("pause");
	return 0;
}

