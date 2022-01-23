#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int h, m;
	scanf("%d%d", &h, &m);

	if (m < 45) { // 45분보다 작다면
		if (h == 0) printf("23 %d\n", m + 15); // 시간이 24시 == 00시라면?
		else printf("%d %d\n", --h, m + 15);
	}
	else printf("%d %d\n", h, m - 45);

	return 0;
}
