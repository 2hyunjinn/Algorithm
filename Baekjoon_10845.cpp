#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	queue<int> queue;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (word == "push") {
			int x;
			cin >> x;
			queue.push(x);
		}
		else if (word == "pop") {
			if (queue.empty()) cout << -1 << '\n';
			else {
				cout << queue.front() << '\n';
				queue.pop();
			}
		}
		else if (word == "size") {
			cout << queue.size() << '\n';
		}
		else if (word == "empty") {
			cout << queue.empty() << '\n';
		}
		else if (word == "front") {
			if (queue.empty()) cout << -1 << '\n';
			else cout << queue.front() << '\n';
		}
		else if (word == "back") {
			if (queue.empty()) cout << -1 << '\n';
			else cout << queue.back() << '\n';
		}
	}
	return 0;
}
