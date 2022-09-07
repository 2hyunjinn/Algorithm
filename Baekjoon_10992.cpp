#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << ' ';
        }

        int cnt = 1;
        for (int j = 1; j <= i * 2 - 1; j++) {
            if (j > 1 && j < i * 2 - 1 && i>1 && i < n) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
