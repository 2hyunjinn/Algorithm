#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int W[10], K[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &W[i]);
    sort(W, W + 10);
    for (int i = 0; i < 10; i++)
        scanf("%d", &K[i]);
    sort(K, K + 10);
    int sum_w = 0, sum_k = 0;
    for (int i = 9; i > 6; i--) // 상위 3명의 점수
        sum_w += W[i], sum_k += K[i];
    printf("%d %d\n", sum_w, sum_k);
    return 0;
}
