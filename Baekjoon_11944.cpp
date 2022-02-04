#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	int m, idx = 0;
	cin >> n >> m;
	if ((stoi(n)*n.length()) > m) {
		for (int i = 0; i < m; i++) {
			if (idx == n.length()) idx = 0;
			printf("%c", n[idx]);
			idx++;
		}
	}
	else for (int i = 0; i < stoi(n); i++) cout << n;
	return 0;
}
