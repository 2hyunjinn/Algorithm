#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.push_back({ y,x });
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ' << v[i].first << '\n';
    }
    return 0;
}
