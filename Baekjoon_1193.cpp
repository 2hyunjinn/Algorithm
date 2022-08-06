#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

   int i = 1;
   while (n > i) {
      n -= i;
      i++;
   }

   if (i % 2)
      cout << i + 1 - n << '/' << n << endl;
   else
      cout << n << '/' << i + 1 - n << endl;

    return 0;
}
