#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int sum = 1; // 0은 곱하면 0이 되므로 반드시 1로 초기화해야 함
	for (int i = n; i > 1; i--)
		sum *= i;
	printf("%d\n", sum);
	return 0;
}
