#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int make_gcd(int a, int b) {
	if (b == 0) return a;
	return make_gcd(b, a % b);
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int big, small;
	(a > b) ? (big = a, small = b) : (big = b, small = a);

	int gcd = make_gcd(big, small);
	printf("%d\n%d\n", gcd, gcd * (big / gcd) * (small / gcd));
	return 0;
}
