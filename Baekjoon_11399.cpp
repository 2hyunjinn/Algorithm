#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
    
	int arr[1000];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n); // 순서대로 정렬
    
	int sum = arr[0], before = 0;
	for (int i = 1; i < n; i++) {
		before += arr[i-1]; // 내 전까지의 합
		sum += (before+ arr[i]); // 나를 포함한 합
	}
	printf("%d\n", sum);
}
