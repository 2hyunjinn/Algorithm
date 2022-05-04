#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    int n, m, a, b;

    while (t--) {
        int past_idx2rank[501], past_rank2idx[501];
        bool adj[501][501];

        memset(adj, false, sizeof(adj));

        scanf("%d", &n);
        vector<int> indegree(n + 1, 0);

        int team_idx;
        for (int rank = 1; rank <= n; ++rank) {
            cin >> team_idx;
            past_idx2rank[team_idx] = rank;
            past_rank2idx[rank] = team_idx;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                adj[past_rank2idx[i]][past_rank2idx[j]] = true;
                indegree[past_rank2idx[j]]++;
            }
        }

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            if (past_idx2rank[a] < past_idx2rank[b]) {//저번엔 a가 더 높은 경우, 이번에는 b가 더 높은 순위임을 의미
                adj[b][a] = true;
                adj[a][b] = false;
                indegree[a]++;
                indegree[b]--;
            }
            else {
                adj[a][b] = true;
                adj[b][a] = false;
                indegree[b]++;
                indegree[a]--;
            }
        }

        queue<int> que;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) que.push(i);
        }

        vector<int> new_ranking;
        bool is_possible = true, is_single_answer = true;
        for (int i = 0; i < n; ++i) {
            if (que.empty()) {
                is_possible = false;
                break;
            }
            team_idx = que.front();
            que.pop();

            if (que.size() > 0) is_single_answer = false;
            else new_ranking.push_back(team_idx);

            for (int j = 1; j <= 500; ++j) {
                if (adj[team_idx][j])
                    if (--indegree[j] == 0) que.push(j);
            }
        }

        if (!is_possible) printf("IMPOSSIBLE\n");
        else if (!is_single_answer) printf("?\n");
        else {
            for (int i = 0; i < n; ++i)
                printf("%d ", new_ranking[i]);
            printf("\n");
        }
    }

    return 0;
}
