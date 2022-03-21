#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[10001];

/* 인덱스는 0부터 시작하기 때문에 공백은 -1 */
int idx = -1;

/* top */
// idx가 -1이면 공백, 아니면 가장 최근에 넣은 값 반환
int top() {
	if (idx == -1)return -1;
	return stack[idx];
}

/* push */
// 인덱스 +1 한 후 stack 배열에 x 넣기
void push(int x) {
	idx++;
	stack[idx] = x;
}

/* pop */
// 배열이 공백 상태면 -1 반환, 아니면 인덱스 -1 한 후 값 반환
int pop() {
	if (idx == -1) return -1;
	idx--;
	return stack[idx + 1]; // idx-- 하기 전 값을 반환해야 하므로 idx+1
}

/* size */
// 인덱스는 0부터 시작하기 때문에 +1 한 값 반환
int size() {
	return (idx + 1);
}

/* empty */
// -1이면 공백, 아니면 0반환
int empty() {
	if (idx == -1) return 1;
	else return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char word[6];
		scanf("%s", word);
		if (strcmp(word, "push") == 0) {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(word, "pop") == 0)
			printf("%d\n", pop());

		else if (strcmp(word, "size") == 0)
			printf("%d\n", size());

		else if (strcmp(word, "empty") == 0)
			printf("%d\n", empty());

		else if (strcmp(word, "top") == 0)
			printf("%d\n", top());
	}
	return 0;
}
