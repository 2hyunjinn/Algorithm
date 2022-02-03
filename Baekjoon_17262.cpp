#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int n, max_v, min_v;
int first[100000], second[100000];
/* 팬의 수, 학교에 있는 시간 입력 */
void input_info() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &first[i], &second[i]);
	}
}
/* 시작, 끝 시간 구하기 */
void get_time() {
	min_v = *max_element(first, first + n); // 최소 이때부터는 있어야 함
	max_v = *min_element(second, second + n); // 최대 이때까지는 있어야 함
}
/* 최소 시간 구하기 */
int get_mintime() {
	get_time();
	if (min_v - max_v <= 0) return 0;
	else return (min_v - max_v);
}
int main() {
	input_info();
	printf("%d\n", get_mintime());
	return 0;
}
