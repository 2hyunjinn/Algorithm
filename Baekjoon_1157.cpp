#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int alpha[26] = { 0, };
    for (int i = 0; i < s.length(); i++) {
        alpha[toupper(s[i]) - 'A']++;
    }

    int max = *max_element(alpha, alpha + 26);
    int idx = max_element(alpha, alpha + 26) - alpha;
    int cnt = -1;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == max) {
            cnt++;
        }
    }

    if (cnt) cout << '?' << '\n';
    else cout << char('A' + idx) << '\n';
    return 0;
}
