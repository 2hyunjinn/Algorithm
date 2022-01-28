#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n, m; // 배열의 크기
	scanf("%d%d", &n, &m);

	/* 배열 입력 */
	int arr[300][300] = { 0 };
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			scanf("%d", &arr[a][b]);
		}
	}

	int k; // 몇 개의 구간 탐색할 것인지 입력
	scanf("%d", &k);
	
	
	int sum[10000] = { 0 };
	for (int a = 0; a < k; a++) {
		/* (i,j) ~ (x,y) 구간 탐색 */
		int i, j, x, y; 
    scanf("%d%d%d%d", &i, &j, &x, &y);
    for (int row = i - 1; row < x; row++) { // row
	        for (int col = j - 1; col < y; col++) // col
		sum[a] += arr[row][col]; // 구간 사이의 합 누적
    }	
	}

	for (int a = 0; a < k; a++) {
		printf("%d\n", sum[a]);
	}
}
