#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int h, w, x, y, input;
	cin >> h >> w >> x >> y;

	vector<vector<int>> b(h+x);
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> input;
			b[i].push_back(input);
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i >= x && j >= y) b[i][j] -= b[i - x][j - y];
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
