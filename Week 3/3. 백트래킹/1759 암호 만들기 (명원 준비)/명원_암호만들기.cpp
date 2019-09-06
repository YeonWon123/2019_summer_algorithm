#include<iostream>

#include<algorithm>

using namespace std;

#include<string>




char alphbet[16];

int L, C;

void backtracking(int position, string str, int mo, int ja)

{
	
	if (str.size() == L)

	{

		if (mo >= 1 && ja >= 2)

			cout << str << endl;

		return;

	}

	for (int i = position; i <= C; i++)

	{

		if (alphbet[i] == 'a' || alphbet[i] == 'u' || alphbet[i] == 'i' ||

			alphbet[i] == 'o' || alphbet[i] == 'e')

			backtracking(i + 1, str + alphbet[i], mo + 1, ja);

		else

			backtracking(i + 1, str + alphbet[i], mo, ja + 1);

	}

}

int main()

{

	cin >> L >> C;

	for (int i = 1; i <= C; i++)

	{

		cin >> alphbet[i];

	}

	sort(alphbet, alphbet + C + 1);

	backtracking(1, "", 0, 0);

	//system("pause");
	return 0;

}
