#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	stack<int> stack;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (word == "push") {
			int x;
			cin >> x;
			stack.push(x);
		}
		else if (word == "pop") {
			if (stack.empty()) cout << -1 << '\n';
			else {
				cout << stack.top() << '\n';
				stack.pop();
			}
		}
		else if (word == "size") {
			cout << stack.size() << '\n';
		}
		else if (word == "empty") {
			cout << stack.empty() << '\n';
		}
		else if (word == "top") {
			if (stack.empty()) cout << -1 << '\n';
			else cout << stack.top() << '\n';
		}
	}

	return 0;
}
