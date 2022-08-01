#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if (c > b) cout << a / (c-b) + 1;
    else cout << -1;
    return 0;
}
