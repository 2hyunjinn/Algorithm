#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    char arr[50][50] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int size = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k < m; k++) {
                if (i + k < n && j + k < m) {
                    if (arr[i][j] == arr[i][j + k]
                        && arr[i][j] == arr[i + k][j]
                        && arr[i][j] == arr[i + k][j + k]) {
                        size = max(k + 1, size);
                    }
                }
            }
        }
    }

    cout << size*size << endl;
    return 0;
}
