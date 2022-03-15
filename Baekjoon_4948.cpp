#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;
int n;
int prime[123456 * 2];

void make_arr(int input) {
	for (int i = 2; i <= input; i++)
		prime[i] = i;
}

void primeN(int input) {
	for (int i = 2; i <= sqrt(input); i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j <= input; j += i) {
			prime[j] = 0;
		}
	}
}


int count_P(int n) {
	int cnt = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (prime[i] != 0) {
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		make_arr(n * 2);
		primeN(n * 2);
		printf("%d\n", count_P(n));
	}

	return 0;
}
