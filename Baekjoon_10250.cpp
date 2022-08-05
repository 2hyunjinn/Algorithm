#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int t, h, w, n;
    cin >> t;
    while (t--) {
        cin >> h >> w >> n;
        int y = n % h;
        int x = n / h;

        if (y) x++;
        else y = h;
        cout << y * 100 + x << endl;
    }

    return 0;
}
