#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, a, b;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": ";
		cout << a << " + " << b << " = " << (a + b) << '\n';
	}
	return 0;
}
