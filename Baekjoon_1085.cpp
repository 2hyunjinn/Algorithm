#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min_w = min(x, w - x);
	int min_h = min(y, h - y);
	cout << min(min_w, min_h);

	return 0;
}
