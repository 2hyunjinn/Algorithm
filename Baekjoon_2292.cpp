#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int sum = 6, cnt = 1;
    for (int i = 1; i < n; sum += 6) {
        i += sum;
        cnt++;
    }
    cout << cnt;
    return 0;
}
