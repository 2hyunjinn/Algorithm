#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (word == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (word == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (word == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (word == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (word == "size") {
			cout << dq.size() << '\n';
		}
		else if (word == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (word == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (word == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
	return 0;
}
