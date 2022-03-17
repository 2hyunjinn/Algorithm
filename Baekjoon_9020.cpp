#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;
int n, m;
bool visited[10001]= {1, 1};

 // m보다 작은 소수 찾기
void primeN(int input) {
	for (int i = 2; i <= sqrt(input); i++) {
		if (visited[i]) continue; // 이미 방문했다면
		for (int j = i + i; j <= input; j += i) {
			if (visited[j]) continue;
			visited[j] = true;
		}
	}
}

// 소수끼리 더해보기
void check(int input) {
	for (int i = input/2; i >= 2; i--) {
		if (!visited[i]) { // 소수라면
			if (!visited[input - i]) { // input - i 도 소수라면
				printf("%d %d\n", i, input - i);
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		primeN(m); // m보다 작은 소수 찾기
		check(m); // 소수끼리 더해보기
	}
	return 0;
}
