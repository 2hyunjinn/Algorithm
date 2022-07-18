#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int self_number(int n) {
	return (n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> v(10001);
	for (int i = 1; i < 10000; i++) {
		int idx = self_number(i);
		if(idx < 10000) v[idx] = 1;
	}

	for(int i = 1; i < 10000; i++) {
		if (!v[i]) cout << i << '\n';
	}

	return 0;
}
