#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int queue[10000];
int idx = -1; // idx는 0부터 시작하니까 -1로 설정
int first = 0; // front용

// true가 현재 하나라도 있는 상태, false가 공백
typedef enum {false, true} bool;
bool emp = false;  // 초기상태는 공백으로 처리

void push(int x) {
	idx++; // -1로 설정해서 ++하고 시작
	queue[idx] = x;
	emp = true; // 뭐있다고 바꾸기
}

void pop() {
	if (emp == false)
		printf("-1\n");
	else {
		printf("%d\n", queue[first]);
		if (idx == first)
			emp = false;
		first++; // first ++
	}
}

void front() {
	if (emp == false) // 비어있다면
		printf("-1\n");
	else
		printf("%d\n", queue[first]);
}

void back() {
	if (emp == false) // 비어있다면
		printf("-1\n");
	else
		printf("%d\n", queue[idx]);
}

void size() {
	printf("%d\n", idx + 1 - first);
}

void empty() {
	if (emp == true)
		printf("0\n");
	else
		printf("1\n");
}

int main(void) {
	int n, x;
	scanf("%d", &n);

	char input[6];
	for (int i = 0; i < n; i++) {
		scanf("%s",input);
		if (!strcmp(input, "push")) {
			scanf("%d", &x);
			push(x);
		}
		else if (!strcmp(input, "pop")) {
			pop();
		}
		else if (!strcmp(input, "size"))
			size();
		else if (!strcmp(input, "empty")) {
			empty();
		}
		else if (!strcmp(input, "front")) {
			front();
		}
		else if (!strcmp(input, "back")) {
			back();
		}
	}
	return 0;
}
