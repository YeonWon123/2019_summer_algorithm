#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; 

vector<pair<int, int>>room;



bool cmp(pair<int,int>one, pair<int,int>two) {

	if (one.second == two.second)   // 종료 시간이 같다면  시작시간이 빠른 순
		return  one.first < two.first;

	else   // 종료시간이 빠른 순
		return one.second < two.second;

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	cin >> N;

	int start, end;
	for (int i = 0; i < N; i++) {

		cin >> start >> end;

		room.push_back(make_pair(start, end));
	}

	sort(room.begin(), room.end(), cmp);

	int cnt = 0;   int n = 0;  // cnt는 빌릴 수 있는 방수   n 은 종료시간 저장

	for (int i = 0; i < room.size(); i++) {

		if (n <= room[i].first) {
			n = room[i].second;
			cnt++;

		}
	}


	cout << cnt;



	//system("puase");	
	return 0;
}