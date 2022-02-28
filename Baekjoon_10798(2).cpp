#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string word[5];

void input() {
	for (int i = 0; i < 5; i++)
		getline(cin, word[i]);
}

void print_length() {
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 5; k++) {
			if (word[k].length() <= i) continue; // 문자열의 길이를 넘어서면 건너뛰기
			else if ((word[k][i] >= 'a' && word[k][i] <= 'z') 
				|| (word[k][i] >= 'A' && word[k][i] <= 'Z') 
				|| (word[k][i] >= '0' && word[k][i] <= '9'))
				printf("%c", word[k][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	print_length();
	return 0;
}
