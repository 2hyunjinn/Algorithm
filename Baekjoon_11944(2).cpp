#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string n;
	int m;
	cin >> n >> m;
	
	if (stoi(n) * n.length() <= m) {
		for (int i = 0; i < stoi(n); i++) {
			cout << n;
		}
	}
	else {
		for (int i = 0; i < m / n.length(); i++) cout << n;
		for (int i = 0; i < m % n.length(); i++) cout << n[i];
	}
	
	return 0;
}
