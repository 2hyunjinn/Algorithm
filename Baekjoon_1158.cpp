#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n, k; 
	scanf("%d%d", &n,&k);

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	printf("<");
	while (q.size() != 1) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
	return 0;
}
