#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int n, c;
vector<int> adj[1001];
bool visited[1001];

void dfs(int now) {
	visited[now] = 1; // 해당 노드는 방문함
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!visited[next]) dfs(next); // 방문 안했다면
	}
}

void input() {
	int a, b;
	for (int i = 0; i < c; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main(){
	scanf("%d%d", &n, &c);
	input();

	int component = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) { // 방문 안했다면
			dfs(i);
			component++; // 연결요소 증가
		}
	}
	printf("%d\n", component);
	return 0;
}
