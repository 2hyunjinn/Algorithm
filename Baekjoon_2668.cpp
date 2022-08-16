#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt;
int node[101];
bool visited[101];
bool cycle[101];

bool DFS(int startNum, int nodeNum)
{
	if (visited[nodeNum]) return false;

	visited[nodeNum] = true;

	//사이클을 이루면
	if (startNum == nodeNum || DFS(startNum, node[nodeNum]))
	{
		cnt++;
		cycle[nodeNum] = true;
		return true;
	}
	return false;
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> node[i];
	}

	for (int i = 1; i <= n; i++){
		DFS(i, node[i]);

		//이미 사이클을 이루는 집합은 재방문 X
		for (int j = 1; j <= n; j++) {
			visited[j] = cycle[j]; 
		}
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		//사이클 이루는 노드들 출력
		if (cycle[i]) cout << i << endl;
	}

	return 0;
}
