#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double a, b;
	cin >> a >> b;

	cout.precision(10); // 소수점 10번째자리까지
	cout << a / b << endl;
	return 0;
}
