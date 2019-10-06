#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int w;
int E_F = 0;
int E_B = 0;
int V = 0;
string str;
stack<char> input;
int sw = 0;			// ó������ : 0, ���ĺ��� ������ 1, ���� ��ȣ�� ������ 2, �ݴ� ��ȣ�� ������ 3, ������ ������ 4, ��Ÿ ���� 5
int slb = 0;		// ó������ : 0, S : 1, l : 2, b : 3

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> w;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;

		// �� ó���� ������ ���(S, L, B)
		if (str[i] == 'S' || str[i] == 'L' || str[i] == 'B') {
			if (sw == 1) {
				sw = 5;
				break;
			}
			if (str[i] == 'S') {
				slb = 1;
				if (slb != 2) {
					E_F += 1;
				}
				V += 1;
			}
			else if (str[i] == 'L') {
				slb = 2;
				E_F += 2;
				E_B += 1;
				V += 2;
			}
			else /* if (str[i] == 'B') */ {
				slb = 3;
				E_F += 2;
				V += 2;
			}
			sw = 1;
		}
		// �� ó���� ��ȣ�� ���
		else if (str[i] == '(' || str[i] == '[') {
			input.push(str[i]);
			sw = 2;
		}
		// �� ó���� ��ȣ�� ���
		else if (str[i] == ')' || str[i] == ']') {
			if (sw == 4 || input.size() == 0) {
				sw = 5;
				break;
			}

			char a = input.top();
			if (str[i] == ')') {
				if (a == '(') {
					input.pop();
					sw = 3;
				}
				else {
					sw = 5;
					break;
				}
			}
			else if (str[i] == ']') {
				if (a == '[') {
					input.pop();
					sw = 3;
				}
				else {
					sw = 5;
					break;
				}
			}
		}
		else if (str[i] == ',') {
			if (sw == 0 || sw == 2) {
				sw = 5;
				break;
			}
			else {
				sw = 4;
			}
		}
		else {
			sw = 5;
			break;
		}
	}

	if (sw == 5) {
		cout << -1;
		return 0;
	}

	cout << E_F + w * E_B - V + 2;
	return 0;
}