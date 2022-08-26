#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[50] = { 0,1 };

int Fibo(int x) {
    if (x == 0 || x == 1) {
        return dp[x];
    }
    if (dp[x] == 0) {
        dp[x] = Fibo(x - 1) + Fibo(x - 2);
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if (!x) cout << "1 0\n";
        else cout << Fibo(x-1) << ' ' << Fibo(x) << '\n';
    }
    return 0;
}
