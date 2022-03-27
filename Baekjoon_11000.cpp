#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> c_time; // 수업시간
priority_queue<int> pq;

int check() {
    pq.push(-c_time[0].second); // 종료시간

    for (int i = 1; i < n; ++i) {
        pq.push(-c_time[i].second);

        if (-pq.top() <= c_time[i].first) { 
            pq.pop();
        }
    }
    return pq.size();
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        c_time.push_back({ s, t });
    }
    sort(c_time.begin(), c_time.end());
}

int main() {
    input();
    printf("%d\n", check());
    return 0;
}
