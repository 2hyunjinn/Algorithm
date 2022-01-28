#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int b, int s) {
	return ((b % s == 0) ? s : gcd(s, b % s));
}
int main() {
	int r, g;
	scanf("%d%d", &r, &g);
	int num = (r > g) ? gcd(r, g) : gcd(g, r);
	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			printf("%d %d %d\n",i, r / i, g / i);
	}
	return 0;
}
