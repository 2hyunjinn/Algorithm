#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int N, nodeIdx;
int node[10001];
int low[10001];
int high[10001];
pair<int, int> tree[10001];

void DFS(int nodeNum, int cnt) {

    if (tree[nodeNum].first > 0) DFS(tree[nodeNum].first, cnt + 1);

    low[cnt] = min(low[cnt], nodeIdx);
    high[cnt] = max(high[cnt], nodeIdx++);

    if (tree[nodeNum].second > 0) DFS(tree[nodeNum].second, cnt + 1);
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < 10001; i++) low[i] = INF;

    for (int i = 0; i < N; i++) {
        int parent, child1, child2;
        scanf("%d%d%d", &parent, &child1, &child2);

        node[parent]++;
        if (child1 != -1) node[child1]++;
        tree[parent].first = child1;

        if (child2 != -1) node[child2]++;
        tree[parent].second = child2;
    }

    int root;
    for (int i = 1; i <= N; i++) {
        if (node[i] == 1) root = i;
    }

    nodeIdx = 1;
    DFS(root, 1);

    int result = high[1] - low[1] + 1;
    int level = 1;

    for (int i = 2; i <= N; i++) {
        int temp = high[i] - low[i] + 1;

        if (temp > result) {
            result = temp;
            level = i;
        }
    }
    printf("%d %d\n", level, result);

    return 0;
}
