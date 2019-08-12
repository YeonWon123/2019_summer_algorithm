#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int T;
int  H, W, N;
bool hotel[100][100];


int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> T;

	while (T--) {

		
		memset(hotel, false, sizeof(hotel));

		cin >> H >> W >> N;  // H가 층수 W가 한층당 방의 개수


		 int high = (N % H);  int	wide = N / H;  // hihg 가   층수  , wide+1이 방번호 수  

		 if (high == 0)
		 {
			 high = H;
			 wide--;
		 }
		 
		
		 if (wide < 9)  
		 {
			
			 cout << high << "0" << wide + 1 << "\n";
		 }
		 else
		 {
			 cout << high << wide + 1 << "\n";
		 }

	}

	//system("pause");
	return 0;
}