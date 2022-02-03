#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 단어의 개수
vector<string> word;

/* 정렬 */
bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b; // 길이가 같으면 사전순
	else return a.length() < b.length(); // 길이가 다르면 짧은 것부터
}

/* 단어 입력 */
void input_info() {
	scanf("%d", &n); // 단어 개수 입력
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		/* 해당 문자가 없으면 */
		if (find(word.begin(), word.end(), input) == word.end())
			word.push_back(input);
	}
}

/* 단어 출력 */
void print_word() {
	for (int i = 0; i < word.size(); i++)
		cout << word[i] << "\n";
}

int main() {
	input_info();
	sort(word.begin(), word.end(), compare); // 정렬
	print_word();
	return 0;
}
