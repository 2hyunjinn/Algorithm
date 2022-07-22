#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int a, b, c;
   cin >> a >> b >> c;

   if ((a == b) && (b == c)) {
      cout << 10000 + a * 1000;
   }
   else if ((a == b) || (a == c)){
      cout << 1000 + a * 100;
   }
   else if (b == c) {
      cout << 1000 + b * 100;
   }
   else {
      cout << max(a, max(b, c)) * 100;
   }
   return 0;
}
