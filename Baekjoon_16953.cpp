#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll A, B;
int min_v = 2147483647;
bool pos;

void dfs(ll a, int cnt) {
	if (a > B) return;
	if (a == B) { // 숫자가 같아질 때
		pos = true;
		min_v = min(min_v, cnt); // 가장 작은 수가 최솟값
	}
	dfs(a * 2, cnt+1); // 2배 했다면?
	dfs(a * 10 + 1, cnt+1); // 1을 추가했다면?
}

int main(void) {
	scanf("%lld%lld", &A, &B);
	dfs(A, 1);
	
	if (pos) printf("%d\n", min_v);
	else printf("-1\n");
	return 0;
}
