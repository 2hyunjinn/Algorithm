#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	bool primeNumber[1000001] = { 1,1 };
	for (int i = 2; i*i <= n; i++) {
		if (primeNumber[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			if (primeNumber[j]) continue;
			primeNumber[j] = true;
		}
	}

	for (int i = m; i <= n; i++) {
		if (!primeNumber[i]) cout << i << '\n';
	}
	return 0;
}
