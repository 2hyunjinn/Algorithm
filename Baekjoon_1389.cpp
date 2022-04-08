#include <iostream>
#include <algorithm>
using namespace std;

int INF = 987654321;
int N, M;
int graph[101][101];

// floyd
void floyd(void) {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i == j)
                    continue;
                else if (graph[i][k] && graph[k][j]) {
                    if (graph[i][j] == 0) graph[i][j] = graph[i][k] + graph[k][j];

                    //베이컨의 수가 적어야하므로
                    else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
}

int main(void) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        graph[node1][node2] = graph[node2][node1] = 1;
    }
    floyd();

    int result = INF;
    int person;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += graph[i][j];

        if (result > sum) //최소 베이컨 수일 때
        {
            result = sum;
            person = i; //해당 사람을 저장
        }
    }
    printf("%d\n", person);
    return 0;
}
