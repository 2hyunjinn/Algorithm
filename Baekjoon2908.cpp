#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void) {
   int A, B;
   scanf("%d%d", &A, &B);

   A = (A % 10 * 100) + (A % 100 / 10 * 10) + (A / 100);
   B = (B % 10 * 100) + (B % 100 / 10 * 10) + (B / 100);

   printf("%d\n", (A > B) ? A : B);
   return 0;
}
