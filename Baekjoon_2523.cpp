#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n * 2 - 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= n - abs(n - i))printf("*");
        }
        printf("\n");
    }
    return 0;
}
