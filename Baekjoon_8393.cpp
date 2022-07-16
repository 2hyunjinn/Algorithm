#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int sum = 0;
	while (n) {
		sum += n;
		n--;
	}
	cout << sum;
	return 0;
}
