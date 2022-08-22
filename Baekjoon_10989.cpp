#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int arr[10000] = { 0 };
    while (n--) {
        int a;
        cin >> a;
        arr[a - 1]++;
    }

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}
