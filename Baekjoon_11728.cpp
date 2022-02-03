#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[2000000];

/* 배열 값 입력 */
void input_info() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n+m; i++)
		scanf("%d", &arr[i]);
}

int main() {
	input_info();
	sort(arr, arr + (n + m));
	for (int i = 0; i < n + m; i++)
		printf("%d ", arr[i]);
	return 0;
}
