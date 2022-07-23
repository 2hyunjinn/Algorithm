#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);

   int alpha[26] = { 0, };

   string word;
   cin >> word;

   for (int i = 0; i < word.length(); i++) {
      int idx = word[i] - 'a';
      if(!alpha[idx]) alpha[idx] = i + 1;
   }

   for (int i = 0; i < 26; i++) {
      if (alpha[i]) cout << alpha[i] - 1 << ' ';
      else cout << -1 << ' ';
   }
   return 0;
}
