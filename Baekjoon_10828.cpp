#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

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
	return idx + 1;
}

/* empty */
// -1이면 공백, 아니면 0반환
int empty() {
	if (idx == -1) return 1;
	else return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (word == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (word == "pop")
			cout << pop() << "\n";

		else if (word == "size")
			cout << size() << "\n";

		else if (word == "empty")
			cout << empty() << "\n";

		else if (word == "top")
			cout << top() << "\n";
	}
	return 0;
}
