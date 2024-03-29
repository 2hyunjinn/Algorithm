#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int fibo(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
