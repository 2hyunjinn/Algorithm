#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> v;

/* 길이순, 사전순으로 출력 */
bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

/* 문자열 뒤집기 */
string reverse_arr(string input) {
	if (input.length() == 1) return input; // 일의 자리 수라면
	
	reverse(input.begin(), input.end()); // 뒤집기
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '0') return input.substr(i);
	}
}

/* 문자열 입력 */
void input_info() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		v.push_back(reverse_arr(input));
	}
}

void print_info() {
	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";
}

int main() {
	input_info();
	sort(v.begin(), v.end(), compare);
	print_info();

	return 0;
}
