#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	string y;
	cin >> x >> y;

	int result_3 = x * ((int)(y[2]) - '0');
	int result_4 = x * ((int)(y[1]) - '0');
	int result_5 = x * ((int)(y[0]) - '0');

	cout << result_3 << endl << result_4 << endl << result_5 << endl;
	cout << (result_3 + result_4 * 10 + result_5 * 100);
	return 0;
}
