#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	bool flag = false;
	while (q.size()!=1) {
		if (flag == false) {
			flag = true;
			q.pop();
		}
		else {
			flag = false;
			q.push(q.front());
			q.pop();
		}
	}
	printf("%d\n", q.front());
	return 0;
}
