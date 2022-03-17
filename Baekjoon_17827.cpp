#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int n, m, v;
int arr[200001];

void check(int c) {
	if (c < n) {
		printf("%d\n", arr[c]);
		return;
	}
	int x = c - v + 1;
	int y = n - v + 1;
	int idx = v + (x % y) - 1;
	printf("%d\n", arr[idx]);
	return;
}

void input() {
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

int main() {
	input();
	while (m--) {
		int c;
		scanf("%d", &c);
		check(c);
	}
	return 0;
}
