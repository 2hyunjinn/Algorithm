#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[42] = { 0, }, cnt = 0;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		if (!arr[n % 42]) {
			cnt++;
			arr[n % 42] = 1;
		}
	}
	cout << cnt;
	return 0;
}
