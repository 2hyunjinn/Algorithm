#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string ac; 
		cin >> ac;
		
		int n; 
		cin >> n;

		string word; 
		cin >> word;

		deque<int> dq;

		string s;
		for (int i = 1; i < word.length(); i++) {
			if (word[i] >= '0' && word[i] <= '9')
				s += word[i];
			else if(word[i] ==',' || word[i] ==']') {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s.clear();
				}
			}
		}

		bool flag = true;
		bool rever = true;
		for (int i = 0; i < ac.length(); i++) {
			if (ac[i] == 'R') {
				rever = !rever;
			}
			else{
				if (dq.empty()) {
					flag = false;
					cout << "error\n";
					break;
				}
				else {
					if (rever) dq.pop_front();
					else dq.pop_back();
				}
			}
		}

		if (flag) {
			if (rever) {
				cout << "[";
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty()) cout << ",";
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty()) cout << ",";
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}
