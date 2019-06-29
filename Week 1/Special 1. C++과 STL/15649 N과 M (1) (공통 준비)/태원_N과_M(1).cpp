#include <iostream>
#include <vector>
using namespace std;
#define maxValue 8 // 최대 8개의 배열 index 선언
int n, m; // n : 1~n까지 자연수 , m : 수열의 개수
bool Select[maxValue];
vector<int> v; // 순서를 고려해야 되서 만들었음

void Print() // 벡터에 저장된 값들을 출력한다.
{
	for (int i = 0; i < v.size(); i++) { // 벡터의 사이즈 만큼 루프를 돌린다.
		cout << v[i] << " ";
	}
		cout << "\n";

}

void Search(int Cnt) // 수열을 고른다.
// Cnt : 카운트 된 개수
{
	if (Cnt == m) // m개의 개수가 다 구해졌으면 
	{
		Print(); // 출력
		return;
	}

	for (int i = 0; i < n; i++) // i는 넣을지 말지 결정할 index
	{
		if (Select[i] == true) continue; // select[i]가  이미 선택되었다면 다음 루프로
		Select[i] = true; // 정해지지 않았다면 현재 index를 선택
		v.push_back(i + 1); // 순서도 고려해야하기 때문에 결정된 순서대로 벡터에 넣어준다.
		Search(Cnt + 1); // 카운트가 되었으니 카운터를 +1해주고 재귀적으로 새로운 값을 찾는다.
		v.pop_back(); // 출력이 되었으면 가장 나중에 넣은 값을 벡터에서 빼준다.
		Select[i] = false; // 제거된 값의 index를 false로
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;


	Search(0); 

	return 0;
}

// 참고 https://yabmoons.tistory.com/99