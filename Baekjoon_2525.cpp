#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int hour, min, time;
   cin >> hour >> min >> time;

   min += time;

   if (min >= 60) {
      hour += (min / 60);
      min %= 60;
   }

   if (hour >= 24) {
      hour %= 24;;
   }

   cout << hour << ' ' << min << endl;
   return 0;
}
