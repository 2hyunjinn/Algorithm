#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 9876543210;
bool flag;
int n, m;
int a, b, c;
long long dist[501];
vector<pair<int, int>> d[501];

void Bellman(int start) {
    // 아무것도 모르기 때문에 각 정점 사이의 거리는 일단 무한대로 초기화
    fill(dist, dist + 501, INF);

    // 시작점에서 시작점까지의 최단 거리는 0
    dist[start] = 0;

    // 총 n-1번 검사 + 마지막 한번은 음수 사이클 존재 여부 검사
    flag = false;
    for (int i = 1; i <= n; i++) {
        // 1번 점 ~ 끝 점
        for (int j = 1; j <= n; j++) {
            // 해당 정점에 연결된 모든 간선 살펴보고 업데이트
            for (int k = 0; k < d[j].size(); k++) {
                int next = d[j][k].first; // i점에서 연결된 정점
                int nextCost = d[j][k].second; // i->next 사이의 가중치

                // 만약 next의 dist가 
                // i까지의 dist + i -> next까지의 가중치합보다 크다면
                if (dist[j] != INF && dist[next] > dist[j] + nextCost) {
                    dist[next] = dist[j] + nextCost; // 후자로 교체

                    // 1 ~ n번째로 가려면 n-1개의 간선만 완화하면 됨
                    // 그런데 N번째에도 갱신이 된다면 음수 사이클 존재
                    if (i == n) flag = true;
                }
            }
        }
    }
}


void input() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        d[a].push_back({ b,c });
    }
}

int main() {
    input();
    Bellman(1);
    if (flag) printf("-1\n");
    else {
        for (int i = 2; i <= n; i++) printf("%lld\n", (dist[i] == INF ? -1 : dist[i]));
    }
    return 0;
}
