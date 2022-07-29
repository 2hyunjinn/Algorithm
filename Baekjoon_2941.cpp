#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    string s;
    cin >> s;

    for (int i = 0; i < 8; i++) {
        while (1) {
            int idx = s.find(croatia[i]);
            if (idx == string::npos) break;
            s.replace(idx, croatia[i].length(), "#");
        }
    }
    cout << s.length() << '\n';
    return 0;
}
