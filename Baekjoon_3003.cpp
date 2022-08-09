#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int chess[6] = { 1,1,2,2,2,8 };
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		cout << chess[i] - n << ' ';
	}
	return 0;
}
