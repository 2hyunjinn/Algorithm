#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void) {
   int in, out, amount = 0 , max = 0;
   for (int i = 0; i < 10; i++) {
      scanf("%d%d", &out, &in);
      amount = amount - out + in;
      if (amount > max) max = amount;
   }
   printf("%d\n", max);
   return 0;
}
