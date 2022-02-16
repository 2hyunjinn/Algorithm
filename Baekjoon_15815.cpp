#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 후위수식
int main(void)
{
	stack<int> stack;
	string word;
	getline(cin, word);

	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= '0' && word[i] <= '9')
			stack.push(word[i] - '0');
		else {
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (word[i] == '*') {
				stack.push(b * a);
			}
			else if (word[i] == '+') {
				stack.push(b + a);
			}
			else if (word[i] == '-') {
				stack.push(b - a);
			}
			else if (word[i] == '/') {
				stack.push(b / a);
			}
		}
	}
	cout << stack.top();
	return 0;
}
