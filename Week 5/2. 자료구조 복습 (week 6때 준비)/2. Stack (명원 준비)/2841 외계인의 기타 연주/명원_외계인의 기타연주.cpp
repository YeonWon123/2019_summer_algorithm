// 문제 주의 할 점    ** 외계인은 손가락이 무한개이다.  따라서 다른 줄을 칠때 다른 손가락을 사용하면 된다.  

//7 15 
//1 5 = > 1회 
//2 3 = > 1회 
//2 5 = > 1회 
//2 7 = > 1회 
//2 4 = > 3회 = > 3번, 5번 플렛 떼고 4번 플렛 누름 
//1 5 = > 1회 = > 눌려있음. 
//1 3 = > 2회 = > 5번 플렛 떼고 3번 플렛 누름


// 알고리즘     ******  1.  줄을 인덱스로하는 기타 스택을 만든다
                    //  2.  같은 줄에서 스택으로 플랫을 오름차순으로 쌓는다.  
                     //   같은 줄에서 스택이 높은 게 낳올 경우 쌓아주고  낮은게 나올경우 pop해준다
                      // 같은 게 있을 경우는 무시해도 좋다. 



#include<iostream>
#include<stack>

using namespace std;

int N, P;
stack<int>s[7]; // 줄 1-6
int result = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P;

	for (int i = 0; i < N; i++) {


		pair<int, int> T;  // 줄 , 플랫번호
		cin >> T.first >> T.second;

		if (s[T.first].empty())
		{
			result++;	 s[T.first].push(T.second);
		}

		else
		{
			if (T.second > s[T.first].top())  // 만일 플랫이 더 크다면
			{
				s[T.first].push(T.second);
				result++;  // 손가락 한번 움직인다.
			}

			else if (T.second == s[T.first].top()) // 이미 있으면 추가할 필요 없다
				continue;

			else  // 만일 플랫이 작다면 
			{
				while (!s[T.first].empty() && T.second < s[T.first].top())
				{
					s[T.first].pop();  // 낮은 플랫이 오면 높은 플랫들을 떼어준다.
					result++; //   떼어줄 때 손가락이 움직이므로 ++
				}


				if (!s[T.first].empty() && T.second == s[T.first].top())  // 만일 같은 플랫이 있으면 
					continue;



				s[T.first].push(T.second);
				result++;
			}

		}
	}

	cout << result;



	system("pause");
	return 0;
}