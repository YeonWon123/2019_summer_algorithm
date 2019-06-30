#include<iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int initNum, num, count = 0;
	int tens, units;

	cin >> initNum;
    
	tens = initNum / 10;
	units = initNum % 10;

	do {

		num = units * 10 + (tens + units) % 10;
		tens = num / 10;
		units = num % 10;

		count++;

	} while (initNum != num);

	cout << count << "\n";
	
	//system("pause");

	return 0;
}