#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int n; //스위치 개수 100 이하
int student; // 학생 수 100이하
int info[101][2]; // 학생의 성별, 지정숫자
int state[101] = { 0 }; // 스위치의 상태

/* 남학생 */
// 스위치번호가 자기가 받은 수의 배수이면 상태 바꿈
void male(int num, int i) {
	if (i * num > n) return;
	state[i * num] ^= 1;
	male(num, i + 1);
}

/* 여학생 */
// 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우대칭이면 가장 많이 바꿀 수 있게 바꿈
// 처음부터 좌우대칭이 아니라면 자기 것만 바꿈
void female(int current, int i) {
	if (state[current - i] == state[current + i]) {
		if ((current > 1 && current < n) && (current + i <= n && current - i > 0)) {
			state[current - i] = state[current + i] = state[current + i] ^ 1;
			female(current, i + 1);
		}
		else state[current] ^= 1;
	}
	else state[current] ^= 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &state[i]);

	scanf("%d", &student); // 학생 수 100이하

	// 학생의 성별, 지정숫자
	for (int i = 1; i <= student; i++)
		scanf("%d%d", &info[i][0], &info[i][1]);

	for (int i = 1; i <= student; i++) {
		/* 남자라면 */
		if (info[i][0] == 1) male(info[i][1], 1);
		/* 여자라면 */
		else female(info[i][1], 1);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", state[i]);
		if (i != 1 && i % 20 == 0) printf("\n");
	}
	return 0;
}
