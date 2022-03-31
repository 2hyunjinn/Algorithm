#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 987654321;
int dist[501];

int tc; // 테스트 케이스의 개수
int n; // 지점의 개수
int m; // 도로의 개수
int w; // 웜홀의 개수

struct edge {
    int s, e, t;
};

bool Bellman(int n, vector<edge> edges) {
    fill(dist+1, dist+501, INF);

    int s, e, t;
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edges.size(); j++) {
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        s = edges[i].s;
        e = edges[i].e;
        t = edges[i].t;
        if (dist[e] > dist[s] + t) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &tc);
    
    int a, b, c;
    while (tc > 0) {
        scanf("%d%d%d", &n, &m, &w);
        vector<edge> edges;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({ a, b, c });
            edges.push_back({ b, a, c });
        }

        for (int i = 0; i < w; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({ a, b, -c });
        }

        if (Bellman(n, edges)) printf("YES\n");
        else printf("NO\n");
        tc--;
    }
    return 0;
}
