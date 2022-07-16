#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1) {
		int a, b;
		cin >> a >> b;
		if (!(a && b)) break;
		cout << a + b << '\n';
	}
	return 0;
}
