#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < i; j++) // 투명 직각 삼각형 출력
			printf(" ");
		for (j = 0; j < (2 * n - 1) - (i * 2); j++) // 별 직각 역삼각형 출력
			printf("*");
		printf("\n");
	}

	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) // 투명 직각 역삼각형 출력
			printf(" ");
		for (j = 0; j < i * 2 + 1; j++) // 별 직각 삼각형 출력
			printf("*");
		printf("\n");
	}
	
	return 0;
}
