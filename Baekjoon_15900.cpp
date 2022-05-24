#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 500001
using namespace std;

vector <int> tree[MAX];
bool visited[MAX], is_leaf[MAX];
long long sum;

void dfs(int now, int dist) {
	if (tree[now].size() == 1 && now != 1) {
		if(dist % 2 == 1)
			sum++;
		return;
	}

	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, dist + 1);
			visited[next] = true;
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	visited[1] = true;
	dfs(1, 0);

	if (sum % 2 == 0)
		cout << "No";
	else
		cout << "Yes";
}
