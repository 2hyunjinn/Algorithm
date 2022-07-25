#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2 - 1; i++) {
        for (int j = 1; j <= n * 2; j++) {
            if (i <= n) {
                if (j <= i || j > n * 2 - i) printf("*");
                else printf(" ");
            } 
            else if (j <= n - (i % n) || j > i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
