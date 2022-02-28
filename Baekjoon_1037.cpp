#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, min_v, max_v;
int divisor[1000000];

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &divisor[i]);
	}
}

int get_multi() {
	min_v = *max_element(divisor, divisor + n); // 최솟값
	max_v = *min_element(divisor, divisor + n); // 최댓값
	return (min_v * max_v);
}

int main(){
	input();
	printf("%d\n", get_multi());
	return 0;
}
