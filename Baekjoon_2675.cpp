#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	int n; string str;
	while (t--) {
		cin >> n >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < n; j++) cout << str[i];
		}
		cout << '\n';
	}
	return 0;
}
