#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int n, c;
int cnt;
vector<int> adj[101];
bool visited[101];

void dfs(int now) {
	visited[now] = 1; // 해당 노드는 방문함
	cnt++; // 방문한 노드 개수 추가
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
	dfs(1);
	printf("%d\n", cnt - 1); // 1번은 개수에서 제외
	return 0;
}
