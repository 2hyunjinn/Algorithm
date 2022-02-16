#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(void)
{
	int n, k, m; 
	scanf("%d%d%d", &n, &k, &m);

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int cnt = 0;
	while (dq.size() != 1) {
		if (cnt < m) {
			for (int i = 1; i < k; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			printf("%d\n", dq.front());
			dq.pop_front(); cnt++;
		}
		else {
			cnt = 0; reverse(dq.begin(), dq.end());
		}
	}
	printf("%d\n", dq.front());
	return 0;
}
