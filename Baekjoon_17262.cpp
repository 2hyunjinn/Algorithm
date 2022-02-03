#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int first[100000], second[100000];
/* 팬의 수, 학교에 있는 시간 입력 */
void input_info() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &first[i], &second[i]);
	}
}
/* 시간 정렬 */
void sort_arr() {
	sort(first, first + n); // 최소 이때부터는 있어야 함
	sort(second, second + n); // 최대 이때까지는 있어야 함
}
/* 최소 시간 구하기 */
int get_mintime() {
	sort_arr();
	if ((first[n - 1] - second[0]) < 0) return 0;
	else return (first[n - 1] - second[0]);
}
int main() {
	input_info();
	printf("%d\n", get_mintime());
	return 0;
}
