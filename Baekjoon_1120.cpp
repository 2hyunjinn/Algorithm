#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
const int INF = 987654321;

int main() {
	char A[51], B[51];
	scanf("%s%s", A, B);

	int cnt = 0, before = INF;
	for (int i = 0; i < strlen(B) - strlen(A) + 1; i++) {
		cnt = 0;
		for (int j = 0; j < strlen(A); j++) {
			if (A[j] != B[j + i]) cnt++;
		}
		before = (before < cnt) ? before : cnt;
	}
	printf("%d\n", before);
	return 0;
}
