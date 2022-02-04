#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	char n[100000001];
	fgets(n, 100000001, stdin);

	/* n이 한자리 수라면 */
	if (strlen(n) - 1 == 1) printf("%c\n", n[0]);
	else {
		/* n이 두자리 수라면 */
		if (strlen(n) - 1 == 2) printf("%d", (((n[0] - '0' - 1) * 10) + (n[1] - '0')) * 2 + 11);
		else { // n이 세자리 수 이상이면 
			int num = (n[0] - '0' - 1);
			int sum_2 = 9, idx = 1, x = 2, ten = 90;
			while (idx < strlen(n) - 1) {
				num = (num * 10) + (n[idx] - '0');

				/* x가 아직 n의 자리 수 보다 작다면 */
				if (x < strlen(n) - 1) sum_2 += ten * x;
				x++, ten *= 10, idx++;
			}
			printf("%d\n", (num + 1) * (strlen(n) - 1) + sum_2);
		}
	}
	return 0;
}
