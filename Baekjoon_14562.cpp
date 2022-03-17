#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int c, s, t;
int min_v = 100;

void dfs(int a, int b, int cnt) {
	if (a > b) return; // 커지면 여기에는 답 없음
	if (a == b) { // 같으면 최솟값을 저장
		min_v = min(min_v, cnt);
		return;
	}
	dfs(a * 2, b + 3, cnt + 1); // 2배 했을 때
	dfs(a + 1, b, cnt + 1); // +1을 했을 때
}

int main() {
	scanf("%d", &c);
	while (c--) {
		scanf("%d%d", &s, &t);
		dfs(s, t, 0);
		printf("%d\n", min_v);
		min_v = 100; // 다시 
	}
	return 0;
}
