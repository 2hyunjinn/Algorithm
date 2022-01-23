#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n); // 숫자 N 입력
	int n_copy, cycle = 0;

	/* ten은 10의 자리 수로 26이면 2를 뜻함 */
	/* one은 1의 자리 수로 26이면 6을 뜻함 */
	int ten = n / 10, one = n % 10;

	/* n_copy가 n이 되면 원래 수로 돌아왔다는 뜻으로 탈출 */
	do {
		/* one = 주어진 수의 가장 오른쪽 자리 수 */
		/* ten + one = 각 자리의 숫자를 더한 값 */
		n_copy = one * 10 + (ten + one) % 10;

		/* 다음 사이클 수 만들기 */
		ten = n_copy / 10; 
		one = n_copy % 10;
		cycle++;
	} while (n_copy != n); 
	printf("%d\n", cycle);
	return 0;
}
