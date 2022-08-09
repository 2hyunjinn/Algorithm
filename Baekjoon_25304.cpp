#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, n;
	cin >> x >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		x -= (a * b);
	}

	if (x) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}
