#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; 

vector<pair<int, int>>room;



bool cmp(pair<int,int>one, pair<int,int>two) {

	if (one.second == two.second)   // ���� �ð��� ���ٸ�  ���۽ð��� ���� ��
		return  one.first < two.first;

	else   // ����ð��� ���� ��
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

	int cnt = 0;   int n = 0;  // cnt�� ���� �� �ִ� ���   n �� ����ð� ����

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