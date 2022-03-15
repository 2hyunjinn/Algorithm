#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int n, x, y, m;
vector<int> adj[10001];
bool visited[10001] = { 0 };
int cnt = 0;

void dfs(int now) {
	visited[now] = 1; // 해당 노드는 방문함
	cnt++;

	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!visited[next]) {
			dfs(next); // 방문 안했다면
		}
		if (now == y) {
			printf("%d\n", cnt - 1);
			break;
		}
	}
	cnt--;
}

void input() {
	scanf("%d", &n); // 사람의 수
	scanf("%d%d", &x, &y); // 두 사람
	scanf("%d", &m); // 관계의 개수
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main(){
	input();
	dfs(x);
	if (!(visited[x] && visited[y])) printf("-1\n");
	return 0;
}
