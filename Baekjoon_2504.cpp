#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// 괄호닫기
int main(void)
{
	char word[31];
	scanf("%s", word);

	stack<char> stack;
	int temp = 1, sum = 0;
	bool flag = false;

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == '(') {
			stack.push('(');
			temp *= 2;
		}
		else if (word[i] == '[') {
			stack.push('[');
			temp *= 3;
		}
		else if (word[i] == ')') {
			if (stack.empty() || stack.top() != '(') {
				flag = true; break;
			}

			if (word[i - 1] == '(') sum += temp;
			stack.pop();
			temp /= 2;
		}
		else if (word[i] == ']') {
			if (stack.empty() || stack.top() != '[') {
				flag = true; break;
			}
			if (word[i - 1] == '[') sum += temp;
			stack.pop();
			temp /= 3;
		}
	}
	if (flag || !stack.empty()) printf("0\n");
	else printf("%d\n", sum);
	return 0;
}
