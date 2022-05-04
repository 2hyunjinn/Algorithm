#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
int arr[32001];
int n, m;

void Topology_sort(void) {
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!arr[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            arr[graph[cur][i]]--;
            if (!arr[graph[cur][i]])
                q.push(graph[cur][i]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        arr[b]++;
    }
    Topology_sort();

    return 0;
}
