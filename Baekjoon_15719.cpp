#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int n, num, sum = 0, sum_2 = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		sum += num;
		sum_2 += i;
	}
    printf("%d", sum - sum_2);
}
