#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[50], B[50];

/* 내림차순 정렬 */
bool compare(int x, int y) {
	return (x > y);
}

/* 배열 입력 */
void input_info() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);
}

/* 배열 정렬 */
void sort_arr() {
	sort(A, A + n); // 오름차순
	sort(B, B + n, compare); // 내림차순
}

/* S의 최솟값 구하기 */
int get_S() {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (A[i] * B[i]);
	return sum;
}

int main() {
	input_info();
	sort_arr();
	printf("%d\n", get_S());
	return 0;
}
