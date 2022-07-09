#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   int num, sum = 0;
   vector<int>mode(101);
   for (int i = 0; i < 10; i++) {
      scanf("%d", &num);
      sum += num;
      mode[num / 10]++;
   }

   int max = max_element(mode.begin(), mode.end()) - mode.begin();
   printf("%d\n%d\n", sum / 10, max * 10);
   return 0;
}
