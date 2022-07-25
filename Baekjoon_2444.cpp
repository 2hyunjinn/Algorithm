#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2 - 1; i++) {
        for (int j = 1; j <= abs(n - i); j++) {
            printf(" ");
        }
        int x = (i <= n) ? (i * 2 - 1) : ((n - (i % n)) * 2 - 1);
        for (int j = 1; j <= x; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
