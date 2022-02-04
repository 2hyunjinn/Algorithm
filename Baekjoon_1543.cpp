#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word, input;
	getline(cin, word);
	getline(cin, input);

	int cnt = 0;
	while (word.find(input) != -1) {
		if (word.find(input) + input.length() > word.length()) break;
		cnt++;
		word = word.substr(word.find(input) + input.length());
	}
	printf("%d\n", cnt);
	return 0;
}
