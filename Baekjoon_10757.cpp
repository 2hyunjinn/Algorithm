#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) {
        string tmp = a;
        a = b;
        b = tmp;
    }

    int n1[100001] = { 0, }, n2[100001] = { 0, };
    for (int i = 0; i < a.length(); i++) {
        n1[i] = a[a.length() - 1 - i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        n2[i] = b[b.length() - 1 - i] - '0';
    }

    vector<int>sum;
    for (int i = 0; i < a.length(); i++) {
        if (n1[i] + n2[i] > 9) n1[i + 1]++;
        sum.push_back((n1[i] + n2[i]) % 10);
    }
    
    if(n1[a.length()]) cout << 1;
    for (int i = sum.size()-1; i >= 0; i--) {
        cout << sum[i];
    }
    return 0;
}
